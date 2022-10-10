#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	auto check = [&](int x) {
		long long ans = 0;
		for(auto v : a) {
			ans += std::max(x - v, 0);
		}
		return ans;
	};
	int l = mx, r = mx + m;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid) < m) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	std::cout << l << ' ' << mx + m << '\n';
}