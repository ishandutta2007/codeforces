#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> vec(n, n);
	for (int i = 0; i < k; i++) {
		int x;
		std::cin >> x;
		--x;

		vec[x] = 0;
	}

	std::vector<std::vector<int>> e(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		--u;
		--v;

		e[u].push_back(v);
		e[v].push_back(u);
	}

	std::vector<int> dp(n);
	std::function<void(int, int, int)> Dfs = [&](int u, int dep, int f) {
		int suc = 1, ch = 0;
		for (int v : e[u]) {
			if (v == f) continue;
			Dfs(v, dep + 1, u);
			vec[u] = std::min(vec[u], vec[v] + 1);
			if (dp[v] == -1) suc = 0;
			ch += dp[v];
		}
		if (dep >= vec[u]) {
			dp[u] = 1;
		} else {
			if (ch == 0 || !suc) {
				dp[u] = -1;
			} else {
				dp[u] = ch;
			}
		}
	};
	
	Dfs(0, 0, 0);

	std::cout << dp[0] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;	
}