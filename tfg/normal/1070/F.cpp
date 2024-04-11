#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a[4];
	while(n--) {
		int msk;
		std::cin >> msk;
		msk = msk % 10 + (msk / 10) * 2;
		int v;
		std::cin >> v;
		a[msk].push_back(v);
	}
	int ans = 0;
	int bal = 0;
	for(int i = 0; i < 4; i++) {
		std::sort(a[i].begin(), a[i].end());
	}
	while(a[3].size() > 0) {
		ans += a[3].back();
		bal++;
		a[3].pop_back();
	}
	while(a[1].size() > 0 && a[2].size() > 0) {
		ans += a[1].back() + a[2].back();
		a[1].pop_back();
		a[2].pop_back();
	}
	for(auto v : a[1]) {
		a[0].push_back(v);
	}
	for(auto v : a[2]) {
		a[0].push_back(v);
	}
	std::sort(a[0].begin(), a[0].end());
	while(bal > 0 && a[0].size() > 0) {
		ans += a[0].back();
		a[0].pop_back();
		bal--;
	}
	std::cout << ans << '\n';
}