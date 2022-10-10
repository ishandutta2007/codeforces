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
		int ans = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
			char ch;
			std::cin >> ch;
			if(i == n-1 && ch == 'D' || j == m-1 && ch == 'R') ans++;
		}
		std::cout << ans << '\n';
	}
}