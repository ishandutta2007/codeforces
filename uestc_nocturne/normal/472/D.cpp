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
const int V=2100;
int f[V],d[V][V],n,lca[V][V],dp[V];
vector<int> son[V],st[V];
void dfs(int u)
{
    st[u].push_back(u);
    for(int i=0;i<son[u].size();i++)
    {
        int v=son[u][i];
        dp[v]=dp[u]+d[u][v];
        //printf("D %d %d %d %d\n",u,v,dp[u],d[u][v]);
        dfs(v);
        for(int j=0;j<st[v].size();j++)
        st[u].push_back(st[v][j]);
    }
    for(int i=0;i<son[u].size();i++)
    for(int j=0;j<i;j++)
    {
        int v=son[u][i];
        int w=son[u][j];
        for(int ii=0;ii<st[v].size();ii++)
        for(int jj=0;jj<st[w].size();jj++)
        lca[st[v][ii]][st[w][jj]]=lca[st[w][jj]][st[v][ii]]=u;
    }
    for(int i=0;i<st[u].size();i++)
    lca[u][st[u][i]]=lca[st[u][i]][u]=u;
}

bool check()
{
    for(int i=0;i<n;i++)
    if(d[i][i]!=0)return false;
    for(int i=0;i<n;i++)f[i]=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(d[i][j]!=d[j][i])return false;
        if(i!=j&&d[i][j]==0)return false;
        if(i==j)continue;
        if(d[i][j]+d[j][0]==d[i][0])
        {
            if(d[j][0]>d[f[i]][0])
            f[i]=j;
        }
    }
    //for(int i=0;i<n;i++)printf("%d ",f[i]);puts("");
    for(int i=0;i<n;i++)son[i].clear(),st[i].clear();
    for(int i=1;i<n;i++)son[f[i]].push_back(i);
    memset(lca,0,sizeof(lca));
    dp[0]=0;dfs(0);
    //for(int i=0;i<n;i++)printf("%d %d %d\n",i,dp[i],f[i]);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i!=j&&d[i][j]+2*dp[lca[i][j]]!=dp[i]+dp[j])
    {
        //printf("%d %d %d\n",i,j,lca[i][j]);
        return false;
    }
    return true;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&d[i][j]);
        if(check())puts("YES");
        else puts("NO");
    }
    return 0;
}