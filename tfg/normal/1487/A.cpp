#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	int mn = 1e9, f = 0;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(x < mn) {
			mn = x, f = 0;
		}
		if(x == mn) {
			f++;
		}
	}
	std::cout << n - f << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}