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
		int f[4] = {0, 0, 0, 0};
		while(n--) {
			int x;
			std::cin >> x;
			f[x]++;
		}
		std::cout << f[1] + f[3] << '\n';
	}
}