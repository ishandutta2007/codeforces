#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, MOD;
	std::cin >> n >> MOD;
	int ans = 1 % MOD;
	for(int l = 1, r = 2; l <= n; ) {
		ans = (int) ((long long) ans * (r - l + 1) % MOD);
		l = r;
		r = std::min(n + 1, l * 2);
	}
	std::cout << (ans + MOD - 1) % MOD << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}