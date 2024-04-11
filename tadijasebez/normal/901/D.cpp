#include <stdio.h>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=100050;
vector<pair<ll,ll> > E[N];
ll odd,s,t,mark[N],par[N],disc[N],tid,w[N],ans[N],need[N],edg[N];
void DFS(ll u, ll p)
{
	par[u]=p;
	disc[u]=++tid;
	for(ll i=0;i<E[u].size();i++)
	{
		ll v=E[u][i].first;
		ll e=E[u][i].second;
		if(!disc[v])
		{
			edg[v]=e;
			mark[v]=mark[u]^1;
			DFS(v,u);
			ans[e]+=need[v];
			need[u]-=need[v];
		}
		else if(disc[v]<disc[u] && mark[v]==mark[u])
		{
			odd=e;
			s=u;
			t=v;
		}
	}
}
ll sol[N],was[N];
void DFS(ll u)
{
	was[u]=1;
	for(ll i=0;i<E[u].size();i++)
	{
		ll v=E[u][i].first;
		ll e=E[u][i].second;
		if(!was[v] && e!=odd)
		{
			DFS(v);
			sol[e]+=w[v];
			w[u]-=w[v];
		}
	}
}
int main()
{
	ll n,i,m,u,v;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&w[i]),need[i]=w[i];
	for(i=1;i<=m;i++) scanf("%lld %lld",&u,&v),E[u].pb(mp(v,i)),E[v].pb(mp(u,i));
	DFS(1,0);
	if(!odd && need[1]) return printf("NO\n"),0;
	if(!need[1])
	{
		printf("YES\n");
		for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
		return 0;
	}
	DFS(s);
	ll add=w[s]/2,f=1;
	for(u=s;u!=t;u=par[u],f=-f)
	{
		sol[edg[u]]+=add*f;
	}
	sol[odd]+=f*add;
	printf("YES\n");
	for(i=1;i<=m;i++) printf("%lld\n",sol[i]);
	return 0;
}