#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(long long x) {
	if(x == 0) return 0;
	if(x % 2 == 0) return x / 2;
	for(long long i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return 1 + solve(x - i);
		}
	}
	return 1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	std::cin >> n;
	std::cout << solve(n) << '\n';
}