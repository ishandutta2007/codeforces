#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

bool a[MX][MX], b[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}

	vector<pair<int, int>> ans;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (b[i - 1][j - 1] && b[i - 1][j] && b[i][j - 1] && b[i][j]) {
				a[i - 1][j - 1] = a[i - 1][j] = a[i][j - 1] = a[i][j] = 1;
				ans.emplace_back(i, j);
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != b[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}