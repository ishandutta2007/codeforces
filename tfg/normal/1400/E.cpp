#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, a[5050];

int solve(int l, int r, int x) {
	int ans = 0;
	int mn = 2e9;
	for(int i = l; i < r; i++) {
		mn = std::min(mn, a[i]);
	}
	ans += mn - x;
	for(int i = l, j = l; i < r; i = j) {
		if(a[i] == mn) {
			j++;
			continue;
		}
		while(j < r && a[j] != mn) j++;
		ans += solve(i, j, mn);
	}
	ans = std::min(ans, r - l);
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cout << solve(0, n, 0) << '\n';
}