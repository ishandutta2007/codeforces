#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#define int long long
//std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int32_t main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n;
		std::vector<int> aa(n);
		for(int i = 0; i < n; i++) {
			std::cin >> aa[i];
			aa[i] /= 100;
		}
		std::sort(aa.rbegin(), aa.rend());
		int x, a;
		int y, b;
		std::cin >> x >> a;
		std::cin >> y >> b;
		if(x < y) {
			std::swap(x, y);
			std::swap(a, b);
		}
		long long want;
		std::cin >> want;
		int g = gcd(a, b);
		auto check = [&](int size) {
			long long ans = 0;
			int use = size / (a / g * b);
			int pt = 0;
			while(use--) {
				ans += aa[pt++] * (x + y);
			}
			use = size / a - size / (a / g * b);
			while(use--) {
				ans += aa[pt++] * x;
			}
			use = size / b - size / (a / g * b);
			while(use--) {
				ans += aa[pt++] * y;
			}
			return ans;
		};
		int l = 0, r = n + 1;
		while(l != r) {
			int mid = (l + r) / 2;
			if(check(mid) >= want) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if(l == n + 1) {
			l = -1;
		}
		std::cout << l << '\n';
	}
}