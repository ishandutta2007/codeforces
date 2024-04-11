#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	if(k > (n - 1) / 2) {
		std::cout << "-1\n";
	} else {
		std::cout << n * k << '\n';
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) {
				std::cout << i + 1 << ' ' << (i + 1 + j) % n + 1 << '\n';
			}
		}
	}
}