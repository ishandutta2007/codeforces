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
		int a, b;
		std::cin >> a >> b;
		if(a > b) std::swap(a, b);
		int l = (b - a) / 2, r = a * 2 + (b - a + 1) / 2;
		int gap = (a + b) % 2 == 0 ? 2 : 1;
		std::cout << (r - l + 1 + (gap - 1)) / gap << '\n';
		for(int i = l; i <= r; i += gap) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}