#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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

const int maxn = 400000 + 10;
const int maxm = 1000000 + 10;
int n, m, s, t;
pi edge[maxm];
vii adj[maxn];
vii g[maxn];
int dir[maxm];
int vis[maxn];
int lev[maxn];
pi p[maxn];
int nxt[maxn];

void dfs(int u) {
	vis[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int ix = adj[u][i].se;
		if (!vis[v]) {
			lev[v] = lev[u] + 1;
			p[v] = mp(u, ix);
			nxt[u] = v;
			dfs(v);
		}
		else if (lev[v] < lev[u]) {
			g[nxt[v]].pb(mp(u, ix));
		}
	}
}

void setedge(int from, int ix) {
	if (edge[ix].fi != from) swap(edge[ix].fi, edge[ix].se);
}

void work() {
	cin >> n >> m >> s >> t; s--, t--;
	FOR(i, 0, n) adj[i].clear(), g[i].clear();
	fill_n(vis, n, 0);
	fill_n(dir, m, -1);
	fill_n(p, n, mp(-1, -1));
	FOR(i, 0, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
		edge[i] = mp(u, v);
	}
	lev[s] = 0; dfs(s);
	if (!vis[t]) {
		cout << "No\n";
		return;
	}
	queue<pi> que;
	que.push(mp(t, 1));
	while (sz(que)) {
		int u = que.front().fi;
		int w = que.front().se;
		que.pop();
		while (p[u] != mp(-1, -1) && dir[p[u].se] == -1) {
			dir[p[u].se] = w;
			if (w) setedge(p[u].fi, p[u].se);
			else setedge(u, p[u].se);
			FOR(i, 0, sz(g[u])) {
				int v = g[u][i].fi;
				int ix = g[u][i].se;
				dir[ix] = w;
				if (w) setedge(p[u].fi, ix);
				else setedge(v, ix);
				que.push(mp(v, w ^ 1));
			}
			u = p[u].fi;
		}
	}
	FOR(i, 0, m) {
		if (dir[i] == -1) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	FOR(i, 0, m) {
		cout << edge[i].fi + 1 << " " << edge[i].se + 1 << "\n";
	}
}

void solve() {
	int test; cin >> test;
	while (test--) {
		work();
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