#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k, m;
	int n;
	std::cin >> m >> n >> k;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for(int l = 0, r = 0; l < n; l = r, ans++) {
		while(r < n && (a[l]-1-l) / k == (a[r]-1-l) / k) r++;
	}
	std::cout << ans << '\n';
}