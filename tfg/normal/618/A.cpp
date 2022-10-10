#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 20; i >= 0; i--) {
		if(n & (1 << i)) {
			std::cout << i+1 << ' ';
		}
	}
	std::cout << '\n';
}