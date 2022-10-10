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
	while(t--) {
		long long n, k;
		std::cin >> n >> k;
		long long x = std::max(0LL, (long long)(sqrtl(n * n / ((long double) k * k * 2)) - 10));
		while(2 * k * k * (x+1) * (x+1) <= n*n) x++;
		std::cout << (k * k * (x * x + (x+1) * (x+1)) > n * n ? "Utkarsh\n" : "Ashish\n");
	}
}