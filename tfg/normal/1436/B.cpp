#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int x) {
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		int ans1 = 2 * (n-1) + 1;
		while(isPrime((ans1-1)/(n-1)) || !isPrime(ans1)) {
			ans1 += (n - 1);
		}
		int ans2 = n + 1;
		while(isPrime(ans2 - (n-1)) || !isPrime(ans2)) {
			ans2++;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i+1 != n && j+1 != n) {
					std::cout << (ans1-1) / (n-1);
				} else if(i+1 == n && j+1 == n) {
					std::cout << ans2 - (n-1);
				} else {
					std::cout << 1;
				}
				std::cout << (j + 1 == n ? '\n' : ' ');
			}
		}
	}
}