#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::string str;
	std::cin >> n >> k;
	std::vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cin >> str;
	long long ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && str[l] == str[r]) r++;
		std::sort(a.begin() + l, a.begin() + r);
		for(int i = 0; i < r - l && i < k; i++) {
			ans += a[r-1-i];
		}
	}
	std::cout << ans << '\n';
}