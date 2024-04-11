#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000050;
int n,k;
vector<int> E[N];
int bck[N],sz[N],dp[N],par[N];
void DFS(int u)
{
	for(int v:E[u])
	{
		DFS(v);
		if(bck[v]) sz[u]+=sz[v];
		bck[u]=max(bck[u],bck[v]-1);
	}
	if(E[u].empty()) bck[u]=k,sz[u]=1;
}
void Solve(int u)
{
	dp[u]=1;
	for(int v:E[u])
	{
		Solve(v);
		dp[u]=max(dp[u],sz[u]-sz[v]*(bck[v]!=0)+dp[v]);
	}
}
int main()
{
	scanf("%i %i",&n,&k);
	for(int i=2;i<=n;i++) scanf("%i",&par[i]),E[par[i]].pb(i);
	DFS(1);Solve(1);
	printf("%i\n",dp[1]);
	return 0;
}