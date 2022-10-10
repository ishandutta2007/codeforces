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
		int n, k;
		std::cin >> n >> k;
		bool win;
		if(k % 3 == 0) {
			win = n % (k + 1) % 3 != 0 || n % (k + 1) == k;
		} else {
			win = n % 3 != 0;
		}
		std::cout << (!win ? "Bob\n" : "Alice\n");
	}
}