#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, t;
	std::cin >> n >> t;
	if(n % 2 == 0) {
		std::cout << (t-1) % n + 1 << '\n';
	} else {
		std::cout << (t-1 + (t-1)/(n/2)) % n + 1 << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}