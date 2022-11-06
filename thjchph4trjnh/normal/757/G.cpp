#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

struct CentroidTree {
	struct Info {
		long long d;
		Info() : d(0) {}
		Info(long long d) : d(d) {}
		Info(const Info& rhs) : d(rhs.d) {}
		Info operator + (const int& w) const {
			return Info(d + w);
		}
		Info operator + (const Info& rhs) const {
			return Info(d + rhs.d);
		}
	};
	
	static const int maxn = 1000000 + 10;
	static const int logn = 20;
	int n, rt;
	vector<pair<int, int> > adj[maxn];
	int size[maxn];
	int rem[maxn];
	vector<int> tree[maxn];
	int lev[maxn];
	int tin[maxn];
	int tou[maxn];
	int tms;
	int p[logn][maxn];
	Info info[logn][maxn];
	
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			tree[i].clear();
			rem[i] = 0;
		}
		tms = 0;
	}
	void add(int u, int v, int w) {
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	void dfs(int u, int p) {
		size[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i].first;
			if (v != p && !rem[v]) {
				dfs(v, u);
				size[u] += size[v];
			}
		}
	}
	int findcentroid(int u) {
		dfs(u, -1);
		int p = -1, t = size[u];
		while (1) {
			pair<int, int> best;
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i].first;
				if (v != p && !rem[v]) {
					best = max(best, make_pair(size[v], v));
				}
			}
			if (best.first + best.first <= t) {
				return u;
			}
			p = u, u = best.second;
		}
	}
	void upd(int u, int dep, int p) {
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (v != p && !rem[v]) {
				info[dep][v] = info[dep][u] + w;
				upd(v, dep, u);
			}
		}
	}
	int divide(int u, int dep) {
		lev[u = findcentroid(u)] = dep;
		tin[u] = tms++;
		p[0][u] = u;
		info[dep][u] = Info(0);
		upd(u, dep, -1);
		rem[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i].first;
			if (!rem[v]) {
				int w = divide(v, dep + 1);
				tree[u].push_back(w);
				p[0][w] = u;
			}
		}
		tou[u] = tms - 1;
		adj[u].clear();
		return u;
	}
	int lca(int u, int v) {
		if (lev[u] < lev[v]) swap(u, v);
		for (int k = logn - 1; k >= 0; k--) {
			if (lev[p[k][u]] >= lev[v]) {
				u = p[k][u];
			}
		}
		if (u == v) return u;
		for (int k = logn - 1; k >= 0; k--) {
			if (p[k][u] != p[k][v]) {
				u = p[k][u], v = p[k][v];
			}
		}
		return p[0][u];
	}
	int isparent(int u, int v) {
		return tin[u] <= tin[v] && tou[u] >= tou[v];
	}
	Info getInfo(int u, int v) {
		int a = lca(u, v);
		int ix = lev[a];
		return info[ix][u] + info[ix][v];
	}
	void build() {
		rt = divide(0, 0);
		for (int k = 1; k < logn; k++) {
			for (int u = 0; u < n; u++) {
				p[k][u] = p[k - 1][p[k - 1][u]];
			}
		}
		for (int u = 0; u < n; u++) {
			adj[u].clear();
		}
	}
} ct;

const int maxn = 1000000 + 10;
int n, q;
int p[maxn];
vii adj[maxn];
vii adj2[maxn];
int vis[maxn];

void dfs(int u) {
	vis[u] = 1;
	vii li;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		if (!vis[v]) {
			li.pb(adj[u][i]);
		}
	}
	if (sz(li) <= 2) {
		adj2[u] = li;
		
	}
	else {
		adj2[u].pb(li[0]);
		adj2[u].pb(mp(n, 0));
		FOR(i, 1, sz(li) - 1) {
			adj2[n].pb(li[i]);
			if (i < sz(li) - 2) {
				adj2[n].pb(mp(n + 1, 0));
			}
			else {
				adj2[n].pb(li[i + 1]);
			}
			n++;
		}
	}
	FOR(i, 0, sz(li)) {
		dfs(li[i].fi);
	}
}

struct Node {
	long long sum;
	int cnt;
	Node* child[3];
	Node() : sum(0), cnt(0) {}
};

inline Node* newNode() {
	return new Node;
}

Node* rt[maxn];

Node* build(int u) {
	Node* res = newNode();
	FOR(i, 0, sz(ct.tree[u])) {
		int v = ct.tree[u][i];
		res->child[i] = build(v);
	}
	return res;
}

Node* upd(int u, int v, Node* p) {
	Node* res = newNode();
	int ix = ct.lev[v];
	res->sum = p->sum + ct.info[ix][u].d;
	res->cnt = p->cnt + 1;
	if (ix) {
		res->sum -= ct.info[ix - 1][u].d;
	}
	FOR(i, 0, sz(ct.tree[v])) {
		int w = ct.tree[v][i];
		if (ct.isparent(w, u)) {
			res->child[i] = upd(u, w, p->child[i]);
		}
		else {
			res->child[i] = p->child[i];
		}
	}
	return res;
}

long long query(int u, int v, Node* p) {
	long long res = 0;
	int ix = ct.lev[v];
	res += p->sum;
	res += p->cnt * ct.info[ix][u].d;
	FOR(i, 0, sz(ct.tree[v])) {
		int w = ct.tree[v][i];
		if (ct.isparent(w, u)) {
			res += query(u, w, p->child[i]);
			res -= p->child[i]->cnt * ct.info[ix][u].d;
		}
	}
	return res;
}

void solve() {
	cin >> n >> q;
	FOR(i, 0, n) cin >> p[i], p[i]--;
	FOR(i, 0, n - 1) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	dfs(0);
	ct.init(n);
	FOR(u, 0, n) {
		FOR(i, 0, sz(adj2[u])) {
			int v = adj2[u][i].fi;
			int w = adj2[u][i].se;
			ct.add(u, v, w);
		}
		adj[u].clear();
		adj2[u].clear();
	}
	ct.build();
	rt[0] = build(ct.rt);
	FOR(i, 0, n) {
		rt[i + 1] = upd(p[i], ct.rt, rt[i]);
	}
	long long ans = 0;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int a, b, c; cin >> a >> b >> c;
			int l = (ans % (1 << 30)) ^ a;
			int r = (ans % (1 << 30)) ^ b;
			int v = (ans % (1 << 30)) ^ c;
			v--;
			ans = query(v, ct.rt, rt[r]) - query(v, ct.rt, rt[l - 1]);
			cout << ans << "\n";
		}
		else {
			int a; cin >> a;
			int x = (ans % (1 << 30)) ^ a;
			swap(p[x - 1], p[x]);
			rt[x] = upd(p[x - 1], ct.rt, rt[x - 1]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}