#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
const int L=19;
const ll inf=1e15;
vector<int> E[N];
int par[N][L],dep[N];
void DFS(int u, int p)
{
	dep[u]=dep[p]+1;
	par[u][0]=p;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u]) if(v!=p) DFS(v,u);
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	for(int i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
vector<pair<int,int> > up[N];
bool ok[N];
ll dp[N];
int hi[N];
set<pair<ll,int> > st[N];
pair<ll,int> operator + (pair<ll,int> a, ll b){ a.first+=b;return a;}
ll st_add[N],ans;
void Solve(int u, int p)
{
	int nok=0;
	ll sum=0;hi[u]=dep[u];
	for(int v:E[u]) if(v!=p) Solve(v,u),nok+=!ok[v],sum+=ok[v]?dp[v]:0,hi[u]=min(hi[u],hi[v]);
	if(nok){ ok[u]=0;}
	else
	{
		for(int v:E[u]) if(v!=p)
		{
			if(st[u].size()<st[v].size()) st[u].swap(st[v]),swap(st_add[u],st_add[v]);
			for(auto p:st[v]) st[u].insert(p+(st_add[v]-st_add[u]));
		}
		dp[u]=sum;
		for(auto p:up[u]) st[u].insert(mp(p.second,dep[p.first])+(-st_add[u]));
		if(hi[u]==dep[u])
		{
			while(st[u].size() && st[u].begin()->second>=dep[u]) st[u].erase(st[u].begin());
            if(st[u].empty()) ok[u]=0;
            else
			{
				ok[u]=1;
				dp[u]+=st[u].begin()->first+st_add[u];
				hi[u]=st[u].begin()->second;
				st_add[u]-=st[u].begin()->first+st_add[u];
				st[u].erase(st[u].begin());
			}
		}
		else ok[u]=1;
	}
	if(u==1) ans=nok==0?sum:-1;
}
int main()
{
	int n,m,i,u,v,c;
	scanf("%i %i",&n,&m);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	for(i=1;i<=m;i++) scanf("%i %i %i",&u,&v,&c),up[u].pb(mp(LCA(u,v),c));
	Solve(1,0);
	printf("%lld\n",ans);
	return 0;
}