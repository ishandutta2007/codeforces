#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> ans;
		if (k != n - 1) {
			ans.push_back({k, n - 1});
			if (k != 0) {
				ans.push_back({0, n - 1 - k});
			}
			for (int i = 0; i < n / 2; i++) {
				if ((i == 0) || (i == k) || (i == n - 1 - k)) continue;
				ans.push_back({i, n - 1 - i});
			}
		} else if (n == 4) {
			cout << "-1\n";
			continue;
		} else {
			ans.push_back({0, 1});
			ans.push_back({n - 1, n / 2 - 1});
			ans.push_back({n - 2, n / 2});
			for (int i = 0; i < n / 2; i++) {
				if ((i == 0) || (i == 1) || (i == n / 2 - 1)) continue;
				ans.push_back({i, n - 1 - i});
			}
		}
		int sum = 0;
		for (int i = 0; i < ans.size(); i++) sum += ans[i].first & ans[i].second;
		// assert(sum == k);
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}