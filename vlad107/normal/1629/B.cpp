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
		int l, r, k;
		cin >> l >> r >> k;
		if ((l == r) && (l == 1)) {
			cout << "NO\n";
			continue;
		}
		int len = (r - l + 1);
		int cnt;
		if (len % 2 == 0) {
			cnt = len / 2;
		} else if (len == 1) {
			cnt = 0;
		} else if (l % 2 == 0) {
			cnt = len / 2;
		} else {
			cnt = (len + 1) / 2;
		}
		cout << ((cnt <= k) ? "YES" : "NO") << "\n";
	}
	return 0;
}