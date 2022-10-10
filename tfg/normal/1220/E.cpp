#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];
int low[ms], height[ms];
long long dp[ms][2], w[ms];

void add(long long a[2], long long x) {
	if(x >= a[0]) {
		a[1] = a[0];
		a[0] = x;
	} else if(x >= a[1]) {
		a[1] = x;
	}
}
long long ans = 0;
bool good[ms];

void dfs(int on, int par, int h = 1) {
	low[on] = h;
	height[on] = h;
	for(auto to : edges[on]) {
		if(to == par) continue;
		if(low[to] != 0) {
			low[on] = std::min(low[on], height[to]);
			if(low[on] < h || good[to]) {
				good[on] = true;
			}
		} else {
			dfs(to, on, h + 1);
			low[on] = std::min(low[on], low[to]);
			if(low[to] > h && !good[to]) {
				// is bridge!
				//std::cout << on+1 << ", " << to+1 << " is bridge\n";
				add(dp[on], dp[to][0] + w[to]);
			} else {
				// not bridge
				w[on] += w[to];
				add(dp[on], dp[to][0]);
				add(dp[on], dp[to][1]);
				good[on] = true;
			}
		}
	}
	//std::cout << "at " << on + 1 << " got " << w[on] << ", " << dp[on][0] << ", " << dp[on][1] << '\n';
	ans = std::max(ans, dp[on][0] + dp[on][1] + w[on]);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int s;
	std::cin >> s;
	dfs(--s, -1);
	ans = dp[s][0] + w[s];
	std::cout << ans << '\n';
}