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
struct Edge{int num,ne;}e[2*V];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
    e[K].num=x;e[K].ne=p[y];p[y]=K++;
}
int vis[2][V],a[V];
void dfs(int u,int id)
{
    if(vis[id][u]!=0)return;
    vis[id][u]=1;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        if(i%2!=id%2)continue;
        int v=e[i].num;
        if(id==0)
        {
            dfs(v,id);
        }
        else
        {
            if(a[v]!=1)
            dfs(v,id);
            else vis[id][v]=1;
        }
    }
}
int n,m,i,x,y;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(p,-1,sizeof(p));K=0;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            x--;y--;add(x,y);
        }
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        if(a[i]==1)dfs(i,0);
        else if(a[i]==2)dfs(i,1);
        for(i=0;i<n;i++)
        {
            if(vis[0][i]&&vis[1][i])puts("1");
            else puts("0");
        }
    }
}