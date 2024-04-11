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
		/*
		(1, 0), (0, 1)
		(1, 0), (-1, 1)
		(1, 0), (-2, 1)
		(-1, 1), (-2, 1)
		(-1, 1), (-1, 0)
		(-1, 1), (0, -1)
		(-1, 0), (0, -1)
		*/
		int n;
		std::cin >> n;
		std::cout << (n / 2) * 6 << '\n';
		int seq[6] = {1, 1, 0, 1, 1, 0};
		for(int i = 0; i < n; i += 2) {
			int trash;
			std::cin >> trash;
			std::cin >> trash;
			for(int j = 0; j < 6; j++) {
				std::cout << seq[j]+1 << ' ' << i+1 << ' ' << i+2 << '\n';
			}
		}
	}
}