#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		while(k > 3) {
			k--, n--;
			std::cout << 1 << ' ';
		}
		if(n % 4 == 2) {
			std::cout << n/2-1 << ' ' << n/2-1 << ' ' << 2 << '\n';
		} else if(n % 2) {
			std::cout << n/2 << ' ' << n/2 << ' ' << 1 << '\n';
		} else {
			// n % 4 == 0
			// for example, 16
			// n/4 + n/4 + n/2
			// 4 4 8
			std::cout << n/4 << ' ' << n/4 << ' ' << n/2 << '\n';
		}
	}
}