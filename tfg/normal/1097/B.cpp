#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < (1 << n); i++) {
		int bal = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				bal += a[j];
			} else {
				bal -= a[j];
			}
		}
		bal %= 360;
		bal += 360;
		if(bal % 360 == 0) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}