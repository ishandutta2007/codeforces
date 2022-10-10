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
		int e = 0;
		while(n % 2 == 0) {
			n /= 2;
			e++;
		}
		if(e != 1) {
			std::cout << (n > 1 ? "Ashishgup\n" : "FastestFinger\n");
		} else {
			e = 0;
			for(int i = 2; i * i <= n; i++) {
				while(n % i == 0) {
					n /= i;
					e++;
				}
			}
			if(n > 1) {
				e++;
			}
			std::cout << (e != 1 ? "Ashishgup\n" : "FastestFinger\n");
		}
	}
}