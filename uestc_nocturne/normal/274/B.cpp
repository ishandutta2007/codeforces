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
LL dc[V],ic[V];
int a[V];
void dfs(int u,int fa)
{
	dc[u]=ic[u]=0;
	for(int i=p[u];i!=-1;i=e[i].ne)
	{
		int v=e[i].num;
		if(v==fa)continue;
		dfs(v,u);
		dc[u]=max(dc[u],dc[v]);
		ic[u]=max(ic[u],ic[v]);
	}
	LL now=a[u]+ic[u]-dc[u];
	if(now>0)dc[u]+=now;
	else ic[u]-=now;
}
int n,x,y;
int main()
{
	while(~scanf("%d",&n))
	{
		memset(p,-1,sizeof(p));K=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		dfs(1,-1);
		printf("%I64d\n",dc[1]+ic[1]);
	}
}