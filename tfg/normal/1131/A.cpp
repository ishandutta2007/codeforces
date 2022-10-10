#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	std::cout << 2 * (y1 + 1 + y2 + 1) + x1 + x2 + std::max(x1, x2) - std::min(x1, x2) << '\n';
}