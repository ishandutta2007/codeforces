#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	const int MOD = 1e9 + 7;
	long long ans = 0;
	long long pot = 1;
	for(int i = 0; i < n; i++) {
		ans = (ans + a[i] * (pot - 1) % MOD - a[n-i-1] * (pot - 1) % MOD + MOD) % MOD;
		pot = 2 * pot % MOD;
	}
	std::cout << ans << '\n';
}