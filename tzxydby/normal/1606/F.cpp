#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],ans[N],x[N],k[N];
vector<int>e[N],dp[N],q[N];
void dfs(int u,int f)
{
	a[u]=-1;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		a[u]++;
	}
}
void cal(int u,int f)
{
	if(a[u]<0)
		return;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		cal(v,u);
		if(dp[v].size()>dp[u].size())
			dp[u].resize(dp[v].size());
		for(int i=0;i<dp[v].size();i++)
			dp[u][i]+=dp[v][i];
	}
	for(auto i:q[u])
		if(k[i]<dp[u].size())
			ans[i]=dp[u][k[i]];
	if(dp[u].size()<a[u])
		dp[u].resize(a[u]);
	for(int i=0;i<dp[u].size();i++)
		dp[u][i]+=a[u]-i;
	while(dp[u].size()&&dp[u].back()<0)
		dp[u].pop_back();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&k[i]);
		q[x[i]].push_back(i);
	}
	dfs(1,0);
	cal(1,0);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]+a[x[i]]+1);
	return 0;
}