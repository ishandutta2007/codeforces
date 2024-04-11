#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::cin >> n;
	int k;
	std::cin >> k;
	if(k == 0) {
		std::cout << n * (n - 1) / 2 << '\n';
		for(int i = n; i > 0; i--) {
			for(int j = 1; j < i; j++) {
				std::cout << j << ' ' << j+1 << '\n';
			}
		}
	} else {
		std::cout << n * (n - 1) / 2 << '\n';
		for(int i = 1; i <= n; i++) {
			for(int j = n; j > i; j--) {
				std::cout << j << ' ' << j-1 << '\n';
			}
		}
	}
}