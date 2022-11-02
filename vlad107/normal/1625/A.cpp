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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, l;
		cin >> n >> l;
		vector<int> cnt1(l);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			for (int j = 0; j < l; j++) {
				if (((1<<j) & x) != 0) {
					++cnt1[j];
				}
			}
		}
		int res = 0;
		for (int i = 0; i < l; i++) {
			if (cnt1[i] * 2 > n) {
				res += (1<<i);
			}
		}
		cout << res << "\n";
	}
	return 0;
}