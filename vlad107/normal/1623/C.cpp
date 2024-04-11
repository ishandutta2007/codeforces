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

bool check(vector<int> &h, int M) {
	int n = h.size();
	vector<int> d(n);
	for (int i = n - 1; i >= 0; i--) {
		int H = h[i];
		if ((2 <= i + 1) && (i + 1 < n)) H += d[i + 1];
		if (i + 2 < n) H += d[i + 2] * 2;
		// 3 * d[i] <= h[i]
		// 3 * d[i] <= H - M
		if (H < M) return false;
		d[i] = min(H - M, h[i]) / 3;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> h(n);
		for (int &x : h) cin >> x;
		int L = 0;
		int R = 1e9;
		while (L < R - 1) {
			int M = (L + R) / 2;
			if (check(h, M)) {
				L = M;
			} else {
				R = M;
			}
		}
		cout << L << "\n";
	}
	return 0;
}