#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int l, r, d;
		std::cin >> l >> r >> d;
		if(d < l) {
			std::cout << d << '\n';
		} else {
			std::cout << r / d * d + d << '\n';
		}
	}
}