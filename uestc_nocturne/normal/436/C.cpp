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
const int V=1100;
const int En=V*V;
struct Node
{
	int u,v,len;
}b[En];
bool cmp(Node x,Node y)
{
	return x.len<y.len;
}
int set[V];
int find(int x)
{
	if(x!=set[x])set[x]=find(set[x]);
	return set[x];
}
void U(int x,int y)
{
	int u=find(x);
	int v=find(y);
	set[u]=v;
}
struct Edge{int v,ne;}e[En];
int p[V],kn;
void add(int u,int v)
{
	e[kn].v=v;e[kn].ne=p[u];p[u]=kn++;
}
void dfs(int u,int fa)
{
	if(fa!=-1)printf("%d %d\n",u,fa);
	for(int i=p[u];i!=-1;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
	}
}
char map[V][12][12];
int n,m,K,W;
const int P=1000000007;
int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&K,&W))
	{
		int N=K+1,t=0;
		for(int k=1;k<=K;k++)
		{
			b[t].u=0;
			b[t].v=k;
			b[t++].len=n*m;
			for(int i=0;i<n;i++)
			scanf("%s",map[k][i]);
		}
		for(int u=1;u<=K;u++)
		for(int v=1;v<u;v++)
		{
			int df=0;
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			if(map[u][i][j]!=map[v][i][j])
			df++;
			b[t].u=u;
			b[t].v=v;
			b[t++].len=df*W;
		}
		sort(b,b+t,cmp);
		for(int i=0;i<N;i++)set[i]=i;
		memset(p,-1,sizeof(p));kn=0;
		int ret=0;
		for(int i=0;i<t;i++)
		{
			int u=b[i].u;
			int v=b[i].v;
			if(find(u)==find(v))continue;
			ret+=b[i].len;
			add(u,v);add(v,u);
			U(u,v);
		}
		printf("%d\n",ret);
		dfs(0,-1);
	}
}