#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

/*
3 - 4 - 5
*/

const int ms = 300100;

int a[ms];
std::vector<std::pair<int, int>> edges[ms];

long long ans = 0;

long long dfs(int on, int par) {
	long long larg = a[on];
	for(auto to : edges[on]) {
		if(to.first == par) continue;
		long long down = dfs(to.first, on) - to.second;
		ans = std::max(ans, larg + down);
		down += a[on];
		larg = std::max(larg, down);
	}
	ans = std::max(ans, larg);
	return larg;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
	}
	dfs(0, -1);
	std::cout << ans << '\n';
}