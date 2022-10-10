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
		int n, x, a, b;
		std::cin >> n >> x >> a >> b;
		std::cout << std::min(n-1, abs(a-b)+x) << '\n';
	}
}