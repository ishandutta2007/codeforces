#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb double
#define pb push_back
vector<pair<ll,ll>> all;
struct MinCostMaxFlow{
	static const int NSZ=55,ESZ=5005;
	static const ll inf=9e18;
	struct Edge{int u,v;ll c,f,w;};
	Edge edges[ESZ];
	int xb,s,t,n,go[NSZ],q[NSZ],ql,qr,inq[NSZ];
	ll dist[NSZ];
	vector<int> G[NSZ];
	void init(int _n){n=_n;xb=0;}
	void AddEdge(int u,int v,ll c,ll w){
		G[u].pb(xb);edges[xb++]=(Edge){u,v,c,0,w};
		G[v].pb(xb);edges[xb++]=(Edge){v,u,0,0,-w};
	}
	bool spfa(){
		for(int i=1;i<=n;i++)dist[i]=inf,inq[i]=0;
		ql=qr=0;q[qr++]=s;dist[s]=0;inq[s]=1;
		for(;ql!=qr;ql=(ql+1)%NSZ){
			int u=q[ql];inq[u]=0;
			for(int e:G[u]){
				if(edges[e].f<edges[e].c && dist[edges[e].v]>dist[u]+edges[e].w){
					dist[edges[e].v]=dist[u]+edges[e].w;go[edges[e].v]=e;
					if(!inq[edges[e].v])q[qr]=edges[e].v,inq[edges[e].v]=1,qr=(qr+1)%NSZ;
				}
			}
		}
		return dist[t]!=inf;
	}
	pair<ll,ll> Solve(int _s,int _t){
		s=_s;t=_t;
		ll cost=0,flow=0;
		while(spfa()){
			ll cut=inf;
			for(int i=t;i!=s;i=edges[go[i]].u)cut=min(cut,edges[go[i]].c-edges[go[i]].f);
			for(int i=t;i!=s;i=edges[go[i]].u)edges[go[i]].f+=cut,edges[go[i]^1].f-=cut;
			flow+=cut;cost+=cut*dist[t];
			all.pb({cost,flow});
		}
		return {cost,flow};
	}
};
int main(){
	int n,m,q;
	scanf("%i %i",&n,&m);
	MinCostMaxFlow NET;NET.init(n);
	for(int i=1,u,v,w;i<=m;i++)scanf("%i %i %i",&u,&v,&w),NET.AddEdge(u,v,1,w);
	NET.Solve(1,n);
	scanf("%i",&q);
	while(q--){
		int x;scanf("%i",&x);
		ldb ans=1e9;
		for(auto t:all)ans=min(ans,(ldb)(t.first+x)/t.second);
		printf("%.12f\n",ans);
	}
	return 0;
}