#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, s;
	std::cin >> n >> s;
	if(s == 1) {
		std::cout << "NO\n";
	} else if(n == 1) {
		std::cout << "YES\n" << s << '\n' << 1 << '\n';
	} else if(s >= n * 2) {
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			std::cout << s / n + (i < s % n ? 1 : 0) << (i + 1 == n ? '\n' : ' ');
		}
		std::cout << "1\n";
	} else {
		std::cout << "NO\n";
	}
}