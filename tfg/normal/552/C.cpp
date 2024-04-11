#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long

std::vector<int> a[2];
std::vector<int> go(std::vector<int> arr) {
	int n = (int) arr.size();
	std::vector<int> ans(1, 0);
	for(int i = 0; i < n; i++) {
		int size = (int) ans.size();
		for(int j = 0; j < size; j++) {
			ans.push_back(ans[j] + arr[i]);
			ans.push_back(ans[j] - arr[i]);
		}
	}
	std::sort(ans.begin(), ans.end());
	return ans;
}
main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int w, m;
	std::cin >> w >> m;
	if(w == 2) {
		std::cout << "YES\n";
		return 0;
	}
	long long cur = 1;
	long long sum = 0;
	for(int i = 0; cur - sum <= m; cur *= w, i++) {
		sum += cur;
		a[i%2].push_back(cur);
		//std::cout << "pushing (" << cur << " at " << i%2 << ")" << std::endl;
	}
	a[0] = go(a[0]);
	a[1] = go(a[1]);
	for(auto v : a[0]) {
		int id = std::lower_bound(a[1].begin(), a[1].end(), m - v) - a[1].begin();
		if(id < (int) a[1].size() && a[1][id] == m - v) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}