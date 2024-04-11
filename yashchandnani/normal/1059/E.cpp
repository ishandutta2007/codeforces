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
#define fill(a)  memset(a, 0, sizeof (a))
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

void solve(){


}
ll w[100009];
vi p;
vector<vi> treeJump(vi& P){
	int on = 1, d = 1;
	while(on < sz(P)) on *= 2, d++;
	vector<vi> jmp(d, P);
	repA(i,1,d-1) rep(j,sz(P))
		jmp[i][j] = jmp[i-1][jmp[i-1][j]];
	return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
	rep(i,sz(tbl))
		if(steps&(1<<i)) nod = tbl[i][nod];
	return nod;
}
typedef vector<pii> vpi;
typedef vector<vpi> graph;
const pii inf(1 << 29, -1);

template <class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,depth-1) rep(j,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep =  31- __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	vi time;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll> > q(1);
		vpi ret;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};
graph g;
int ans,n,l;
ll s;
int val[100009];
void dfs(int v,LCA& lca,vector<vi>& tbl){
	trav(i,g[v]){
		dfs(i.fst,lca,tbl);
		val[v] = max(val[i.fst],val[v]);
	}
	if(val[v]==0){
		ans++;
		int lo = 1,hi = l;
		while(lo<hi){
			int m = (lo+hi)/2;
			m++;
			if(lca.distance(v,jmp(tbl,v,m))<=s) lo = m;
			else hi = m-1;
		}
		val[v] = lo-1;
	}
	else val[v] -=1;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n>>l>>s;
	l = min(l,n);
	n++;
	g.resize(n);
	bool fg =0;
	repA(i,1,n-1) cin>>w[i];
	rep(i,n) if(w[i]>s) fg=1;
	if(fg){
		cout<<-1;
		exit(0);
	}
	p.resize(n,0);
	repA(i,1,n-1) {
		if(i>1) cin>>p[i];
		g[p[i]].pb(mp(i,w[i]));
	}
	vector<vi> tbl = treeJump(p);
	LCA lca(g);
	dfs(1,lca,tbl);
	cout<<ans;
	return 0;
}