#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int k;
std::vector<std::pair<int, int>> edges[500500];
long long dp[500500][2];

void dfs(int on, int par) {
	dp[on][0] = dp[on][1] = 0;
	long long sum = 0;
	std::vector<long long> costs;
	for(auto e : edges[on]) {
		if(e.first == par) continue;
		dfs(e.first, on);
		costs.push_back(std::max(0LL, e.second + dp[e.first][1] - dp[e.first][0]));
		sum += dp[e.first][0];
	}
	std::sort(costs.rbegin(), costs.rend());
	while((int) costs.size() > k) {
		costs.pop_back();
	}
	long long haha = 0;
	for(auto v : costs) haha += v;
	dp[on][0] = sum + haha;
	dp[on][1] = sum + haha - ((int) costs.size() == k ? costs.back() : 0);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n >> k;
		for(int i = 0; i < n; i++) {
			edges[i].clear();
		}
		for(int i = 1; i < n; i++) {
			int u, v, c;
			std::cin >> u >> v >> c;
			u--;v--;
			edges[u].emplace_back(v, c);
			edges[v].emplace_back(u, c);
		}
		dfs(0, -1);
		std::cout << dp[0][0] << '\n';
	}
}