#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m;
	std::cin >> n >> m;
	if(n > m) std::swap(n, m);
	if(n == 1) {
		std::cout << m / 6 * 6 + (m % 6 >= 3 ? (m % 6 - 3) * 2 : 0LL) << '\n';
	} else if(n == 2) {
		if(m < 3) {
			std::cout << 0 << '\n';
		} else if(m == 3) {
			std::cout << 4 << '\n';
		} else {
			std::cout << n * (m - (m == 7 ? 1 : 0)) << '\n';
		}
	} else {
		std::cout << n * m / 2 * 2 << '\n';
	}
}