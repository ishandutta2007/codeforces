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
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int pos = 0;
		for(int i = 1; i < n; i++) {
			if(a[i] != a[i-1]) {
				pos++;
			}
		}
		if(pos > 0 && k == 1) {
			std::cout << "-1\n";
		} else if(k == 1) {
			std::cout << "1\n";
		} else {
			std::cout << std::max(1, (pos + k - 2) / (k-1)) << '\n';
		}
	}
}