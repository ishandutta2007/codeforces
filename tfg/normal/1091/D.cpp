#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	const long long MOD = 998244353;
	long long fat = 1;
	for(int i = 1; i <= n; i++) {
		fat = fat * i % MOD;
	}
	long long ans = fat;
	long long other = 1;
	for(int i = n; i > 0; i--) {
		other = other * i % MOD;
		ans = (ans + fat - other + MOD) % MOD;
	}
	std::cout << ans << '\n';
}