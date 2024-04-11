#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long sum = 0, x = 0;
		{
			int n;
			std::cin >> n;
			while(n--) {
				int v;
				std::cin >> v;
				x ^= v;
				sum += v;
			}
		}
		// add x
		// sum += x
		// add sum
		std::cout << "2\n" << x << " " << (sum + x) << "\n";
		assert((sum + sum + x + x) == 2 * (x ^ x ^ (sum + x)));
	}
}