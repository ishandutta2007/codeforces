#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int ans[2] = {0, (int) 2e9 + 1};
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for(int i = 1; i < n; i++) {
		if(a[i] - a[i-1] < ans[1]) {
			ans[1] = a[i] - a[i-1];
			ans[0] = 0;
		}
		if(ans[1] == a[i] - a[i-1]) {
			ans[0]++;
		}
	}
	std::cout << ans[1] << ' ' << ans[0] << '\n';
}