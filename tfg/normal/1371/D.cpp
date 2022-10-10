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
		int n, k;
		std::cin >> n >> k;
		std::cout << (k % n == 0 ? 0 : 2) << '\n';
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				int id = j < i ? (n - i) + j : j - i;
				int realID = i + id * n;
				std::cout << (realID < k ? 1 : 0);
			}
			std::cout << '\n';
		}
	}
}