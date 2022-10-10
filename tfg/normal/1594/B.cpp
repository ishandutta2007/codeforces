#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	const int MOD = 1e9 + 7;
	while(t--) {
		long long n, k;
		std::cin >> n >> k;
		long long pot = 1, ans = 0;
		while(k != 0) {
			if(k & 1) {
				ans = (pot + ans) % MOD;
			}
			pot = pot * n % MOD;
			k /= 2;
		}
		std::cout << ans << '\n';
	}
}