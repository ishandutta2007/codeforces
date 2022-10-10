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
	std::vector<std::vector<int>> table(m, std::vector<int>(m, 0));
	std::string str;
	std::cin >> str;
	for(int i = 1; i < n; i++) {
		int u = str[i-1] - 'a', v = str[i] - 'a';
		table[u][v]++;
		table[v][u]++;
	}
	n = m;
	std::vector<int> dp(1 << n, 1e9);
	dp[0] = 0;
	for(int mask = 0; mask+1 < (1 << n); mask++) {
		int cost = 0;
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) continue;
			for(int j = 0; j < n; j++) {
				if(!(mask & (1 << j))) continue;
				cost += table[i][j];
			}
		}
		for(int i = 0; i < n; i++) {
			if((mask & (1 << i))) continue;
			dp[mask | (1 << i)] = std::min(dp[mask | (1 << i)], dp[mask] + cost);
		}
	}
	std::cout << dp.back() << '\n';
}