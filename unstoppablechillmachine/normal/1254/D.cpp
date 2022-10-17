#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 2e5 + 10;
const int LOG = 18;
const int MOD = 998244353;
const ll MOD2 = MOD * 1ll * MOD;
const int B = 2250;
inline int add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline void add2(ll &a, ll b) {
	a += b;
	if (a >= MOD2) {
		a -= MOD2;
	}
}

inline void sub(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

inline int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b  & 1) {
		return mult(b_pow(a, b - 1), a);
	}
	return b_pow(mult(a, a), b >> 1);
}

vector<int> g[N];
int ver[N], on_path[N], flex[N], in[N], n, root;
vector<pair<int, int>> que;
vector<int> order;

mt19937 rnd(228);

int up[N][LOG], tin[N], tout[N], h[N], sz[N], timer;
int pr[N];
void dfs(int v, int p = 0, int curh = 0) {
	up[v][0] = (p ? p : v);
	tin[v] = timer++;
	order.pb(v);
	sz[v] = 1;
	h[v] = curh;
	pr[v] = p;
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v, curh + 1);
			sz[v] += sz[u];
		}
	}
	tout[v] = timer++;
}

inline void rebuild() {
	for (int i = 1; i <= n; i++) {
		in[i] = 0;
		flex[i] = 0;
		on_path[i] = 0;
	}
	int all = 0;
	for (auto it : que) {
		add(all, mult(sz[it.F], it.S));
		add(in[it.F], it.S);
	}
	que = {};
	on_path[root] = mult(in[root], n);
	for (int v : order) {
		add(ver[v], all);
		sub(ver[v], on_path[v]);
		add(ver[v], flex[v]);
		add(ver[v], mult(in[v], n));
		for (auto u : g[v]) {
			on_path[u] = on_path[v];
			add(on_path[u], mult(in[u], sz[u]));
			flex[u] = flex[v];
			add(flex[u], mult(n - sz[u], in[v]));	
		}
	}	
}

inline bool anc(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

inline int go_up(int a, int h) {
	for (int i = LOG - 1; i >= 0; i--) {
		if ((h >> i) & 1) {
			a = up[a][i];
		}
	}
	return a;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	root = rnd() % n + 1;
	dfs(root);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
	int invN = b_pow(n, MOD - 2);
	for (int i = 0; i < m; i++) {
		if (SZ(que) == B) {
			rebuild();
		}
		int type;
		cin >> type;
		if (type == 1) {
			int v, d;	
			cin >> v >> d;
			que.pb({v, d});
		}
		else {
			int v;
			cin >> v;
			int ans = ver[v];
			ll kek = 0;
			for (auto it : que) {
				if (it.F == v) {
					add2(kek, it.S * 1ll * n);
				}
				else if (anc(v, it.F)) {
					add2(kek, it.S * 1ll * sz[it.F]);
				}
				else if (anc(it.F, v)) {
					int to;
					if (SZ(g[it.F]) < LOG) {
						for (auto u : g[it.F]) {
							if (u != pr[it.F] && anc(u, v)) {
									to = u;
								break;
							}
						}
					}
					else {
						to = go_up(v, h[v] - h[it.F] - 1);
					}
					add2(kek, it.S * 1ll * (n - sz[to]));
					//add(ans, mult(it.S, n - sz[to]));
				}
				else {
					add2(kek, it.S * 1ll * sz[it.F]);
					//add(ans, mult(it.S, sz[it.F]));
				}
			}
			add(ans, kek % MOD);
			cout << mult(ans, invN) << '\n';
		}
	}
}