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
const int N=1000000000;
const int V=3001000;
int nu[V],dp[V],p[120],pn,is[120],ct,mx[V];
void dfs(int k,LL x)
{
    nu[ct++]=x;
    for(int i=k;i<pn;i++)
    {
        if(x*p[i]<=N)
        dfs(i,x*p[i]);
    }
}
int main()
{
    memset(is,0,sizeof(is));pn=0;
    for(int i=2;i<=100;i++)
    {
        if(is[i])continue;
        p[pn++]=i;
        for(int j=2*i;j<=100;j+=i)
        is[j]=1;
    }
    ct=0;
    dfs(0,1);
    sort(nu,nu+ct);
    for(int i=0;i<ct;i++)dp[i]=mx[i]=100100;
    dp[0]=mx[0]=0;
    for(int i=2;i<=100;i++)
    {
        int pos=0;
        for(int j=0;j<ct;j++)
        {
            mx[j]=min(mx[j],dp[j]+i);
            while(pos<ct&&nu[pos]<(LL)i*nu[j])pos++;
            if(pos==ct)continue;
            dp[pos]=min(dp[pos],dp[j]+1);
        }
    }
    int l,r,K;
    while(~scanf("%d%d%d",&l,&r,&K))
    {
        int ret=0;
        for(int i=0;i<ct;i++)
        {
            if(nu[i]>=l&&nu[i]<=r&&mx[i]<=K)
            ret++;
        }
        printf("%d\n",ret);
    }
}