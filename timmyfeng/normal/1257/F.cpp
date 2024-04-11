#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	map<vector<int>, int> lo;
	vector<int> cur(n - 1);
	for (int i = 0; i < (1 << 15); ++i) {
		int first = __builtin_popcount(a[0] & ((1 << 15) - 1) ^ i);
		for (int j = 1; j < n; ++j) {
			cur[j - 1] = first - __builtin_popcount(a[j] & ((1 << 15) - 1) ^ i);
		}
		lo[cur] = i;
	}

	for (int i = 0; i < (1 << 15); ++i) {
		int first = __builtin_popcount((a[0] >> 15) ^ i);
		for (int j = 1; j < n; ++j) {
			cur[j - 1] = __builtin_popcount((a[j] >> 15) ^ i) - first;
		}
		if (lo.count(cur)) {
			cout << (i << 15) + lo[cur] << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}