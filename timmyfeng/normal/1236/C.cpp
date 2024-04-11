#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int k = 0;
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2) {
				ans[n - 1 - j][i] = ++k;
			} else {
				ans[j][i] = ++k;
			}
		}
	}
	for (auto& i : ans) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}