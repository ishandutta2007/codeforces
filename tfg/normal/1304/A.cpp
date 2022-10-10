#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long x, y, a, b;
		std::cin >> x >> y >> a >> b;
		if((y - x) % (a + b) == 0) {
			std::cout << (y - x) / (a + b) << '\n';
		} else {
			std::cout << "-1\n";
		}
	}
}