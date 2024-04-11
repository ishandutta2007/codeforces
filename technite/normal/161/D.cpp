#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
ll ans=0;
void dfs(int x,int p,vvi&adj,vvl&dp,int k)
{
	dp[x][0]=1;
	for(auto node:adj[x])
	{
		if(node==p)continue;
		dfs(node,x,adj,dp,k);
		dp[x][1]++;
		for(int i=2;i<=k;i++)
		{
			dp[x][i]+=dp[node][i-1];
		}
		
	}
	for(auto node:adj[x])
	{
		if(node==p)continue;
	
		long long temp=0;
		for(int i=1;i<=k-1;i++)
		{
			temp+=dp[node][i-1]*(dp[x][k-i]-dp[node][k-i-1]);
		}
		ans+=temp;
	}
}
int main()
{
	int n,k;
	cin>>n>>k;
	vvi adj(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vvl dp(n,vl(k+1,0));
	dfs(0,0,adj,dp,k);
	ans/=2;
	for(int i=0;i<n;i++)  ans+=dp[i][k];
	cout<<ans<<'\n';
	
}