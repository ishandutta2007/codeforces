#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int f[4];
	for(int i = 0; i < 4; i++) {
		std::cin >> f[i];
	}
	if(f[0] != f[3] || (f[2] > 0 && f[0] == 0)) {
		std::cout << "0\n";
	} else {
		std::cout << "1\n";
	}
}