#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m, n;
	std::cin >> m >> n;
	std::vector<int> groups(m, -1);
	std::vector<std::vector<int>> a(n);
	int ans = 0;
	for(int i = 0; i < m; i++) {
		std::cin >> groups[i];
		groups[i]--;
		a[groups[i]].push_back(i);
		if(i && groups[i] != groups[i-1]) {
			ans++;
		}
	}
	auto f = [&](int i) {
		int got = 0;
		if(i && groups[i] != groups[i-1]) got++;
		if(i+1 < m && groups[i] != groups[i+1]) got++;
		return got;
	};
	auto makeUnion = [&](int u, int v) {
		bool change = false;
		if(a[u].size() < a[v].size()) {
			std::swap(u, v);
			change = true;
		}
		int g = groups[a[u][0]];
		for(auto id : a[v]) {
			ans -= f(id);
			groups[id] = g;
			ans += f(id);
			a[u].push_back(id);
		}
		if(change) {
			a[u].swap(a[v]);
		}
	};
	std::cout << ans << '\n';
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		makeUnion(u, v);
		std::cout << ans << '\n';
	}
}