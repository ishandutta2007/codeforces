#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

int a[ms], p[ms];
int sum[ms];
std::vector<int> pos[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
		sum[i+1] = a[i];
		sum[i+1] += sum[i];
		sum[i+1] %= k;
	}
	for(int i = 0; i <= n; i++) {
		pos[sum[i]].push_back(i);
		//std::cout << i << ": " << sum[i] << '\n';
	}
	std::sort(p, p + n, [&](int v1, int v2) { return a[v1] > a[v2]; });
	std::set<int> lim;
	lim.insert(0);
	lim.insert(n+1);
	long long ans = 0;
	for(int j = 0; j < n; j++) {
		int m = p[j];
		int l, r;
		{
			auto it = lim.lower_bound(m+1);
			r = *it;
			it--;
			l = *it;
			lim.insert(m+1);
		}
		if(m - l <= r - m) {
			for(int i = l; i <= m; i++) {
				// want - sum[l] - a[m] == 0
				// want == sum[l] + a[m]
				int want = (sum[i] + a[m]) % k;
				int got = std::lower_bound(pos[want].begin(), pos[want].end(), r) -
						  std::lower_bound(pos[want].begin(), pos[want].end(), std::max(m+1, i+2));
				//std::cout << "1: at [" << i << ", " << m << ", " << r << "] got " << got << '\n';
				if(got >= 0) {
					ans += got;
				}
			}
		} else {
			for(int i = m+1; i < r; i++) {
				int want = (sum[i] - a[m] % k + k) % k;
				//std::cout << "range is " << std::min(m, i-3) + 1 << ", " << l-1 << '\n';
				int got = std::lower_bound(pos[want].begin(), pos[want].end(), std::min(m, i-2) + 1) -
						  std::lower_bound(pos[want].begin(), pos[want].end(), l);
				//std::cout << "2: at [" << l << ", " << m << ", " << i << "] got " << got << '\n';
				if(got >= 0) {
					ans += got;
				}
			}
		}
	}
	std::cout << ans << '\n';
}