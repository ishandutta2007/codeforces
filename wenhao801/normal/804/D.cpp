#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

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
const int MAXN = 100100;
int n, m, q, dia[MAXN];
vector <int> E[MAXN], b[MAXN], a[MAXN];
vector <ll> sa[MAXN];
unordered_map <int, ll> sav[MAXN];

int dep[MAXN], id[MAXN], cur, f[MAXN];
void dfs (int x, int fa) {
	dep[x] = dep[fa] + 1; id[x] = cur; b[cur].push_back(x);
	for (auto i: E[x]) if (i != fa) dfs(i, x);
}
void dfs2 (int x, int fa) {
	dep[x] = dep[fa] + 1; f[x] = fa;
	for (auto i: E[x]) if (i != fa) dfs2(i, x);
}

int main () {
	n = read(), m = read(), q = read();
	int i, j;
	for (i = 1; i <= m; i++) {
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
	}
	for (i = 1; i <= n; i++) if (!id[i]) {
		++cur, dfs(i, 0); int mx = i;
		for (auto j: b[cur]) if (dep[j] > dep[mx]) mx = j;
		dfs2(mx, 0); int d = 0, now = 0;
		for (auto j: b[cur]) if (dep[j] > d) d = dep[j], now = j;
		--d; dia[cur] = d; for (j = 1; j <= d / 2; j++) now = f[now];
		if (d & 1) {
			int u = now, v = f[now];
			dep[u] = dep[v] = 0; b[cur].clear(); dfs(u, v); for (auto j: b[cur]) a[cur].push_back(((dep[j] - 1) << 1) + 1 + dia[cur]);
			dep[u] = dep[v] = 0; b[cur].clear(); dfs(v, u); for (auto j: b[cur]) a[cur].push_back(((dep[j] - 1) << 1) + 1 + dia[cur]);
			b[cur].clear(); dfs(u, 0);
		}
		else {
			dfs2(now, 0);
			for (auto j: b[cur]) a[cur].push_back(((dep[j] - 1) << 1) + dia[cur]);
		}
		sort(a[cur].begin(), a[cur].end());
		// printf("! group %d: dia = %d\n", i, dia[cur]);
		for (auto j: a[cur]) sa[cur].push_back(j); //, cout << j << ' ';
		// cout << endl;
		for (int j = ((int)a[cur].size()) - 2; j >= 0; j--) sa[cur][j] = sa[cur][j + 1] + a[cur][j];
	}
	while (q--) {
		int u = id[read()]; int v = id[read()];
		if (u == v) { puts("-1"); continue; }
		if (u > v) swap(u, v);
		if (sav[u].count(v)) { printf("%.7lf\n", 1.0 * sav[u][v] / ((ll)(b[u].size())) / ((ll)(b[v].size())) / 2); continue; }
		if (b[u].size() > b[v].size()) swap(u, v);
		ll way = 0, sum = 0;
		for (auto i: a[u]) {
			auto j = upper_bound(a[v].begin(), a[v].end(), max(dia[u], dia[v]) * 2 - i - 2);
			if (j != a[v].end()) {
				int it = j - a[v].begin();
				way += ((int)a[v].size()) - it;
				sum += sa[v][it] + (((ll)a[v].size()) - it) * i;
			}
		}
		// printf("way = %lld, sum = %lld\n", way, sum);
		if (u > v) swap(u, v);
		sav[u][v] = sum + 2ll * way + 2ll * (((ll)(b[u].size())) * ((ll)(b[v].size())) - way) * max(dia[u], dia[v]);
		printf("%.7lf\n", 1.0 * sav[u][v] / ((ll)(b[u].size())) / ((ll)(b[v].size())) / 2);
	}
	return 0;
}