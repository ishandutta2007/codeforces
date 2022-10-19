#include<bits/stdc++.h>
using namespace std;
const int N=50005,K=505;
int n,k,dp[N][K],a[N];
vector<int>e[N];
long long ans;
void dfs(int u,int f)
{
	dp[u][0]=1,a[u]=f;
	for(int v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		for(int j=1;j<=k;j++)
			dp[u][j]+=dp[v][j-1];
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int u=1;u<=n;u++)
	{
		for(int i=0;i<=k;i++)
			ans+=1ll*dp[u][i]*dp[u][k-i];
		for(auto v:e[u])
			if(v!=a[u])
				for(int i=0;i<=k-1;i++)
					ans-=1ll*dp[v][i]*dp[v][k-i-2];
	}
	printf("%lld\n",ans/2);
	return 0;
}