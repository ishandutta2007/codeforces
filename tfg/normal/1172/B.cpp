#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int MOD = 998244353;

std::vector<int> edges[ms];

int fat[ms];
int dp[ms][2];

void dfs(int on, int par) {
	int deg = 0;
	int wtf = 1;
	for(auto to : edges[on]) {
		if(par == to) continue;
		dfs(to, on);
		deg++;
		wtf = (int)(wtf * (dp[to][0] * (edges[to].size() == 1 ? 1LL : 2LL) + dp[to][1]) % MOD);
	}
	dp[on][0] = (int)((long long) wtf * fat[deg] % MOD);
	if(deg != 0) {
		dp[on][1] = (int)((long long) wtf * fat[deg] % MOD * (deg - 1) % MOD);
	}
	//std::cout << "at " << on + 1 << " got: (" << dp[on][0] << ", " << dp[on][1] << ") and " << wtf << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	fat[0] = 1;
	for(int i = 1; i <= n; i++) {
		fat[i] = (int)((long long) fat[i-1] * i % MOD);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, 0);
	std::cout << (dp[0][0] * (long long) n) % MOD << '\n';
}