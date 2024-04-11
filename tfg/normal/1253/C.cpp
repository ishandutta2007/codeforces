#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n+1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	std::vector<long long> dp(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		a[i] += a[i-1];
		if(i >= m) {
			dp[i] = dp[i-m];
		}
		dp[i] += a[i];
		std::cout << dp[i] << (i == n ? '\n' : ' ');
	}
}