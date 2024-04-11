#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		ans += x % 2;
	}
	std::cout << std::min(ans, n - ans) << '\n';
}