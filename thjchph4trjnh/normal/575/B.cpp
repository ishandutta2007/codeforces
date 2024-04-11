#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
const int mod = 1000000007;
const int maxe = 20;
int n;
vii adj[maxn];
int price[maxn];
int sum[2][maxn];
int ntra[2][maxn];
ll ans;

int vis[maxn];
int lev[maxn];
int p[maxe][maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs1(int u) {
	tin[u] = tms++;
	vis[u] = 1;
	FOR(i, 1, maxe) p[i][u] = p[i - 1][p[i - 1][u]];
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].first;
		if (!vis[v]) {
			p[0][v] = u; lev[v] = lev[u] + 1; dfs1(v);
		}
	}
	tou[u] = tms++;
}

void dfs2(int u) {
	vis[u] = 1;
	ntra[0][u] = sum[0][u];
	ntra[1][u] = sum[1][u];
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].first;
		if (!vis[v]) {
			price[v] = adj[u][i].second;
			dfs2(v);
			ntra[0][u] += ntra[0][v];
			ntra[1][u] += ntra[1][v];
		}
	}
}

int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	if (tin[v] <= tin[u] && tou[v] >= tou[u]) return v;
	FORd(i, maxe, 0) if (lev[u] - (1 << i) >= lev[v]) u = p[i][u];
	FORd(i, maxe, 0) if (p[i][u] != p[i][v]) {u = p[i][u]; v = p[i][v];}
	return p[0][u];
}

ll ex(ll n, ll k) {
         if (k < 0) return 0;
	if (k == 0) return 1;
	if (k & 1) return n * ex(n, k - 1) % mod;
	ll t = ex(n, k >> 1);
	return t * t % mod;
}

void solve() {
	ms(sum, 0); ms(ntra, 0); ms(vis, 0); ms(lev, 0); ms(p, -1); ms(tin, 0); ms(tou, 0); tms = 0;
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w); x--; y--;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, -w));
	}
	dfs1(0);
	int k; scanf("%d", &k);
	int prev = 0;
	FOR(i, 0, k) {
		int s; scanf("%d", &s); s--;
		int a = lca(prev, s);
		sum[0][a]--; sum[0][prev]++;
		sum[1][a]--; sum[1][s]++;
		prev = s;
	}
	ms(vis, 0); dfs2(0);
	ll ans = 0;
	FOR(i, 1, n) {
		if (price[i] == 1) ans = (ans + ex(2, ntra[0][i]) - 1) % mod;
		else if (price[i] == -1) ans = (ans + ex(2, ntra[1][i]) - 1) % mod;
	}
	printf("%I64d", ans);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}