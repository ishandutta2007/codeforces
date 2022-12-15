#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int z[5]={0};
    int a;
    
    for(int i=0;i<n;i++)
    {
        cin>>a;
        z[a]++;
    }
    int taxis;
    taxis = z[4];
    z[4]=0;
    if(z[1]>=z[3])
    {
        taxis+=z[3];
        z[1]-=z[3];
        z[3]=0;
    }
    else
    {
        taxis+=z[1];
        z[3]-=z[1];
        z[1]=0;
    }
    if(z[2]%2==0)
    {
        taxis+=z[2]/2;
        z[2]=0;
    }
    else
    {
        taxis+=z[2]/2;
        z[2]=1;
    }
    taxis+=z[3];
    if(z[1]==0)
    {
        taxis+=z[2];
    }
    else
    {
        taxis+=z[2];
        z[1]-=2*z[2];
        z[2]=0;
        taxis+=(z[1]+3)/4;
    }
    cout<<taxis;
    return 0;
}