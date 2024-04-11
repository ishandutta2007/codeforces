#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> lis;
	int n;
	std::cin >> n;
	int ans = 0;
	std::vector<int> dp(n + 1, -1);
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		dp[v] = std::max(1, 1 + dp[v-1]);
		ans = std::max(ans, dp[v]);
	}
	std::cout << n - ans << '\n';
}