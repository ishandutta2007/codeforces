#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	if(n == m && n == 1) {
		std::cout << "0\n";
		return 0;
	}
	if(m == 1) {
		for(int i = 0; i < n; i++) {
			std::cout << i + 2 << '\n';
		}
		return 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cout << (long long) (i + 1) * (n + 1 + j) << (j + 1 == m ? '\n' : ' ');
		}
	}
}