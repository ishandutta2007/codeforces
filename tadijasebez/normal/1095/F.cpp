#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const ll inf=9e18;
ll mn[N];
int par[N];
void init(){ for(int i=1;i<N;i++) par[i]=i;}
int Find(int x){ return par[x]==x?x:par[x]=Find(par[x]);}
ll sum;
void Union(int x, int y)
{
	x=Find(x);y=Find(y);
	sum-=mn[x];sum-=mn[y];
	par[x]=y;
	mn[y]=min(mn[x],mn[y]);
	sum+=mn[y];
}
ll a[N];
int main()
{
	int n,m,i,u,v,be;ll w;
	scanf("%i %i",&n,&m);
	ll best=inf;
	for(i=1;i<=n;i++) scanf("%lld",&mn[i]),a[i]=mn[i],best=min(best,mn[i]),sum+=mn[i];
	for(i=1;i<=n;i++) if(best==mn[i]) be=i;
	init();
	vector<pair<ll,pair<int,int> > > edges;
	for(i=1;i<=m;i++) scanf("%i %i %lld",&u,&v,&w),edges.pb(mp(w,mp(u,v)));
	for(i=1;i<=n;i++) edges.pb(mp(a[i]+best,mp(i,be)));
	sort(edges.begin(),edges.end());
	//ll ans=inf;
	//ans=sum+best*(n-2);
	//int s=n-2;
	ll ew=0;
	for(auto p:edges)
	{
		w=p.first;
		u=p.second.first;
		v=p.second.second;
		//w+=max(a[u],a[v])+best;
		if(Find(u)!=Find(v))
		{
			ew+=w;
			Union(u,v);
			//s--;
			//ans=min(ans,ew+sum+best*s);
		}
	}
	printf("%lld\n",ew);
	return 0;
}