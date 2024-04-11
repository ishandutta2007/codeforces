#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
pair<int,int> operator + (pair<int,int> a, int b){ a.first+=b;return a;}
int n,L;
ll S;
int par[N],dp[N],w[N];
vector<int> E[N];
set<pair<ll,int> > dep[N],sum[N],val[N];
int dep_add[N],sum_add[N],val_add[N];
bool del[N];
void DFS(int u)
{
	ll all=0;
	for(int v:E[u]) DFS(v),all+=dp[v];
	dep[u].insert(mp(1,u));
	sum[u].insert(mp(w[u],u));
	val[u].insert(mp(all,u));
	for(int v:E[u])
	{
		dep_add[v]++;
		sum_add[v]+=w[u];
		val_add[v]+=all-dp[v];
		if(dep[v].size()>dep[u].size()) dep[u].swap(dep[v]),swap(dep_add[u],dep_add[v]);
		for(auto p:dep[v]) dep[u].insert(p+(dep_add[v]-dep_add[u]));
		if(sum[v].size()>sum[u].size()) sum[u].swap(sum[v]),swap(sum_add[u],sum_add[v]);
		for(auto p:sum[v]) sum[u].insert(p+(sum_add[v]-sum_add[u]));
		if(val[v].size()>val[u].size()) val[u].swap(val[v]),swap(val_add[u],val_add[v]);
		for(auto p:val[v]) val[u].insert(p+(val_add[v]-val_add[u]));
	}
	while(dep[u].size() && dep[u].rbegin()->first+dep_add[u]>L)
	{
		int id=dep[u].rbegin()->second;
		del[id]=1;
		dep[u].erase(*dep[u].rbegin());
	}
	while(sum[u].size() && sum[u].rbegin()->first+sum_add[u]>S)
	{
		int id=sum[u].rbegin()->second;
		del[id]=1;
		sum[u].erase(*sum[u].rbegin());
	}
	while(val[u].size() && del[val[u].begin()->second]) val[u].erase(val[u].begin());
	if(val[u].empty()){ printf("-1\n");exit(0);}
	dp[u]=val[u].begin()->first+val_add[u]+1;
}
int main()
{
	scanf("%i %i %lld",&n,&L,&S);
	for(int i=1;i<=n;i++) scanf("%i",&w[i]);
	for(int i=2;i<=n;i++) scanf("%i",&par[i]),E[par[i]].pb(i);
	for(int i=1;i<=n;i++) if(S<w[i]) return 0*printf("-1\n");
	DFS(1);
	printf("%i\n",dp[1]);
	return 0;
}