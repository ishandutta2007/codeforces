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
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) cin >> a[i].first;
		for (int i = 0; i < n; i++) cin >> a[i].second;
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (a[i].first <= k) {
				k += a[i].second;
			}
		}
		cout << k << "\n";
	}
	return 0;
}