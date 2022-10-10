#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, b, a;
	std::cin >> n >> b >> a;
	int cb = b, ca = a;
	for(int i = 0; i < n; i++) {
		if(cb == 0 && ca == 0) {
			std::cout << i << '\n';
			return 0;
		}
		int x;
		std::cin >> x;
		if(x == 1) {
			if(ca < a && cb > 0) {
				cb--;
				ca++;
			} else {
				ca--;
			}
		} else {
			if(ca > 0) {
				ca--;
			} else {
				cb--;
			}
		}
	}
	std::cout << n << '\n';
}