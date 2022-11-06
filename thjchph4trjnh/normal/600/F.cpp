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
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 2010;
int a, b, m;
vii edges;
int d[maxn];
int g[maxn][maxn];
int ans[maxn][maxn];
int vis[maxn][maxn];

void join(int u, int v, int c) {
	int old = ans[u][v];
	if (old) {
		if (g[u][old] == v) g[u][old] = 0;
		if (g[v][old] == u) g[v][old] = 0;
	}
	g[u][c] = v; g[v][c] = u;
	ans[u][v] = ans[v][u] = c;
}

void solve() {
	scanf("%d%d%d", &a, &b, &m);
	int D = 0;
	FOR(i, 0, m) {
		int u, v; scanf("%d%d", &u, &v); v += a;
		edges.pb(mp(u, v));
		D = max(D, ++d[u]);
		D = max(D, ++d[v]);
	}
	FOR(i, 0, m) {
		int u = edges[i].fi;
		int v = edges[i].se;
		int flag = 0;
		FOR(j, 1, D + 1) if (!g[u][j] && !g[v][j]) {
			join(u, v, j);
			flag = 1;
			break;
		}
		if (!flag) {
			int c[2];
			FOR(j, 1, D + 1) {
				if (g[u][j] && !g[v][j]) c[0] = j;
				if (!g[u][j] && g[v][j]) c[1] = j;
			}
			int cur = v, cnt = 1;
			vi t;
			while (1) {
				t.pb(cur);
				int nxt = g[cur][c[cnt]];
				if (!nxt || vis[cur][nxt]) break;
				vis[cur][nxt] = 1;
				cur = nxt; cnt ^= 1;
			}
			cnt = 0;
			FOR(j, 0, sz(t) - 1) {
				join(t[j], t[j + 1], c[cnt]);
				vis[t[j]][t[j + 1]] = 0;
				cnt ^= 1;
			}
			join(u, v, c[1]);
		}
	}
	printf("%d\n", D);
	FOR(i, 0, m) {
		int u = edges[i].fi;
		int v = edges[i].se;
		printf("%d ", ans[u][v]);
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}