#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::cout << "2\n";
		int cur = n;
		for(int i = n-1; i >= 1; i--) {
			std::cout << cur << ' ' << i << '\n';
			cur = (cur + i + 1) / 2;
		}
		assert(cur == 2);
	}
}