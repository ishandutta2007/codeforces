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
const int V=3100;
struct Edge{int num,ne;}e[2*V];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int rev[2][V],dp[V];
void dfs(int u,int fa)
{
    dp[u]=0;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa)continue;
        dfs(v,u);
        if(i%2==0)dp[u]+=dp[v];
        else dp[u]+=dp[v]+1;
    }
}
void Cal(int id,int u,int fa)
{
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa)continue;
        Cal(id,v,u);
        if(i%2==0)rev[0][i/2]=min(rev[0][i/2],dp[id]-dp[v]);
        else rev[1][i/2]=min(rev[1][i/2],dp[id]-dp[v]-1);
    }
}
int n,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)p[i]=-1;K=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        int ret=n-1;
        for(int i=0;i<n;i++)rev[0][i]=rev[1][i]=n;
        for(int i=1;i<=n;i++)
        {
            dfs(i,-1);
            ret=min(ret,dp[i]);
            Cal(i,i,-1);
        }
        for(int i=0;i<n;i++)
        ret=min(ret,rev[0][i]+rev[1][i]);
        printf("%d\n",ret);
    }
}