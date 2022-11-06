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
void addmod(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
template<class T> void setmin(T& a, T val) {a = min(a, val);}
template<class T> void setmax(T& a, T val) {a = max(a, val);}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

#define MAXV 2010
#define MAXE 4000010
#define INF 1000000000
struct Dinic {
	int n, s, t, E, adj[MAXE], flow[MAXE], cap[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		for (int i = 0; i <= n; i++) last[i] = -1;
	}
	void add(int u, int v, int c1, int c2) {
		adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
		adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
	}
	bool bfs() {
		for (int i = 0; i <= n; i++) level[i] = -1;
		level[s] = 0;
		int qsize = 0;
		que[qsize++] = s;
		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
				int v = adj[e];
				if (flow[e] < cap[e] && level[v] == -1) {
					level[v] = level[u] + 1;
					que[qsize++] = v;
				}
			}
		}
		return level[t] != -1;
	}
	int dfs(int u, int bot) {
		if (u == t) return bot;
		for (int &e = run[u]; e != -1; e = next[e]) {
			int v = adj[e], delta = 0;
			if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
				flow[e] += delta; flow[e ^ 1] -= delta;
				return delta;
			}
		}
		return 0;
	}
	int maxflow() {
		int total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) run[i] = last[i];
			for (int delta = dfs(s, INF); delta > 0; delta = dfs(s, INF)) total += delta;
		}
		return total;
	}
} dinic;

const int maxn = 30;
int n, m, k, l;
int a[maxn][maxn];
vii cor[2];
int id[maxn][maxn];
int dis[maxn * maxn][maxn * maxn];

void solve() {
	scanf("%d%d%d%d", &n, &m, &k, &l);
	if (abs(k - l) != 1) {printf("-1"); return;}
	int d = max(k, l);
	FOR(i, 0, n) {
		char s[maxn]; scanf("%s", s);
		FOR(j, 0, m) a[i][j] = s[j] == '.';
	}
	FOR(i, 0, n) FOR(j, 0, m) id[i][j] = i * m + j;
	int r, c, t; scanf("%d%d%d", &r, &c, &t); r--; c--;
	if (k < l) cor[0].pb(mp(id[r][c], t));
	else cor[1].pb(mp(id[r][c], t));
	FOR(i, 0, k) {
		scanf("%d%d%d", &r, &c, &t); r--; c--;
		cor[0].pb(mp(id[r][c], t));
	}
	FOR(i, 0, l) {
		scanf("%d%d%d", &r, &c, &t); r--; c--;
		cor[1].pb(mp(id[r][c], t));
	}
	ms(dis, 0x3f);
	FOR(i, 0, n) FOR(j, 0, m) if (a[i][j]) {
		dis[id[i][j]][id[i][j]] = 0;
		if (i && a[i - 1][j]) {
			dis[id[i][j]][id[i - 1][j]] = 1;
		}
		if (j && a[i][j - 1]) {
			dis[id[i][j]][id[i][j - 1]] = 1;
		}
		if (a[i + 1][j]) {
			dis[id[i][j]][id[i + 1][j]] = 1;
		}
		if (a[i][j + 1]) {
			dis[id[i][j]][id[i][j + 1]] = 1;
		}
	}
	FOR(k, 0, n * m) FOR(i, 0, n * m) FOR(j, 0, n * m) {
		setmin(dis[i][j], dis[i][k] + dis[k][j]);
	}
	ll lo = 0, hi = 500LL * INF;
	while (lo < hi) {
		ll mid = (lo + hi) >> 1;
		int sr = 2 * (d + n * m), sk = 2 * (d + n * m) + 1;
		dinic.init(2 * (d + n * m) + 2, sr, sk);
		FOR(i, 0, d) {
			dinic.add(sr, i, 1, 0);
			dinic.add(i + d, sk, 1, 0);
			int u = cor[0][i].fi;
			int x = cor[0][i].se;
			int v = cor[1][i].fi;
			int y = cor[1][i].se;
			FOR(j, 0, n * m) {
				if (dis[u][j] < INF && (ll) x * dis[u][j] <= mid) {
					dinic.add(i, j + 2 * d, 1, 0);
				}
				if (dis[j][v] < INF && (ll) y * dis[j][v] <= mid) {
					dinic.add(j + 2 * d + n * m, i + d, 1, 0);
				}
			}
		}
		FOR(i, 0, n * m) {
			dinic.add(i + 2 * d, i + 2 * d + n * m, 1, 0);
		}
		if (dinic.maxflow() < d) lo = mid + 1; else hi = mid;
	}
	if (lo == 500LL * INF) lo = -1;
	printf("%I64d", lo);
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