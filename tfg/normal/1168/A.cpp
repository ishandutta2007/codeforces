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
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	auto check = [&](int x) {
		int dp = 0;
		for(auto v : a) {
			int nxt = m + 1;
			if(v >= dp) {
				nxt = std::min(nxt, v);
			}
			if(m - v + dp <= x) {
				nxt = std::min(nxt, dp);
			}
			if(v <= dp && dp - v <= x) {
				nxt = std::min(nxt, dp);
			}
			if(nxt == m + 1) {
				return false;
			}
			dp = nxt;
		}
		return true;
	};
	int l = 0, r = m;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}