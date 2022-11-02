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
const int V=1010;
int f[V],set[V];
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
int dp[V],nu[V],n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        set[i]=i;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&f[i]);
            if(f[i]!=0)
            U(f[i],i);
        }
        memset(dp,0,sizeof(dp));
        memset(nu,0,sizeof(nu));
        dp[0]=1;
        for(int i=1;i<=n;i++)nu[find(i)]++;
        for(int i=1;i<=n;i++)
        {
            if(nu[i]==0)continue;
            if(find(m)==i)continue;
            for(int j=n;j>=nu[i];j--)
            if(dp[j-nu[i]])dp[j]=1;
        }
        int fr=1,u=m;
        while(f[u]!=0)
        {
            fr++;
            u=f[u];
        }
        for(int i=0;i<=n;i++)
        if(dp[i])printf("%d\n",i+fr);
    }
}