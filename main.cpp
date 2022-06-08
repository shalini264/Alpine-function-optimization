//Optimization of alpine function
#include <bits/stdc++.h>
using namespace std;
int population[1001][51];
int getFitnessVal(int i,int d)
{
    int result=0;
    for(int j=0;j<d;j++)
    {  int temp = ((population[i][j]*sin(population[i][j]))+(0.1*population[i][j]));//Alpine function
       if(temp<0)
        result-=temp;
       else
        result+=temp;
    }
    return result;
}
struct blackHole{
    int position;
    int fitnessVal;
};
int main() {
    int n,d,T=3,R,total_fitness=0;
    blackHole bh;
    bh.position=0;
    bh.fitnessVal=0;
    cout<<"Enter Population size and dimensions:";
    cin>>n>>d;
    srand(time(0));
    //Initialisation
    for(int i=0;i<n;i++)
    {  
        for(int j=0;j<d;j++)
        {
         population[i][j] = rand()%100;   
        }
    }
    //Calculate fitness Value of all candidate solutions and choose bloack hole
    for(int i=0;i<n;i++)
    {   int temp = getFitnessVal(i,d);
        total_fitness+=temp;
        if(bh.fitnessVal<temp)
        {
            bh.position=i;
            bh.fitnessVal=temp;
        }
    }
    R = (bh.fitnessVal/total_fitness);
    while(T--)
    {
        for(int i=0;i<n;i++)
        {  int random = rand()%2,sum=0,temp;
           temp=getFitnessVal(i,d);
            for(int j=0;j<d;j++)
            {   
                population[i][j]+=(random*(population[bh.position][j]-population[i][j]));
                sum+=(population[i][j]*population[i][j]);
            }
          int newFitnessVal = getFitnessVal(i,d);
          if(newFitnessVal>bh.fitnessVal)
              {
                  bh.position=i;
                  bh.fitnessVal=newFitnessVal;
              
              total_fitness=total_fitness+newFitnessVal-temp;
              R=(bh.fitnessVal/total_fitness);}
          else
          {if(sqrt(sum)<R)
          {   
              for(int j=0;j<d;j++)
              {
                  population[i][j]=rand()%100;
                  
              }
              int newFitnessVal = getFitnessVal(i,d);
            
              total_fitness=total_fitness+newFitnessVal-temp;
              R=(bh.fitnessVal/total_fitness);
          }
         }
        }
        
    }
    cout<<"The global optima is at "<<bh.position<<" index of population.\nValues are:";
    for(int j=0;j<d;j++)
    {
        cout<<population[bh.position][j]<<" ";
    }
    
	return 0;
}
