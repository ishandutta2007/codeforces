#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::bitset<155>> a(n+1);
	a[0][0] = 1;
	a[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		a[i] = a[i-2] ^ (a[i-1] << 1);
	}
	std::cout << n << '\n';
	for(int i = 0; i <= n; i++) {
		std::cout << (a[n][i] ? 1 : 0) << (i == n ? '\n' : ' ');
	}
	std::cout << n-1 << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << (a[n-1][i] ? 1 : 0) << (i == n-1 ? '\n' : ' ');
	}
}