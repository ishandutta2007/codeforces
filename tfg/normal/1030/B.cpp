#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, d;
	std::cin >> n >> d;
	int q;
	std::cin >> q;
	while(q--) {
		int x, y;
		std::cin >> x >> y;
		int u = x-y, v = x+y;
		if(v >= d && v <= 2*n-d && u >= -d && u <= d) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}