#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int l = 1e9;
	int r = 0;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		l = std::min(l, v);
		r = std::max(r, v);
	}
	std::cout << (r - l + 1) - n << std::endl;
}