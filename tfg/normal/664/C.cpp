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
		for(int i = 0; i < 4; i++) {
			char trash;
			std::cin >> trash;
		}
		std::string wtf;
		std::cin >> wtf;
		long long n = 0;
		for(auto x : wtf) n = n * 10 + x - '0';
		long long l = 1989, r = 1999;
		for(int i = 0; i+1 < (int) wtf.size(); i++) {
			l = r + 10 * (r - l);
			std::swap(l, r);
		}
		std::cout << l + ((n - l % (r - l) + (r - l)) % (r - l)) << '\n';
	}
}