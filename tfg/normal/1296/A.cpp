#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		int f[2] = {0, 0};
		while(n--) {
			int x;
			std::cin >> x;
			f[x % 2]++;
		}
		if(f[1] % 2 == 1 || (f[1] && f[0])) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}