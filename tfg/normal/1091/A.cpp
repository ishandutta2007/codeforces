#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int y, b, r;
	std::cin >> y >> b >> r;
	std::cout << std::min(y, std::min(b - 1, r - 2)) * 3 + 3 << '\n';
}