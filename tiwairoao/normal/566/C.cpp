#include <bits/stdc++.h>

const int N = 200000;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}

struct edge{int x, l;}; std::vector<edge>G[N + 5];
void adde(int u, int v, int l) {
	G[u].push_back((edge){v, l}), G[v].push_back((edge){u, l});
}

bool vis[N + 5]; int w[N + 5], n;

int hvy[N + 5], siz[N + 5];
int dfs1(int x, int fa) {
	siz[x] = 1;
	for (auto e : G[x]) if (!vis[e.x] && e.x != fa)
		siz[x] += dfs1(e.x, x);
	return siz[x];
}
int dfs2(int x, int fa, int tot) {
	int ret = 0; hvy[x] = tot - siz[x];
	for (auto e : G[x]) if (!vis[e.x] && e.x != fa) {
		int tmp = dfs2(e.x, x, tot); hvy[x] = std::max(hvy[x], siz[e.x]);
		if (!ret || hvy[tmp] < hvy[ret]) ret = tmp;
	}
	if (!ret || hvy[x] < hvy[ret]) ret = x;
	return ret;
}

double f[N + 5];
double calc(int x, int fa, int l) {
	double ret = w[x] * sqrt(l) * l;
	for (auto e : G[x]) if (e.x != fa)
		ret += calc(e.x, x, l + e.l);
	return ret;
}
double dfs3(int x, int fa, int l) {
	f[x] = w[x] * sqrt(l);
	for (auto e : G[x]) if (e.x != fa)
		f[x] += dfs3(e.x, x, l + e.l);
	return f[x];
}

int ans; double sum;
void solve(int x) {
	double k = calc(x, 0, 0);
	if (!ans || sum > k) sum = k, ans = x;

	double val = 0; vis[x] = true;
	for (auto e : G[x]) if (!vis[e.x])
		val += dfs3(e.x, x, e.l);
	for (auto e : G[x]) if (!vis[e.x])
		if (val - 2 * f[e.x] < 0) solve(dfs2(e.x, x, dfs1(e.x, x)));
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1, a, b, l; i < n; i++)
		a = read(), b = read(), l = read(), adde(a, b, l);
	solve(dfs2(1, 0, dfs1(1, 0)));
	printf("%d %.9f\n", ans, sum);
}