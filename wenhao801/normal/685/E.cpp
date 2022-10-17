#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200, inf = 1e9 + 7;
#define pii pair <int, int>
#define fr first
#define se second

int n, m, q; bool ans[MAXN];
struct qry { int r, t, id; };
pii e[MAXN];
vector <pii> E[MAXN];
vector <qry> Q[MAXN];

int f[1010][1010];

int main () {
	n = read(), m = read(), q = read(); int i, j;
	for (i = 1; i <= m; i++) {
		e[i].fr = read(), e[i].se = read();
		E[e[i].fr].emplace_back(i, e[i].se);
		E[e[i].se].emplace_back(i, e[i].fr);
	}
	for (i = 1; i <= q; i++) {
		int l = read(), r = read(), s = read(), t = read();
		auto it = lower_bound(E[s].begin(), E[s].end(), pii{l, 0});
		if (it == E[s].end()) ans[i] = 0;
		else Q[it->fr].push_back({r, t, i});
	}
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) f[i][j] = inf;
	for (i = m; i >= 1; i--) {
		const int u = e[i].fr, v = e[i].se;
		f[u][v] = f[v][u] = i;
		for (j = 1; j <= n; j++) {
			f[u][j] = f[v][j] = min(f[u][j], f[v][j]);
		}
		for (auto k: Q[i]) ans[k.id] = f[u][k.t] <= k.r;
	}
	for (i = 1; i <= q; i++) puts(ans[i] ? "Yes" : "No");
	return 0;
}