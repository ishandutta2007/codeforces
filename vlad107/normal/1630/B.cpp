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
		vector<int> b(n), a(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			a[i] = b[i];
		}
		// x - (n - x) >= k ; 2x >= n + k ; x >= [(n+k+1)/2]
		int need = (n + k + 1) / 2;
		sort(a.begin(), a.end());
		int x = a[0], y = a.back();
		int mn = y - x;
		for (int i = 0; i + need - 1 < a.size(); i++) {
			if (a[i + need - 1] - a[i] < mn) {
				mn = a[i + need - 1] - a[i];
				x = a[i];
				y = a[i + need - 1];
			}
		}
		cout << x << " " << y << "\n";
		int balance = 0;
		int curL = 0;
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++) {
			if ((x <= b[i]) && (b[i] <= y)) {
				++balance;
			} else {
				--balance;
			}
			if (balance > 0) {
				ans.push_back({curL + 1, i + 1});
				curL = i + 1;
				balance = 0;
			}
		}
		for (int i = 0; i + 1 < k; i++) cout << ans[i].first << " " << ans[i].second << "\n";
		cout << ans[k - 1].first << " " << n << "\n";
	}
	return 0;
}