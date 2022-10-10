#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 998244353;
const int ms = 300300;

std::vector<int> edges[ms];
long long dp[ms][3];

void dfs(int on, int par) {
	dp[on][0] = dp[on][2] = 1;
	for(auto to : edges[on]) {
		if(to == par) continue;
		dfs(to, on);
		long long nxt[2] = {0, 0};
		// transition getting matched
		// it's matched if both are unmatched
		// then, there exists an edge between them
		nxt[1] = dp[on][0] * dp[to][0] % MOD;
		// it's on is matched, then the subtree must also be matched
		// if the subtree is already fully matched, the edge doesn't matter
		nxt[1] += dp[on][1] * (2 * dp[to][1] % MOD + dp[to][2]) % MOD;
		//std::cout << "(" << dp[on][0] * dp[to][0] << ", " << dp[on][1] * (2 * dp[to][1] + dp[to][2]) << ")\n";
		// transition not matching
		// if on is unmatched and there will be no match
		// if to is matched, then the edge doesn't matter
		nxt[0] = dp[on][0] * 2 * dp[to][1] % MOD;
		// otherwise, on in unmatched and to is unmatched
		// in this case, to needs to be alone
		// otherwise there's no perfect match
		nxt[0] += dp[on][0] * dp[to][2] % MOD;
		for(int i = 0; i < 2; i++) {
			dp[on][i] = nxt[i] % MOD;
		}
		// here, it's the case of unmatched but ok
		// in this case, there will be no edge
		// below should be ok and unmatched or matched
		dp[on][2] = dp[on][2] * (dp[to][1] + dp[to][2]) % MOD;
		//std::cout << "on " << on + 1 << ", after " << to << " got (" << dp[on][0] << ", " << dp[on][1] << ", " << dp[on][2] << ")\n";

	}
	//std::cout << "on " << on + 1 << " returning (" << dp[on][0] << ", " << dp[on][1] << ", " << dp[on][2] << ")\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1);
	std::cout << (dp[0][2] + dp[0][1]) % MOD << '\n';
}