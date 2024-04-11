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
		int n;
		std::cin >> n;
		bool ans = false;
		for(int i = 0; i <= 11 && i * 111 <= n && !ans; i++) {
			if((n - i * 111) % 11 == 0) {
				ans = true;
			}
		}
		std::cout << (ans ? "YES\n" : "NO\n");
	}
}