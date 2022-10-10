#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for(int i = 1; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
	}
	std::vector<int> size(n, 1);
	for(int i = n-1; i > 0; i--) {
		size[p[i]] += size[i];
	}
	std::vector<int> dp(n, 0);
	dp[0] = 2;
	for(int i = 1; i < n; i++) {
		dp[i] = dp[p[i]] + 2 + size[p[i]] - size[i] - 1;
	}
	for(int i = 0; i < n; i++) {
		std::cout << dp[i] / 2 << '.' << dp[i] % 2 * 5 << (i + 1 == n ? '\n' : ' ');
	}
}