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
		int n;
		std::cin >> n;
		while(n--) {
			int x;
			std::cin >> x;
			int best[2] = {(int) 2e9, -1};
			for(int i = 0; i < 30; i++) {
				int cost = std::abs((1 << i) - x);
				if(cost < best[0]) {
					best[0] = cost;
					best[1] = 1 << i;
				}
			}
			assert(best[1] != -1);
			std::cout << best[1] << ' ';
		}
		std::cout << '\n';
	}
}