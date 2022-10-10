#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

long long dp[ms][4];
std::vector< std::pair<int, int> > edges[ms];

long long ans = 0;

void dfs(int on, int par) {
	dp[on][0] = 1;
	//std::cout << "in " << on << "\n";
	for(auto e : edges[on]) {
		int to = e.first;
		int c = e.second;
		if(to == par) continue;
		dfs(to, on);
		if(c == 0) {
			// here to there
			ans += dp[on][0] * (dp[to][0] + dp[to][2] + dp[to][3]);
			// there to here
			ans += dp[to][0] * (dp[on][0] + dp[on][2] + dp[on][3]);
			dp[on][0] += dp[to][0];
			// fix dp[2]
			dp[on][2] += dp[to][2] + dp[to][3];
		} else {
			// here to there
			ans += (dp[on][0] + dp[on][1]) * (1 + dp[to][3]);
			// there to here
			ans += (dp[to][0] + dp[to][1]) * (dp[on][3] + 1);
			dp[on][1] += dp[to][0] + dp[to][1];
			// fix dp[3]
			dp[on][3] += 1 + dp[to][3];
		}
		//std::cout << "ans is " << ans << " after edge (" << on << ", " << to << ") got (" << dp[on][0] << ", " << dp[on][1] << ")\n";
	}
	//std::cout << "out " << on << " (" << dp[on][0] << ", " << dp[on][1] << ")\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
	}
	dfs(1, -1);
	std::cout << ans << '\n';
}