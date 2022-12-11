#include<bits/stdc++.h>
using namespace std;
int n,k,l,m;
const int max_k=10+5;
const int max_l=100+5;
const int max_m=20+5;
int x[max_k],a[max_l],y[max_m];
const int max_n=1e4+5;
vector<int> edge[max_n];
inline void add_edge(int x,int y)
{
	edge[x].push_back(y);
	edge[y].push_back(x);
}
const int inf=1e9;
int dis[max_n],que[max_n];
inline void bfs(int s)
{
	for(int i=1;i<=n+1;++i)
		dis[i]=inf;
	dis[s]=0;
	int sz=0;
	que[++sz]=s;
	for(int t=1;t<=sz;++t)
	{
		int x=que[t];
		for(int y:edge[x])
		{
			if(dis[y]==inf)
			{
				dis[y]=dis[x]+1;
				que[++sz]=y;
			}
		}
	}
}
int cost[max_m][max_m];
const int max_S=1<<20|5;
int dp[max_S];
int main()
{
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=k;++i)
		scanf("%d",x+i);
	for(int i=1;i<=l;++i)
		scanf("%d",a+i);
	for(int i=1;i<=k;++i)
	{
		int j=i;
		while(j+1<=k&&x[j+1]-x[j]==1)
			++j;
		y[m++]=x[i],y[m++]=x[j]+1;
		i=j;
	}
	for(int i=1;i<=l;++i)
		for(int L=1;L+a[i]-1<=n;++L)
			add_edge(L,L+a[i]);
	for(int i=0;i<m;++i)
	{
		bfs(y[i]);
		for(int j=i+1;j<m;++j)
			cost[i][j]=dis[y[j]];
	}
	int U=(1<<m)-1;
	for(int S=1;S<=U;++S)
		dp[S]=inf;
	for(int S=0;S<U;++S)
	{
		int v=dp[S];
		if(v==inf)
			continue;
		int a=0;
		while(S>>a&1)
			++a;
		assert(a<m);
		int T=S|(1<<a);
		for(int b=a+1;b<m;++b)
		{
			if(~T>>b&1)
			{
				T|=1<<b;
				dp[T]=min(dp[T],v+cost[a][b]);
				T^=1<<b;
			}
		}
	}
	int ans=(dp[U]==inf?-1:dp[U]);
	printf("%d\n",ans);
	return 0;
}
/*
10 5 1
2 4 6 9 10
1
---
5
*/