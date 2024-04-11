#include <bits/stdc++.h>

using i64 = long long;

const int N = 2E5 + 5;

struct FenwickTree {
	i64 fenw[N];
	void modify(int x, int y) {
		for (int i = x; i < N; i += i & -i) {
			fenw[i] += y;
		}
	}
	i64 get(int x) {
		i64 res = 0;
		for (int i = x; i > 0; i -= i & -i) {
			res += fenw[i];
		}
		return res;
	}
} fenw;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> e(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	std::vector<int> tin(n), tout(n);
	int T = 0;
	std::vector<std::vector<int>> par(n, std::vector<int>(20, -1));
	std::function<void(int, int)> dfs = [&](int u, int f) {
		tin[u] = ++T;
		par[u][0] = f;
		for (int i = 1; i < 20; i++) {
			if (par[u][i - 1] != -1) {
				par[u][i] = par[par[u][i - 1]][i - 1];
			}
		}
		for (int v : e[u]) {
			if (v == f) continue;
			dfs(v, u);
		}
		tout[u] = ++T;
	};

	std::function<bool(int, int)> anc = [&](int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; };

	std::function<int(int, int)> lca = [&](int u, int v) {
		if (anc(u, v)) return u;
		if (anc(v, u)) return v;
		for (int i = 19; i >= 0; i--) {
			if (!anc(par[u][i], v)) {
				u = par[u][i];
			}
		}
		if (u != v) u = par[u][0];
		return u;
	};

	dfs(0, 0);

	for (int i = 0; i < n; i++) {
		fenw.modify(tin[i], abs(a[i]));
		fenw.modify(tout[i] + 1, -abs(a[i]));
	}

	while (q--) {
		int t;
		std::cin >> t;
		if (t == 1) {
			int u, c;
			std::cin >> u >> c;
			--u;
			fenw.modify(tin[u], -abs(a[u]));
			fenw.modify(tout[u] + 1, abs(a[u]));
			a[u] = c;	
			fenw.modify(tin[u], abs(a[u]));
			fenw.modify(tout[u] + 1, -abs(a[u]));
		} else {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			if (u == v) {
				std::cout << "0\n";
				continue;
			}
			int l = lca(u, v);
			std::cout << 2 * (fenw.get(tin[u]) + fenw.get(tin[v]) - fenw.get(tin[l]) - (l != 0 ? fenw.get(tin[par[l][0]]) : 0)) - abs(a[u]) - abs(a[v]) << "\n";
		}
	}

	return 0;
}