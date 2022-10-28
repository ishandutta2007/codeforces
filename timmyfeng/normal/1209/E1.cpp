#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	vector<int> mx_a(m);
	vector<int> mx_b(m);
	vector<int> mx_c(m);
	vector<int> mx_d(m);
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		int mn = 1e9;
		for (int j = 0; j < n; ++j) {
			mx_a[i] = max(mx_a[i], a[j][i]);
			mx_b[i] = max(mx_b[i], a[j][i] + a[(j + 1) % n][i]);
			mx_c[i] = max(mx_c[i], a[j][i] + a[(j + 2) % n][i]);
			mn = min(mn, a[j][i]);
			sum += a[j][i];
		}
		mx_d[i] = sum - mn;
		ans = max(ans, sum);
	}

	if (n == 4) {
		for (int i = 0; i < m; ++i) {
			int mx = 0;
			int oth = 0;
			for (int l = 0; l < n; ++l) {
				if (a[l][i] > mx) {
					oth = mx;
					mx = a[l][i];
				} else {
					oth = max(oth, a[l][i]);
				}
			}

			for (int j = 0; j < m; ++j) {
				for (int k = j + 1; k < m; ++k) {
					if (j != i && k != i) {
						ans = max(ans, mx_a[j] + mx_a[k] + mx + oth);
					}
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				ans = max({ans, mx_b[i] + mx_b[j], mx_c[i] + mx_c[j]});
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			ans = max({ans, mx_d[i] + mx_a[j], mx_d[j] + mx_a[i]});
		}
	}

	sort(mx_a.rbegin(), mx_a.rend());
	int sum = 0;
	for (int i = 0; i < n && i < m; ++i) {
		sum += mx_a[i];
	}
	ans = max(ans, sum);

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}