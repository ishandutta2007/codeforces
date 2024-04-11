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
struct Edge{int num,ne;}e[V*2];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int pre[V];
void dfs(int u,int fa)
{
    int pr=pre[u];
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(v==fa)continue;
        pre[v]=i;
        dfs(v,u);
        if(pr!=-1)printf("%d %d\n",pr/2+1,i/2+1);
        pr=i;
    }
}
int n,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)p[i]=-1;K=0;
        printf("%d\n",n-1);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            printf("2 %d %d\n",x,y);
            add(x,y);add(y,x);
        }
        pre[1]=-1;dfs(1,-1);
    }
}