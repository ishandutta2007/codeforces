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
		int trash, n, l, r;
		std::cin >> trash >> l >> n;
		r = l + 1;
		while(n--) {
			int left, right;
			std::cin >> left >> right;
			right++;
			if(std::max(left, l) < std::min(right, r)) {
				l = std::min(l, left);
				r = std::max(r, right);
			}
		}
		std::cout << r - l << '\n';
	}
}