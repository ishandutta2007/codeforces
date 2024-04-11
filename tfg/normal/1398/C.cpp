#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n+1, 0);
		for(int i = 1; i <= n; i++) {
			char ch;
			std::cin >> ch;
			a[i] = (int)(ch - '0') + a[i-1] - 1;
		}
		std::sort(a.begin(), a.end());
		long long ans = 0;
		for(int l = 0, r = 0; l <= n; l = r) {
			while(r <= n && a[l] == a[r]) r++;
			long long s = r - l;
			ans += s * (s - 1) / 2;
		}
		std::cout << ans << '\n';
	}
}