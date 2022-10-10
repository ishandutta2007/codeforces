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
	int x = 0;
	for(int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		x ^= a;
	}
	if(n % 2 == 0 && x) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n" << (n - 1) / 2 * 2 << '\n';
		for(int rep = 0; rep < 2; rep++) for(int i = 1; i+1 < n; i += 2) {
			std::cout << "1 " << i+1 << ' ' << i+2 << "\n";
		}
	}
}