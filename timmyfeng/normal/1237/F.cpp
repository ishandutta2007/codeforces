#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 3600 + 1;

int fact[MX], fact_inv[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

void calc(vector<vector<int>>& dp, const vector<bool>& bad) {
	dp[0][0] = 1;
	for (int i = 1; i < int(dp.size()); ++i) {
		for (int j = 0; j < int(dp[0].size()); ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j && i >= 2 && !bad[i] && !bad[i - 1]) {
				dp[i][j] = add(dp[i][j], dp[i - 2][j - 1]);
			}
		}
	}
}

int cnk(int n, int k) {
	if (n < 0 || n < k || k < 0)
		return 0;
	return mul(fact[n], mul(fact_inv[n - k], fact_inv[k]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
	}
	for (int i = 1; i < MX; ++i) {
		fact[i] = mul(fact[i - 1], i);
		fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
	}

	int h, w, n;
	cin >> h >> w >> n;
	vector<bool> bad_row(h + 1), bad_col(w + 1);
	for (int i = 0; i < 2 * n; ++i) {
		int r, c;
		cin >> r >> c;
		bad_row[r] = true;
		bad_col[c] = true;
	}

	int cnt_row = h - count(bad_row.begin(), bad_row.end(), true);
	vector<vector<int>> dp_row(h + 1, vector<int>(max(h, w) + 1));
	calc(dp_row, bad_row);

	int cnt_col = w - count(bad_col.begin(), bad_col.end(), true);
	vector<vector<int>> dp_col(w + 1, vector<int>(max(h, w) + 1));
	calc(dp_col, bad_col);

	int ans = 0;
	for (int i = 0; i <= max(h, w); ++i) {
		for (int j = 0; j <= max(h, w); ++j) {
			ans = add(ans, mul(mul(
					mul(dp_row[h][i], cnk(cnt_row - i * 2, j)),
					mul(dp_col[w][j], cnk(cnt_col - j * 2, i))),
					mul(fact[i], fact[j])));
		}
	}
	cout << ans << "\n";
}