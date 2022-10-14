#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> v(n);
	for (int i = 0; i < n; i++)
		v[i].push_back(i);

	std::vector<int> par(n);
	std::iota(par.begin(), par.end(), 0);

	std::function<int(int)> root = [&](int u) {
		return par[u] == u ? u : par[u] = root(par[u]);
	};

	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		--a;
		--b;

		a = root(a);
		b = root(b);

		if (v[a].size() < v[b].size()) std::swap(a, b);

		par[b] = a;
		for (int j : v[b]) v[a].push_back(j);
	}

	for (int i = 0; i < n; i++) {
		if (v[i].size() == n)
			for (int j : v[i]) std::cout << j + 1 << " ";
	}

	return 0;
}