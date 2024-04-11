#include <bits/stdc++.h>
using namespace std;

const int MXM = 2e4;
const int MXN = 51;

int seg_tree[MXM * 4], lazy[MXM * 4], dp[MXM], m;
int vals[MXN][MXM];

void push(int v) {
	for (int i = 0; i < 2; ++i) {
		seg_tree[v * 2 + i] += lazy[v];
		lazy[v * 2 + i] += lazy[v];
	}
	lazy[v] = 0;
}

void upd(int a, int val, int v = 1, int l = 0, int r = m - 1) {
	if (l == r) {
		seg_tree[v] = val;
	} else {
		push(v);
		int m = (l + r) / 2;
		if (a <= m) {
			upd(a, val, v * 2, l, m);
		} else {
			upd(a, val, v * 2 + 1, m + 1, r);
		}
		seg_tree[v] = max(seg_tree[v * 2], seg_tree[v * 2 + 1]);
	}
}

void upd_range(int a, int b, int val, int v = 1, int l = 0, int r = m - 1) {
	if (b < l || r < a) {
		return;
	} else if (a <= l && r <= b) {
		seg_tree[v] += val;
		lazy[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		upd_range(a, b, val, v * 2, l, m);
		upd_range(a, b, val, v * 2 + 1, m + 1, r);
		seg_tree[v] = max(seg_tree[v * 2], seg_tree[v * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> vals[i][j];
		}
	}

	int cur = 0;
	for (int i = 0; i < m; ++i) {
		cur += vals[0][i] + vals[1][i];
		dp[i] = cur;
		if (i - k + 1 >= 0) {
			cur -= vals[0][i - k + 1] + vals[1][i - k + 1];
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			upd(j, dp[j]);
		}
		for (int j = 0; j < m; ++j) {
			upd_range(0, m - 1, vals[i][j] + vals[i + 1][j]);
			upd_range(j, j + k - 1, -vals[i][j]);
			dp[j] = seg_tree[1];
			if (j - k + 1 >= 0) {
				upd_range(0, m - 1, -vals[i][j - k + 1] - vals[i + 1][j - k + 1]);
				upd_range(j - k + 1, j, vals[i][j - k + 1]);
			}
		}
	}
	cout << *max_element(dp, dp + m) << '\n';
}