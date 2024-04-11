#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
vector<int> G[N],E[N];
ll dep[N];
bool cyc_mark[N];
int mn[N],lvl[N],a[N];
bool was[N];
void DFS(int u, int p)
{
	was[u]=1;
	lvl[u]=lvl[p]+1;
    for(int v:G[u]) if(v!=p)
	{
		if(!was[v])
		{
			DFS(v,u);
			E[u].pb(v);
			if(cyc_mark[v]) cyc_mark[u]=1;
		}
		else if(lvl[v]<lvl[u]) cyc_mark[u]=1;
	}
	//printf("%i: %i\n",u,cyc_mark[u]);
}
void Calc(int u, int p)
{
	dep[u]=dep[p];
	if(cyc_mark[u]==0) dep[u]+=a[u];
	for(int v:E[u]) Calc(v,u);
}
int main()
{
	int n,m,s;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	for(int i=1,u,v;i<=m;i++) scanf("%i %i",&u,&v),G[u].pb(v),G[v].pb(u);
	scanf("%i",&s);
	DFS(s,0);
	Calc(s,0);
	ll mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,dep[i]);
	ll ans=mx;
	for(int i=1;i<=n;i++) if(cyc_mark[i]) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}