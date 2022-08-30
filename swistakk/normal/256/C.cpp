#include <iostream>
#include <cmath>
#define N 1000005
#define R 15
#define uint long long int
using namespace std;
int nim[N];
int ile[N][R];
int x4[N];
int x2[N];
int licz(uint k)
{
    if(k<=3)
    {
        return 0;
    }
    int kt=0;
    while(ile[  int(pow( double(k), 0.5) +0.00000001) ][kt]!=ile[  int(pow( double(k), 0.25) -0.00000001)  ][kt])
    {
        kt++;
    }
    return kt;
}
int main()
{
    x4[1]=1;
    for(int i=1; i*i*i*i<=N-2; i++)
    {
        for(int j=i*i*i*i+1; j<N && j<=(i+1)*(i+1)*(i+1)*(i+1); j++)
        {
            x4[j]=i+1;
        }
    }
    for(int i=1; i*i<=N-2; i++)
    {
        for(int j=i*i; j<N && j<(i+1)*(i+1); j++)
        {
            x2[j]=i;
        }
    }
    nim[1]=0;
    ile[1][0]=1;
    nim[2]=0;
    ile[2][1]=0;
    ile[2][0]=2;
    for(int i=3; i<=N-2; i++)
    {
        int z=licz(i);
        nim[i]=z;
        for(int j=0; j<R; j++)
        {
            ile[i][j]=ile[i-1][j];
        }
        ile[i][z]++;
    }
    int xorr=0;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        uint a;
        cin>>a;
        xorr=(xorr^(licz(a)));
        // cout<<xorr<<" zia"<<endl;
    }
    /* cout<<xorr<<endl;
    for(int i=1; i<=20; i++)
    {
        cout<<nim[i]<<" ";
    }
    cout<<endl; */
    if(xorr==0)
    {
        cout<<"Rublo"<<endl;
    }
    else
    {
        cout<<"Furlo"<<endl;
    }
    return 0;
}