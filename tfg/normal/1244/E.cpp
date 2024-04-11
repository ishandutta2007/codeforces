#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long k;
	std::cin >> n >> k;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long long ans = 1e18;
	for(int rep = 0; rep < 2; rep++) {
		std::sort(a.begin(), a.end());
		std::vector<long long> sum(n + 1, 0);
		for(int i = 0; i < n; i++) {
			sum[i+1] = sum[i] + a[i];
		}
		for(int l = 0, r = n-1; l < n && (l + 1LL) * a[l] - sum[l+1] <= k; l++) {
			long long cost = (l + 1LL) * a[l] - sum[l+1] + (sum[n] - sum[r]) - (long long) (n-r) * a[r];
			while(r > l && cost + (a[r] - a[r-1]) * (n-r) <= k) {
				cost += (a[r] - a[r-1]) * (n-r);
				r--;
			}
			while(cost > k || r < l) {
				r++;
				cost -= (a[r] - a[r-1]) * (n-r);
			}
			if(l >= r) {
				ans = 0;
				break;
			}
			long long rest = k - cost;
			long long c1 = l+1, u1 = a[l+1] - a[l];
			if(l + 1 == r) {
				ans = std::min(ans, a[l+1] - a[l] - std::min(rest / c1, u1));
			} else {
				long long c2 = n-r, u2 = a[r] - a[r-1];
				if(c1 > c2) {
					std::swap(c1, c2);
					std::swap(u1, u2);
				}
				long long use1 = std::min(rest / c1, u1);
				rest -= use1 * c1;
				long long use = std::min(rest / c2, u2) + use1;
				ans = std::min(ans, a[r] - a[l] - use);
			}
		}
		for(auto &x : a) x = -x;
	}
	std::cout << ans << '\n';
}