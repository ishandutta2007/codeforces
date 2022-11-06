#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
const int maxe = 20;
int n, q;
vi adj[maxn];
vi adj2[maxn];
map<pi, int> edges;
int p[maxn][maxe];
int lev[maxn];
int tin[maxn];
int tou[maxn];
int tms = 10;
int f[maxn];
int par[maxn];

void dfs(int u, int dad = -1) {
	tin[u] = tms++;
	FOR(i, 1, maxe) p[u][i] = p[p[u][i - 1]][i - 1];
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			p[v][0] = u;
			lev[v] = lev[u] + 1;
			dfs(v, u);
		}
	}
	tou[u] = tms++;
}

int isparent(int u, int v) {
	return tin[u] <= tin[v] && tou[u] >= tou[v];
}

int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	if (isparent(v, u)) return v;
	FORd(i, maxe, 0) if (lev[p[u][i]] >= lev[v]) u = p[u][i];
	FORd(i, maxe, 0) if (p[u][i] != p[v][i]) {u = p[u][i]; v = p[v][i];}
	return p[u][0];
}

void join(int u, int w) {
	if (u == w || par[u] == w) return;
	if (!~par[u]) par[u] = w;
	else {
		int v = par[u];
		if (isparent(v, w)) {
			par[u] = w;
			join(w, v);
		}
		else join(v, w);
	}
}

int dfs2(int u) {
	int res = 0, cnt = 0;
	FOR(i, 0, sz(adj2[u])) {
		int v = adj2[u][i];
		res += dfs2(v);
		cnt += f[v];
	}
	if (f[u]) return res + cnt;
	if (cnt == 1) {f[u] = 1; return res;}
	res += cnt > 0;
	return res;
}

int compare(int u, int v) {
	return tin[u] < tin[v];
}

void solve() {
	ms(par, -1);
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		edges[mp(u, v)] = edges[mp(v, u)] = 1;
	}
	adj[n].pb(0); dfs(n);
	scanf("%d", &q);
	while (q--) {
		int k; scanf("%d", &k);
		vi ver;
		FOR(i, 0, k) {
			int u; scanf("%d", &u); u--;
			ver.pb(u); f[u] = 1;
		}
		int flag = 0;
		FOR(i, 0, k) if (ver[i] && f[p[ver[i]][0]]) {
			printf("-1\n"); FOR(j, 0, k) f[ver[j]] = 0;
			flag = 1; break;
		}
		if (flag) continue;
		ver.pb(n); sort(all(ver), compare);
		vi ver2;
		FOR(i, 0, k) {
			int u = ver[i], v = ver[i + 1];
			int w = lca(u, v);
			join(u, w); join(v, w);
			ver2.pb(u); ver2.pb(v); ver2.pb(w);
		}
		sort(all(ver2)); uni(ver2);
		FOR(i, 0, sz(ver2)) {
			int u = ver2[i];
			if (~par[u]) {
				adj2[par[u]].pb(u);
			}
		}
		printf("%d\n", dfs2(n));
		FOR(i, 0, sz(ver2)) {
			int u = ver2[i];
			adj2[u].clear();
			f[u] = 0; par[u] = -1;
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}