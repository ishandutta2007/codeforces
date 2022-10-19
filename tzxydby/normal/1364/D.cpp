#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,k,dep[N],fa[N];
vector<int>e[N],ans;
struct cyc
{
	int u,v,l;
	bool operator<(const cyc k)const
	{
		return l<k.l;
	}
}zh;
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	fa[u]=f;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		if(!dep[v])
			dfs(v,u);
		else
		{
			if(dep[u]<dep[v])
				continue;
			cyc p;
			p.u=u,p.v=v,p.l=dep[u]-dep[v]+1;
			if(p<zh)
				zh=p;
		}
	}
}
int dp[N][2];
void solve(int u)
{
	for(auto v:e[u])
	{
		if(v==fa[u])
			continue;
		solve(v);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	dp[u][1]++;
}
void path(int u,int p)
{
	if(p==0)
	{
		for(auto v:e[u])
		{
			if(v==fa[u])
				continue;
			if(dp[v][0]>dp[v][1])
				path(v,0);
			else
				path(v,1);
		}
	}
	else
	{
		ans.push_back(u);
		for(auto v:e[u])
		{
			if(v==fa[u])
				continue;
			path(v,0);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	zh.l=1e9;
	dfs(1,0);
	if(zh.l==1e9)
	{
		puts("1");
		solve(1);
		if(dp[1][0]>dp[1][1])
			path(1,0);
		else
			path(1,1);
		k=(k+1)/2;
		for(int i=0;i<k;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	if(zh.l<=k)
	{
		printf("2\n%d\n",zh.l);
		for(int i=zh.u;i!=zh.v;i=fa[i])
			printf("%d ",i);
		printf("%d ",zh.v);
	}
	else
	{
		puts("1");
		int co=1;
		k=(k+1)/2;
		for(int i=zh.u;i!=zh.v&&ans.size()<k;i=fa[i])
		{
			if(co)
				ans.push_back(i);
			co^=1;
		}
		for(auto i:ans)
			printf("%d ",i);
	}
	return 0;
}