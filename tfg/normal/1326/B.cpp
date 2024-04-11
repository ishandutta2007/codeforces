#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		std::cout << x + mx << (i + 1 == n ? '\n' : ' ');
		if(x > 0) mx += x;
	}
}