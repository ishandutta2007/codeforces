// Ko hoce da radimo icpc na cfu / bubble cup sledece godine nek se javi na cfu
#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	std::vector<std::vector<int>> e(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--u;
		--v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	std::vector<bool> was(n, false);
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (was[i]) continue;

		was[i] = true;

		std::vector<int> reach;
		reach.push_back(i);
		for (int j = 0; j < reach.size(); j++) {
			for (int to : e[reach[j]]) {
				if (!was[to]) {
					reach.push_back(to);
					was[to] = true;
				}
			}
		}

		std::sort(reach.begin(), reach.end());

		auto vals = reach;
		std::sort(vals.begin(), vals.end(), [&](int i, int j) {
			return a[i] > a[j];
		});

		for (int j = 0; j < reach.size(); j++)
			ans[reach[j]] = a[vals[j]];
	}

	for (int i = 0; i < n; i++)
		std::cout << ans[i] << " ";

	return 0;
}