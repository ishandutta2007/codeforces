#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int k,n,l,i,j,ansb,tmp,x,h[4003]={0};
    cin>>k>>n;
    ansb=k-1;
    for (i=0;i<n;i++)
    {
        cin>>tmp;
        ansb-=(3-tmp);
        for (j=0;j<3-tmp;j++) {cin>>x;h[x]=1;}
    }
    int r=1;
    int ansa=0;
    h[k]=1;h[k+1]=0;j=0;
    for(i=1;i<=k;i++)
    {
              if (!h[i]) j++;else {ansa+=(j+1)/2;j=0;}       
    }
    cout<<(ansa)<<" "<<ansb;
    
}