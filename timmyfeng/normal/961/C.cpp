#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<string>> a(4, vector<string>(n));
	for (auto& i : a) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	vector<vector<int>> cost(2, vector<int>(4));
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[k][i][j] == '0') {
					++cost[(i + j) % 2][k];
				} else {
					++cost[(i + j + 1) % 2][k];
				}
			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			int sum = 0;
			for (int k = 0; k < 4; ++k) {
				if (k != i && k != j) {
					sum += cost[0][k];
				} else {
					sum += cost[1][k];
				}
			}
			ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
}