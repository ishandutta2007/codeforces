#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int LIS(const std::vector<int> &a) {
	std::vector<int> lis;
	for(auto x : a) {
		int id = std::upper_bound(lis.begin(), lis.end(), x) - lis.begin();
		if(id == (int) lis.size()) {
			lis.push_back(x);
		} else {
			lis[id] = x;
		}
	}
	return (int) lis.size();
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int mn = -1e9;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i] -= i;
	}
	std::vector<bool> present(n);
	a.push_back(1e9);
	present.push_back(true);
	while(k--) {
		int x;
		std::cin >> x;
		present[x-1] = true;
	}
	std::vector<int> cur;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		if(present[i]) {
			int mx = a[i];
			if(mx < mn) {
				std::cout << "-1\n";
				return 0;
			}
			std::vector<int> wtf;
			for(auto &x : cur) {
				if(x < mn || x > mx) {
					ans++;
				} else {
					wtf.push_back(x);
				}
			}
			ans += (int) wtf.size() - LIS(wtf);
			cur.clear();
			mn = mx;
		} else {
			cur.push_back(a[i]);
		}
	}
	std::cout << ans << '\n';
	assert(cur.empty());
}