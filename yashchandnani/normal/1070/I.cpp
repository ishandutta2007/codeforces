#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
bool dfs(int a, int layer, const vector<vi>& g, vi& btoa,
			vi& A, vi& B) {
	if (A[a] != layer) return 0;
	A[a] = -1;
	trav(b, g[a]) if (B[b] == layer + 1) {
		B[b] = -1;
		if (btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(const vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), -1);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		trav(a, btoa) if(a != -1) A[a] = -1;
		rep(a,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay += 2) {
			bool islast = 0;
			next.clear();
			trav(a, cur) trav(b, g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && B[b] == -1) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			trav(a, next) A[a] = lay+1;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,sz(g)) {
			if(dfs(a, 0, g, btoa, A, B))
				++res;
		}
	}
}
vector<vi> g,g2;
vi d;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	g.clear();
	vi d(n,0);
	vector<pii> ed,rg(n);
	rep(i,m){
		int u,v;cin>>u>>v;
		u--,v--;
		ed.pb(mp(u,v));
		d[u]++;d[v]++;
	}
	int cnt = 0;
	rep(i,n){
		if(d[i]-k>0){
			rg[i] = mp(cnt,cnt+2*(d[i]-k)-1);
			cnt+=2*(d[i]-k);
		}
		else rg[i] = mp(0,-1);
	}
	if(cnt>m){
		rep(i,m) cout<<0<<' ';
		cout<<'\n';
		return;
	}
	g.resize(cnt+m);
	rep(i,m){
		repA(j,rg[ed[i].fst].fst,rg[ed[i].fst].snd) g[i+cnt].pb(j),g[j].pb(i+cnt);
		repA(j,rg[ed[i].snd].fst,rg[ed[i].snd].snd) g[i+cnt].pb(j),g[j].pb(i+cnt);
	}
	vi btoa(cnt+m,-1);
	int x = hopcroftKarp(g,btoa);
	vi ans(m,0);
	if(x!=2*cnt) {
		rep(i,m) cout<<0<<' ';
		cout<<'\n';
		return;
	}
	int val = 1;
	rep(i,n){
		repA(j,rg[i].fst,rg[i].snd){
			val++;
			ans[btoa[j]-cnt] = val/2;
		}
	}
	rep(i,m) if(ans[i]) cout<<ans[i]<<' '; else cout<<(++val)/2<<' ';
	cout<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	
	return 0;
}