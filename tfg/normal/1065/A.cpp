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
		long long s, a, b, c;
		std::cin >> s >> a >> b >> c;
		std::cout << s / c + s / c / a * b << std::endl;
	}
}