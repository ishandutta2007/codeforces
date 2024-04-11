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
		int n, m;
		std::cin >> n >> m;
		int good = 3;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
			char ch;
			std::cin >> ch;
			if(ch == 'R') {
				good &= 1 << ((i + j) % 2);
			} else if(ch == 'W') {
				good &= 1 << ((i + j + 1) % 2);
			}
		}
		if(!good) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
				std::cout << ((i + j + good % 2) % 2 ? 'R' : 'W');
				if(j+1 == m) std::cout << '\n';
			}
		}
	}
}