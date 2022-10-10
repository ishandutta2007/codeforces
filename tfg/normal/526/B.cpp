#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int pot, n;
	std::cin >> pot;
	n = 1 << (pot+1);
	std::vector<long long> dp(n);
	for(int i = 2; i < n; i++) {
		std::cin >> dp[i];
	}
	long long ans = 0;
	for(int i = n / 2 - 1; i > 0; i--) {
		ans += abs(dp[i+i] - dp[i+i+1]);
		dp[i] += std::max(dp[i+i], dp[i+i+1]);
	}
	std::cout << ans << '\n';
}