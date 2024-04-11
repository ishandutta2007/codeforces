#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a.begin(), a.end());
	std::cout << (a[0] + a[1] <= k || a.back() <= k ? "YES\n" : "NO\n");
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}