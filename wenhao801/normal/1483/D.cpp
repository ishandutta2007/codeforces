#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

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
const int MAXN = 606;
const ll inf = 1e16;
struct ep { int u, v, w; } E[MAXN * MAXN];
int n, m, q;
ll dis[MAXN][MAXN], f[MAXN][MAXN];

int main () {
	n = read(), m = read(); int i, j, k;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) f[i][j] = -1;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) if (i != j) dis[i][j] = inf;
	for (i = 1; i <= m; i++) {
		E[i].u = read(), E[i].v = read(), E[i].w = read();
		dis[E[i].u][E[i].v] = min(dis[E[i].u][E[i].v], (ll) E[i].w);
		dis[E[i].v][E[i].u] = min(dis[E[i].v][E[i].u], (ll) E[i].w);
	}
	for (k = 1; k <= n; k++) for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	q = read();
	while (q--) {
		int u = read(), v = read(), l = read();
		for (i = 1; i <= n; i++) {
			f[i][v] = max(f[i][v], l - dis[u][i]);
			f[i][u] = max(f[i][u], l - dis[v][i]);
		}
	}
	int ans = 0;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (f[E[i].u][j] >= E[i].w + dis[E[i].v][j]) break;
			if (f[E[i].v][j] >= E[i].w + dis[E[i].u][j]) break;
		}
		if (j <= n) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}