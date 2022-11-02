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
#include <numeric>
#include <array>
#include <limits>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<pair<int, int>> ranges(n);
		for (auto &[l, r] : ranges) cin >> l >> r;
		sort(ranges.begin(), ranges.end(), [](const pair<int, int> lhs, const pair<int, int> rhs) {
			int len1 = lhs.second - lhs.first;
			int len2 = rhs.second - rhs.first;
			if (len1 != len2) {
				return len1 < len2;
			}
			return lhs.first < rhs.first;
		});
		vector<bool> used(n);
		for (auto [l, r] : ranges) {
			for (int j = l - 1; j < r; j++) {
				if (!used[j]) {
					used[j] = true;
					cout << l << " " << r << " " << j + 1 << "\n";
					break;
				}
			}
		}
	}
	return 0;
}