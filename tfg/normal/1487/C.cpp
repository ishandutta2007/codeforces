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
		int n;
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				if(n % 2 == 1) {
					std::cout << ((j + i) % 2 ? 1 : -1) << ' ';
				} else if(i % 2 == 0) {
					if(j == i+1) {
						std::cout << "0 ";
					} else {
						std::cout << ((j + i) % 2 ? 1 : -1) << ' ';
					}
				} else {
					std::cout << ((j + i) % 2 ? 1 : -1) << ' ';
				}
			}
		}
		std::cout << '\n';
	}
}