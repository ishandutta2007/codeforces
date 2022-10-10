#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> edges(n);
	while(m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;v--;
		edges[u].emplace_back(v, w);
	}
	std::vector<int> cost(1 << n, 0), reach(1 << n, 0);
	for(int i = 1; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) if((i & (1 << j)) == 0) {
			for(auto e : edges[j]) if((i & (1 << e.first))) {
				cost[i] += e.second;
			}
		}
		for(int j = 0; j < n; j++) if((i & (1 << j)) != 0) {
			for(auto e : edges[j]) {
				reach[i] |= 1 << e.first;
			}
		}
	}
	std::vector<int> dp(1 << n, 1e9), frm(1 << n, -1);
	dp[0] = 0;
	for(int mask = 1; mask < (1 << n); mask++) {
		for(int submask = mask; submask > 0; submask = (submask - 1) & mask) {
			if((reach[submask] & (mask ^ submask)) == reach[submask] && dp[mask] > dp[mask ^ submask] + cost[mask]) {
				dp[mask] = dp[mask ^ submask] + cost[mask];
				frm[mask] = submask;
			}
		}
	}
	assert(frm.back() != -1);
	std::vector<int> ans(1 << n, -1);
	for(int mask = (1 << n) - 1, id = n+1; mask > 0; mask ^= frm[mask], id--) {
		for(int i = 0; i < n; i++) if(mask & (1 << i)) ans[i] = id;
	}
	for(int i = 0; i < n; i++) std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
}