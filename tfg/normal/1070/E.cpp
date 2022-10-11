#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int te;
	std::cin >> te;
	while(te--) {
		int n, m;
		long long t;
		std::cin >> n >> m >> t;
		std::vector<int> a(n);
		int l = (int) 1e9, r = 0;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			r = std::max(a[i], r);
			l = std::min(a[i], l);
		}
		if(l > t) {
			l = (int) t;
		}
		if(r > t) {
			r = (int) t;
		}
		auto check = [&](int x) {
			long long tot = 0;
			long long group = 0;
			int f = 0;
			for(int i = 0; i < n; i++) {
				if(a[i] <= x) {
					tot += a[i];
					group += a[i];
					f++;
					if(tot > t) return false;
					if(f == m) {
						tot += group;
						group = 0;
						f = 0;
					}
				}
			}
			return true;
		};
		auto getAns = [&](int x) {
			long long tot = 0;
			long long group = 0;
			int f = 0;
			int ans = 0;
			for(int i = 0; i < n; i++) {
				if(a[i] <= x) {
					tot += a[i];
					group += a[i];
					f++;
					if(tot <= t) {
						ans++;
					}
					if(f == m) {
						tot += group;
						group = 0;
						f = 0;
					}
				}
			}
			return ans;
		};
		while(l != r) {
			int mid = (l + r + 1) / 2;
			if(check(mid)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		int ans = l;
		if(l + 1 <= t && getAns(l + 1) > getAns(l)) {
			ans = l + 1;
		}
		std::cout << getAns(ans) << ' ' << ans << "\n";
	}
}