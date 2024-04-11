#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	long long W;
	std::cin >> n >> W;
	long long cur = 0;
	std::vector<long long> a(n);
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		if(a[i] + a[i] >= W && a[i] <= W) {
			std::cout << "1\n" << i+1 << '\n';
			return;
		}
		if(cur + a[i] <= W) {
			cur += a[i];
			ans.push_back(i+1);
		}
	}
	if(cur + cur >= W) {
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	} else {
		std::cout << "-1\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}