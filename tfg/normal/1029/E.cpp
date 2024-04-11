#include <iostream>
#include <vector>

const int ms = 200200;

std::vector<int> edges[ms];
int dist[ms];
int dp[ms][4];

// 00 = off, 01 == this on, 10 == par on, 11 == par and this on
// 00 means getting at least 1 01 and rest 00
// 10 means getting 01 or 00
// 11 means getting anything
// 01 is the same as 11

void dfs(int on = 0, int par = -1) {
	int sum0 = 0;
	int sum1 = 0;
	int diff = 1e9;
	bool leaf = true;
	for(auto to : edges[on]) {
		if(to != par) {
			leaf = false;
			dist[to] = 1 + dist[on];
			dfs(to, on);
			dp[on][2] += std::min(dp[to][0], dp[to][1]);
			dp[on][1] += std::min(dp[to][1], dp[to][2]);
			diff = std::min(diff, dp[to][1] - dp[to][0]);
			sum1 += std::min(dp[to][1], dp[to][0]);
			sum0 += dp[to][0];
		}
	}
	if(leaf) {
		dp[on][1] = 1;
		dp[on][0] = 1e7;
	} else {
		if(diff <= 0) {
			dp[on][0] = sum1;
		} else {
			dp[on][0] = sum0 + diff;
		}
		dp[on][1]++;
	}
	//std::cout << "returning on " << on << ", 00 = " << dp[on][0] << ", 01 == " << dp[on][1] << ", 10 == " << dp[on][2] << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	edges[0].push_back(1);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(dist[i] == 2) {
			ans += std::min(dp[i][2], dp[i][1]);
		}
	}
	std::cout << ans << std::endl;
}