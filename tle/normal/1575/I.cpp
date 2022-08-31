//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
int dfn[maxn], sz[maxn], w[maxn];
ll d[maxn];
vi eg[maxn];
int lb(int x) {
	return x & -x;
}
ll q(int x) {
	ll ans = 0;
	while (x) ans += d[x], x -= lb(x);
	return ans;
}
void upd(int p, int x) {
	while (p < maxn)	
		d[p] += x, p += lb(p);
}
int fa[maxn][20];
int dep[maxn];
int dfcnt = 0;
void dfs(int a) {
	dfn[a] = ++dfcnt; sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa[a][0]) continue;
		dep[v] = dep[a] + 1;
		fa[v][0] = a;
		for (int j = 1; j < 20; j++)
			fa[v][j] = fa[fa[v][j - 1]][j - 1];
		dfs(v); sz[a] += sz[v];
	}
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	if (a != b) a = fa[a][0];
	return a;
}
void chd(int x, int y) {
	y = abs(y);
	upd(dfn[x], y - w[x]), upd(dfn[x] + sz[x], w[x] - y);
	w[x] = y;
}
ll qr(int a, int b) {
	if (a == b) return 0;
	int lc = lca(a, b);
	ll ans = q(dfn[a]) + q(dfn[b]) - q(dfn[lc]) - q(dfn[fa[lc][0]]);
	ans *= 2; ans -= w[a] + w[b];
	return ans;
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int c; scanf("%d", &c); w[i] = c;
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	dep[1] = 1, dfs(1);
	for (int i = 1; i <= n; i++) {
		int c = w[i]; w[i] = 0; chd(i, c);
	}
	for (int i = 1; i <= q; i++) {
		int t, u, c;
		scanf("%d%d%d", &t, &u, &c);
		if (t == 1) chd(u, c);
		else printf("%lld\n", qr(u, c));
	}
    return (0-0); //<3
}