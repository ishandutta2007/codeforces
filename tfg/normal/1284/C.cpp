#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long MOD;
	std::cin >> n >> MOD;
	std::vector<long long> fat(n + 1, 1);
	for(int i = 1; i <= n; i++) {
		fat[i] = fat[i-1] * i % MOD;
	}
	long long ans = 0;
	for(int s = 1; s <= n; s++) {
		long long cur = n - s + 1;
		cur = cur * cur % MOD;
		cur = cur * fat[s] % MOD;
		cur = cur * fat[n-s] % MOD;
		ans = (ans + cur) % MOD;
	}
	std::cout << ans << std::endl;
}