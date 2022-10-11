#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long l, r;
	std::cin >> l >> r;
	std::cout << "YES\n";
	for(long long i = l; i <= r; i += 2) {
		printf("%lld %lld\n", i, i + 1);
	}
}