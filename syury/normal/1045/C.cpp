#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = 5e5 + 5;
const int lg = 20;

vector<int> gr[maxn];
int n, m, q;
int color[maxn];
int tin[maxn], fup[maxn];
bool used[maxn];
int tout[maxn];
int currt = 0, ccol = 0;
vector<pii> edges;
set<int> cols[maxn];
vector<int> cgr[maxn];
int h[maxn];
int up[maxn][lg];

int nxt(int v, int i){
	return v == edges[i].X ? edges[i].Y : edges[i].X;
}

void dfs(int v, int par = -1){
	tin[v] = currt++;
	fup[v] = tin[v];
	I(i, gr[v]){
		int u = nxt(v, i);
		if(i == par)cont;
		if(tin[u] != -1){
			fup[v] = min(fup[v], tin[u]);
		}
		else{
			dfs(u, i);
			fup[v] = min(fup[v], fup[u]);
		}
	}
}

void paint(int v, int col, int par){
	used[v] = true;
	I(i, gr[v]){
		if(i == par)cont;
		int u = nxt(v, i);
		if(!used[u]){
			if(fup[u] >= tin[v]){
				int nc = ccol++;
				color[i] = nc;
				paint(u, nc, i);
			}
			else{
				color[i] = col;
				paint(u, col, i);
			}
		}
		else if(tin[u] < tin[v]){
			color[i] = col;
		}
	}
}

void prepare(int v, int pp = -1){
	tin[v] = currt++;
	if(pp == -1)h[v] = 0;
	else h[v] = h[pp] + 1;
	if(pp == -1)pp = v;
	up[v][0] = pp;
	F(i, 1, lg)up[v][i] = up[up[v][i - 1]][i - 1];
	I(u, cgr[v]){
		if(u == pp)cont;
		prepare(u, v);
	}
	tout[v] = currt++;
}

inline bool ispr(int v, int u){
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

inline int lca(int v, int u){
	if(ispr(v, u))ret v;
	if(ispr(u, v))ret u;
	DF(i, lg - 1, 0){
		int w = up[v][i];
		if(!ispr(w, u))v = w;
	}
	ret up[v][0];
}

int main() {
    sync;
	cin >> n >> m >> q;
	F(i, 0, m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		gr[v].pb(i);
		gr[u].pb(i);
		edges.pb(mp(v, u));
	}
	fill(tin, tin + n, -1);
	dfs(0);
	fill(color, color + m, -1);
	paint(0, ccol, -1);
	F(i, 0, m){
		int v = edges[i].X, u = edges[i].Y;
		cols[v].insert(color[i]);
		cols[u].insert(color[i]);
	}
	F(i, 0, n){
		I(j, cols[i]){
			cgr[j + n].pb(i);
			cgr[i].pb(j + n);
		}
	}
	currt = 0;
	prepare(0);
	F(i, 0, q){
		int v, u;
		cin >> v >> u;
		--v; --u;
		int w = lca(v, u);
		int ans = h[v] + h[u] - 2 * h[w];
		cout << ans/2 << '\n';
	}
}