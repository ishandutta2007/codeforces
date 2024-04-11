#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int MOD;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> MOD;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 1 % MOD;
	for(int i = 0; i < n && ans != 0; i++) {
		for(int j = 0; j < i && ans != 0; j++) {
			ans = (int) ((long long) ans * abs(a[i] - a[j]) % MOD);
		}
	}
	std::cout << ans << '\n';
}