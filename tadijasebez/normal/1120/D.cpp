#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const ll inf=1e18;
vector<int> E[N];
int c[N];
ll dp[N][2];
vector<int> go[N][2];
int take[N];
void Solve(int u, int p)
{
	if(u!=1 && E[u].size()==1) dp[u][0]=c[u],dp[u][1]=0,take[u]=2;
	else
	{
		dp[u][0]=dp[u][1]=inf;
		ll sum=0;
		for(int v:E[u]) if(v!=p)
		{
			Solve(v,u);
			sum+=dp[v][0];
		}
		dp[u][0]=sum;take[u]=1;
		for(int v:E[u]) if(v!=p)
		{
			if(dp[u][0]>sum+dp[v][1]-dp[v][0]+c[u]) dp[u][0]=sum+dp[v][1]-dp[v][0]+c[u],go[u][0].clear(),take[u]=0;
			if(dp[u][0]==sum+dp[v][1]-dp[v][0]+c[u]) go[u][0].pb(v),take[u]|=2;
			if(dp[u][1]>sum+dp[v][1]-dp[v][0]) dp[u][1]=sum+dp[v][1]-dp[v][0],go[u][1].clear();
			if(dp[u][1]==sum+dp[v][1]-dp[v][0]) go[u][1].pb(v);
		}
	}
	//printf("u:%i dp[u][0]=%lld dp[u][1]=%lld take[u]=%i go[u][0]=%i go[u][1]=%i\n",u,dp[u][0],dp[u][1],take[u],go[u][0].size(),go[u][1].size());
}
vector<int> ans;
bool was[N][2];
void Take(int u, int p, int state)
{
	if(was[u][state]) return;
	was[u][state]=1;
	if((take[u]&2) && state==0) ans.pb(u);
	if(go[u][state].size()!=1 || ((take[u]&1) && state==0))
	{
		for(int v:E[u]) if(v!=p) Take(v,u,0);
		for(int v:go[u][state]) Take(v,u,1);
	}
	else
	{
		for(int v:E[u]) if(v!=p)
		{
			if(go[u][state][0]==v) Take(v,u,1);
			else Take(v,u,0);
		}
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	Solve(1,0);
	Take(1,0,0);
	sort(ans.begin(),ans.end());
	printf("%lld %i\n",dp[1][0],ans.size());
	for(int j:ans) printf("%i ",j);printf("\n");
	return 0;
}