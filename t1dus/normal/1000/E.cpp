/*input
4 3
1 2
4 3
3 2
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define WL(t) while(t --)

int n,m;
vector<pii> g[300005];
vi adj[300005];
bitset<300005> brid,vis;
int disc[300005],low[300005];
int comp[300005],cmp,tim;
queue<int> Q[300005];
int ind,mx;

void dfs_bridges(int s,int p = -1){
	vis[s] = 1;
	disc[s] = low[s] = tim++;
	for(auto u:g[s]){
		if(u.F == p) continue;
		if(vis[u.F]){
			remin(low[s],disc[u.F]);
		}
		else{
			dfs_bridges(u.F,s);
			remin(low[s],low[u.F]);
			if(low[u.F] > disc[s]) brid[u.S] = 1;
		}
	}	
}

void dfs_build(int s){
	vis[s] = 1;
	while(Q[cmp].size()) Q[cmp].pop();
	Q[cmp].push(s);
	comp[s] = cmp++;
	while(!Q[comp[s]].empty()){
		int u = Q[comp[s]].front();
		Q[comp[s]].pop();
		for(auto v:g[u]){
			if(vis[v.F]) continue;
			if(brid[v.S]){
				dfs_build(v.F);
				adj[comp[s]].pb(comp[v.F]);
				adj[comp[v.F]].pb(comp[s]);
			}
			else{
				comp[v.F] = comp[s];
				Q[comp[s]].push(v.F);
				vis[v.F] = 1;
			}
		}
	}
}

void calc(int s,int p,int d){
	if(d > mx) mx = d,ind = s;
	for(auto x:adj[s]){
		if(x != p) calc(x,s,d+1);
	}
}

void solve(){
	REP(i,n+2) g[i].clear(),adj[i].clear();
	cin >> n >> m;
	cmp = 0;
	tim = 0;
	brid.reset();
	vis.reset();
	REP(i,m){
		int u,v; cin >> u >> v;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	dfs_bridges(1);
	vis.reset();
	dfs_build(1);
	ind = 0;
	mx = 0;
	calc(0,-1,0);
	mx = 0;
	calc(ind,-1,0);
	cout << mx << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	t = 1;
	WL(t) solve();
}