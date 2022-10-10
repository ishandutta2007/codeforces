#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, h;
	std::cin >> n >> h;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	auto check = [&](int x) {
		long long ans = 0;
		std::vector<int> b(a.begin(), a.begin() + x);
		if(b.size() % 2 == 1) {
			b.push_back(0);
		}
		std::sort(b.begin(), b.end());
		for(int i = 0; i < (int) b.size(); i += 2) {
			ans += b[i+1];
		}
		return ans;
	};
	int l = 0, r = n;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(check(mid) <= h) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << '\n';
}