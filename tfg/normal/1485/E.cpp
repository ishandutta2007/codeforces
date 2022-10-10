#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> edges(n);
	std::vector<int> a(n);
	for(int i = 1; i < n; i++) {
		int j;
		std::cin >> j;
		j--;
		edges[i].push_back(j);
		edges[j].push_back(i);
	}
	for(int i = 1; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<bool> vis(n, false);
	vis[0] = true;
	std::vector<long long> dp(n, 0);
	std::vector<int> layer(1, 0);
	const long long INF = 1e18;
	while(!layer.empty()) {
		std::vector<int> nxt;
		int mn = (int) 1.1e9 + 1, mx = -1;
		long long v1 = -INF, v2 = -INF;
		for(auto u : layer) for(auto v : edges[u]) {
			if(!vis[v]) {
				nxt.push_back(v);
				mn = std::min(mn, a[v]);
				mx = std::max(mx, a[v]);
				v1 = std::max(v1, dp[u] - a[v]);
				v2 = std::max(v2, dp[u] + a[v]);
			}
		}
		//std::cout << "at this layer got (" << mn << ", " << mx << "), (" << v1 << ", " << v2 << ")\n";
		for(auto u : layer) for(auto v : edges[u]) {
			if(!vis[v]) {
				vis[v] = true;
				dp[v] = dp[u] + std::max(std::abs(a[v] - mn), std::abs(a[v] - mx));
				dp[v] = std::max(dp[v], std::max(v1 + a[v], v2 - a[v]));
			}
		}
		nxt.swap(layer);
	}
	long long ans = 0;
	for(auto val : dp) {
		ans = std::max(ans, val);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}