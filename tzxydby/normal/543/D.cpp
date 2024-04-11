#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,mod=1e9+7;
int n,dp[N],ans[N];
vector<int>e[N],p[N],s[N];
void dfs(int u)
{
	dp[u]=1;
	for(auto v:e[u])
	{
		dfs(v);
		dp[u]=dp[u]*(dp[v]+2)%mod;
	}
	dp[u]=(dp[u]+mod-1)%mod;
}
void sol(int u,int x)
{
	if(u!=1)
		ans[u]=((dp[u]+1)%mod*(x+2)%mod)%mod;
	else
		ans[u]=(dp[u]+1)%mod;
	int m=e[u].size();
	for(int i=0;i<m;i++)
	{
		int v=e[u][i];
		p[u][i]=(i==0?1:p[u][i-1])*(dp[v]+2)%mod;
	}
	for(int i=m-1;i>=0;i--)
	{
		int v=e[u][i];
		s[u][i]=(i==m-1?1:s[u][i+1])*(dp[v]+2)%mod;
	}
	for(int i=0;i<m;i++)
	{
		int v=e[u][i];
		sol(v,(((i==0?1:p[u][i-1])*(i==m-1?1:s[u][i+1])%mod*((u==1)?1:x+2)%mod)-1+mod)%mod);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		e[x].push_back(i);
		p[x].push_back(0);
		s[x].push_back(0);
	}
	dfs(1);
	sol(1,1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}