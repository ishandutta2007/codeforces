#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=998244353;
const int N=300050;
const int L=20;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
void Zero(){ printf("0\n");exit(0);}
vector<int> T[N],E[N];
int col[N],par[N][L],dep[N];
bool del[N];
void DFS1(int u, int p)
{
	del[u]=1;
	par[u][0]=p;
	dep[u]=dep[p]+1;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	if(col[u]) del[u]=0;
	for(int v:T[u]) if(v!=p)
	{
		DFS1(v,u);
		del[u]&=del[v];
	}
	//printf("u:%i del:%i\n",u,del[u]);
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
vector<int> all[N];
int high[N];
vector<int> rnm;
void Extend(int u, int p)
{
	for(int v:T[u]) if(v!=p && !del[v])
	{
		Extend(v,u);
		if(high[v]) continue;
		if(col[v])
		{
			if(col[u] && col[u]!=col[v]) Zero();
			col[u]=col[v];
		}
	}
	if(!col[u]) rnm.pb(u);
	//printf("u:%i col:%i\n",u,col[u]);
}
int dp[N][2];
void Solve(int u, int p, int k)
{
	if(u<=k) dp[u][1]=1,dp[u][0]=0;
	else dp[u][0]=1,dp[u][1]=0;
	for(int v:E[u]) if(v!=p)
	{
		Solve(v,u,k);
		if(u<=k)
		{
			dp[u][1]=mul(dp[u][1],add(dp[v][0],dp[v][1]));
		}
		else
		{
			dp[u][1]=add(mul(dp[u][1],add(dp[v][0],dp[v][1])),mul(dp[u][0],dp[v][1]));
			dp[u][0]=mul(dp[u][0],add(dp[v][0],dp[v][1]));
		}
	}
	//printf("u:%i dp[0]:%i dp[1]:%i\n",u,dp[u][0],dp[u][1]);
}
int main()
{
	int n,k,i,u,v;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&col[i]),all[col[i]].pb(i);
	vector<pair<int,int>> edges;
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),T[u].pb(v),T[v].pb(u),edges.pb(mp(u,v));
	//Compressing the Tree
	int root;
	for(i=1;i<=n;i++) if(col[i]) root=i;
	DFS1(root,0);
	for(i=1;i<=k;i++)
	{
		int lca=all[i][0];
		for(int j=1;j<all[i].size();j++)
		{
			lca=LCA(lca,all[i][j]);
		}
		if(high[lca]) Zero();
		high[lca]=i;
	}
	Extend(root,0);
	sort(rnm.begin(),rnm.end());
	set<pair<int,int>> was;
	for(auto e:edges)
	{
		u=e.first;
		v=e.second;
		if(del[u] || del[v]) continue;
		if(col[u]) u=col[u];
		else u=lower_bound(rnm.begin(),rnm.end(),u)-rnm.begin()+k+1;
		if(col[v]) v=col[v];
		else v=lower_bound(rnm.begin(),rnm.end(),v)-rnm.begin()+k+1;
		if(was.count(mp(u,v)) || was.count(mp(v,u))) continue;
		if(u==v) continue;
		E[u].pb(v);
		E[v].pb(u);
		was.insert(mp(u,v));
	}
	//Solving problem
	Solve(1,0,k);
	printf("%i\n",dp[1][1]);
	return 0;
}