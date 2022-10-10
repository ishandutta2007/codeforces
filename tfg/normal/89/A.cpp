#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	if(n % 2 == 0) { std::cout << "0\n"; return 0; }
	int mn = (int) std::min((long long) 1e5, (long long) k * (m / ((n + 1) / 2)));
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(i % 2 == 0) {
			mn = std::min(mn, x);
		}
	}
	std::cout << mn << '\n';
}