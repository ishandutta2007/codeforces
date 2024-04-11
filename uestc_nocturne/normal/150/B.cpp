/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const LL P=1000000007;
int set[2100];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    if(find(x)==find(y))return;
    int p=find(x);
    set[p]=y;
}
int n,m,k,i,j,nu[2100];
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(i=0;i<n;i++)set[i]=i;
        for(i=0;i+k-1<n;i++)
        {
            for(j=0;2*j<k;j++)
            U(i+j,i+k-1-j);
        }
        memset(nu ,0,sizeof(nu));
        for(i=0;i<n;i++)nu[find(i)]++;
        LL ans=1;
        for(i=0;i<n;i++)
        if(nu[i]!=0)ans=ans*m%P;
        cout<<ans<<endl;
    }
}