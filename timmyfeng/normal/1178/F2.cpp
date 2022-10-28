#include <bits/stdc++.h> 
using namespace std;

const int MXM = 1e6 + 1;
const int MX = 1000 + 5;
const int M = (119 << 23) + 1;

int add(int a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int c[MXM];

int a[MX];
int ndx[MX];
int fin[MX];
int start[MX];
int dp[MX][MX];
int seg_mn[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
		if (!start[c[i]]) {
			start[c[i]] = i;
		}
		fin[c[i]] = i;
	}

	vector<pair<int, int>> pts;
	for (int i = 1; i <= n; ++i) {
		if (start[i]) {
			pts.emplace_back(start[i], -i);
			pts.emplace_back(fin[i], i);
		}
	}
	sort(pts.begin(), pts.end());

	m = 0;
	for (auto [x, i] : pts) {
		if (i < 0) {
			i = -i;
			a[++m] = i;
			start[i] = m;
		} else {
			a[++m] = i;
			fin[i] = m;
		}
		ndx[m] = x;
	}

	for (int i = 1; i < m; ++i) {
		seg_mn[i] = n;
		for (int j = ndx[i]; j < ndx[i + 1]; ++j) {
			seg_mn[i] = min(seg_mn[i], c[j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (start[i]) {
			int mn = n;
			for (int j = start[i]; j < fin[i]; ++j) {
				mn = min(mn, seg_mn[j]);
			}
			if (mn < i) {
				cout << 0 << "\n";
				return 0;
			}
		}
	}

	for (int i = 0; i <= m + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			dp[i][j] = 1;
		}
	}

	for (int len = 1; len <= m; ++len) {
		for (int i = 1; i + len - 1 <= m; ++i) {
			int j = i + len - 1;

			int mn = *min_element(a + i, a + j + 1);

			if (start[mn] < i || fin[mn] > j) {
				dp[i][j] = 0;
				continue;
			}

			int left = 0;
			for (int k = start[mn]; k >= i && seg_mn[k] >= mn; --k) {
				left = add(left, mul(dp[i][k - 1], dp[k][start[mn] - 1]));
			}

			int right = 0;
			for (int k = fin[mn]; k <= j && seg_mn[k - 1] >= mn; ++k) {
				right = add(right, mul(dp[fin[mn] + 1][k], dp[k + 1][j]));
			}

			dp[i][j] = mul(dp[start[mn] + 1][fin[mn] - 1], mul(left, right));
		}
	}

	cout << dp[1][m] << "\n";
}