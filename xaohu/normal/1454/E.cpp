#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 1 << 18;

int t, n, vis[N], dep[N], p[N];
vector<vector<int>> g;
vector<int> cycle;

void dfs(int v) {
	vis[v] = 1;
	for (auto u : g[v]) {
		if (vis[u] && dep[u] < dep[v] - 1 && cycle.empty()) {
			int a = v;
			while (a != u) {
				cycle.push_back(a);
				a = p[a];
			}
			cycle.push_back(u);
		}
		if (!vis[u]) {
			p[u] = v;
			dep[u] = dep[v] + 1;
			dfs(u);
		}
	}
}		

int siz(int v, int p) {
	int sz = 1;
	for (auto u : g[v])
		if (!vis[u] && u != p)
			sz += siz(u, v);
	return sz;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cycle.clear();
		g.clear();
		g.resize(n);
		fill(vis, vis + n, 0);
		for (int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0);
		fill(vis, vis + n, 0);
		for (auto v : cycle)	
			vis[v] = 1;
		ll res = 0;
		for (auto v : cycle) {
			int cnt = siz(v, v);
			res += 1LL * cnt * (cnt - 1);
			res += 2LL * cnt * (n - cnt);
		}
		printf("%lld\n", res / 2);
	}
	
	return 0;
}