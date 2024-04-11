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
const int V=100100;
const int P=1000000007;
int dp[V],pr[310],ne[310],a[310],vis[310];
int set[310];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    int p=find(x);
    set[p]=y;
}
void dfs(int x)
{
    if(vis[x]!=-1)return;
    vis[x]=1;
    if(ne[x]==-1)return;
    dfs(ne[x]);a[x]+=a[ne[x]];
}
int n,q,t,x,y;
int main()
{
    while(~scanf("%d%d%d",&n,&q,&t))
    {
        memset(pr,-1,sizeof(pr));
        memset(ne,-1,sizeof(ne));
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)set[i]=i;
        bool can=true;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            pr[x]=y;ne[y]=x;
            if(find(x)==find(y))
            can=false;
            else U(x,y);
        }
        if(!can)
        {
            puts("0");
            continue;
        }
        memset(vis,-1,sizeof(vis));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)dfs(i);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(pr[i]!=-1)
            {
                for(int j=t;j>=a[i];j--)
                dp[j]=dp[j-a[i]];
                for(int j=min(t,a[i]-1);j>=0;j--)
                dp[j]=0;
            }
            for(int j=a[i];j<=t;j++)
            dp[j]+=dp[j-a[i]],dp[j]%=P;
        }
        printf("%d\n",dp[t]);
    }
}