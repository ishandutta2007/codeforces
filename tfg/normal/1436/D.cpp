#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p(n), a(n);
	std::vector<bool> leaf(n, true);
	for(int i = 1; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
		leaf[p[i]] = false;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	auto check = [&](long long x) {
		std::vector<long long> dp(n, 0);
		for(int i = n-1; i > 0; i--) {
			if(leaf[i]) {
				dp[i] += x;
			}
			if(dp[i] < a[i]) {
				return false;
			}
			dp[i] -= a[i];
			dp[p[i]] = std::min((long long) 1e16, dp[i] + dp[p[i]]);
		}
		return dp[0] >= a[0];
	};
	long long l = 0, r = 1e16;
	while(l != r) {
		long long mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}