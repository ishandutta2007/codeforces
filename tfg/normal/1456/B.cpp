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
	std::vector<int> a(n+1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] ^= a[i-1];
	}
	for(int len = 2; len <= n; len++) {
		for(int l = 0; l + len <= n; l++) {
			int r = l + len;
			for(int i = l+1; i < r; i++) {
				if((a[l] ^ a[i]) > (a[i] ^ a[r])) {
					std::cout << len - 2 << std::endl;
					return 0;
				}
			}
		}
	}
	std::cout << "-1\n";
}