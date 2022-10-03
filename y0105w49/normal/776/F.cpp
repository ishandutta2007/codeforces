#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;


const int N=100<<10;
vector<int> adj[N];
int n,m;
int nn=0;

map<pair<int,int>,int> ids;
vector<pair<int,int> > membs[N];

set<int> fadj[N];
int col[N];
int sz[N];

int dfs_sz(int u,int p=-1) {
	sz[u]=1;
	for(int v:fadj[u]) if(v!=p) sz[u]+=dfs_sz(v,u);
	return sz[u];
}
void dfsZ(int u,int c=1) {
	for(int v:fadj[u]) if(sz[v]+sz[v]>sz[u]) {
		int tot=sz[u];
		sz[u]-=sz[v];
		sz[v]=tot;
		return dfsZ(v,c);
	}

	for(int v:fadj[u]) fadj[v].erase(u);
	col[u]=c;
	for(int v:fadj[u]) dfsZ(v,c+1);
}

int32_t main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b; scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i=1;i<n;i++) adj[i].pb(i+1),adj[i+1].pb(i);
	adj[n].pb(1),adj[1].pb(n);

	for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end(),[&](int x,int y){
		if(x>i && y<i) return true;
		if(x<i && y>i) return false;
		return x<y;
	});
	for(int i=1;i<=n;i++) reverse(adj[i].begin(),adj[i].end());
	for(int i=1;i<=n;i++) {
		// cerr<<"adj["<<i<<"]:";
		// for(int x:adj[i]) cerr<<" "<<x;
		// cerr<<endl;
	}

	for(int u=n;u>=1;u--) {
		for(int i=1;i<(int)adj[u].size();i++) {
			int v=adj[u][i-1];
			int w=adj[u][i];
			swap(v,w);
			// cerr<<"u,v,w: "<<u<<","<<v<<","<<w<<endl;
			if(!ids.count({u,v})) {
				// cerr<<"fail"<<endl;
				ids[{u,v}]=++nn;
				membs[nn].push_back({u,v});
			}
			int me=ids[{u,v}];
			if(!ids.count({w,u})) membs[me].push_back({w,u});
			ids[{w,u}]=me;
		}
	}

	for(int i=1;i<=nn;i++) {
		for(const auto &P:membs[i]) {
			fadj[i].insert(ids[{P.se,P.fi}]);
		}
	}


	dfs_sz(1);
	dfsZ(1);


	for(int i=nn;i>=1;--i) printf("%d%c",col[i]," \n"[i==1]);
}