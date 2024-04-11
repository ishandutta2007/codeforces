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
		std::vector<int> a(n);
		bool good = true;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			good = good && a[i] == i + 1;
		}
		if(good) {
			std::cout << "0\n";
		} else if(a[0] == n && a[n-1] == 1) {
			std::cout << "3\n";
		} else if(a[0] != 1 && a[n-1] != n) {
			std::cout << "2\n";
		} else {
			std::cout << "1\n";
		}
	}
}