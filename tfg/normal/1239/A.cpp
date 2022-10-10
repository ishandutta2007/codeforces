#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	const int ms = 100100;
	const int MOD = 1e9 + 7;
	std::vector<int> fib(ms, 1);
	for(int i = 2; i < ms; i++) {
		fib[i] = (fib[i-1] + fib[i-2]) % MOD;
	}
	std::cout << ((long long) MOD + fib[n] + fib[m] - 1) * 2 % MOD << '\n';
}