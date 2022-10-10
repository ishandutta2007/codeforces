#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long a[4];
		for(int i = 0; i < 4; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a + 3);
		if(a[3] >= 2 * a[2] - a[1] - a[0] && (a[3] - 2 * a[2] + a[1] + a[0]) % 3 == 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}