#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, d;
		std::cin >> n >> d;
		int sq = sqrt(d);
		bool valid = false;
		for(int j = std::max(-10, -sq); j <= 20; j++) {
			valid = valid || sq+j + (d + sq+j) / (sq+j + 1) <= n;
		}
		std::cout << (valid ? "YES\n" : "NO\n");
	}
}