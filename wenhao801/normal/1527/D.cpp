#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
const int MAXN = 200200;
int n, U, V; vector <int> E[MAXN];

int siz[MAXN], fa[MAXN][22], dep[MAXN]; ll ans[MAXN];
void pre (int x, int f) {
	siz[x] = 1, dep[x] = dep[f] + 1, fa[x][0] = f;
	for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (auto i: E[x]) if (i != f) pre(i, x), siz[x] += siz[i];
}
int lca (int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int dis (int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
int qwq (int u) { for (int i = 20; i >= 0; i--) if (dep[fa[u][i]] >= 2) u = fa[u][i]; return u; }

int main () {
	int T = read();
	while (T--) {
		int n = read(), i, j;
		for (i = 1; i <= n; i++) for (j = 0; j <= 20; j++) fa[i][j] = 0;
		for (i = 1; i <= n; i++) E[i].clear(), ans[i] = dep[i] = siz[i] = 0;
		for (i = 1; i < n; i++) {
			int u = read() + 1, v = read() + 1;
			E[u].push_back(v), E[v].push_back(u);
		}
		ans[0] = ans[1] = 1ll * n * (n - 1) / 2; pre(1, 0);
		for (auto v: E[1]) ans[1] -= 1ll * siz[v] * (siz[v] - 1) / 2;
		int U = 1, V = 2;
		i = qwq(2); ans[2] = 1ll * siz[2] * (n - siz[i]);
		for (i = 3; i <= n; i++) {
			if (U > V) swap(U, V);
			int disiu = dis(i, U), disiv = dis(i, V), disuv = dis(U, V);
			if (disiu + disuv == disiv) U = i, ans[i] = 1ll * siz[U] * siz[V];
			else if (disiv + disuv == disiu) V = i, ans[i] = 1ll * (U == 1 ? (n - siz[qwq(V)]) : siz[U]) * siz[V];
			else if (disiu + disiv == disuv) { ans[i] = ans[i - 1]; }
			else {
				while (i <= n) ans[i++] = 0;
				break;
			}
		}
		for (i = 0; i < n; i++) printf("%lld ", ans[i] - ans[i + 1]);
		printf("%lld\n", ans[n]);
	}
	return 0;
}