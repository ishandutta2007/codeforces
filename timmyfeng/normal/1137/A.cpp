#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (auto& i : a) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	vector<vector<int>> rows(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		vector<int> b = a[i];
		sort(b.begin(), b.end());
		b.resize(unique(b.begin(), b.end()) - b.begin());
		for (int j = 0; j < m; ++j) {
			rows[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin() + 1;
		}
	}

	vector<vector<int>> cols(n, vector<int>(m));
	for (int j = 0; j < m; ++j) {
		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			b[i] = a[i][j];
		}
		sort(b.begin(), b.end());
		b.resize(unique(b.begin(), b.end()) - b.begin());
		for (int i = 0; i < n; ++i) {
			cols[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin() + 1;
		}
	}

	vector<int> mx_rows(n);
	vector<int> mx_cols(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mx_rows[i] = max(mx_rows[i], rows[i][j]);
			mx_cols[j] = max(mx_cols[j], cols[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (rows[i][j] > cols[i][j]) {
				cout << max(mx_rows[i], mx_cols[j] + rows[i][j] - cols[i][j]) << " ";
			} else {
				cout << max(mx_rows[i] + cols[i][j] - rows[i][j], mx_cols[j]) << " ";
			}
		}
		cout << "\n";
	}
}