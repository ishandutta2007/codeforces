#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	if(n * (n - 1) / 2 > k) {
		for(int i = 0; i < n; i++) {
			std::cout << "0 " << i << '\n';
		}
	} else {
		std::cout << "no solution\n";
	}
}