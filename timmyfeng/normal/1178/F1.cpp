#include <bits/stdc++.h> 
using namespace std;

const int MX = 500 + 5;
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

int a[MX];
int dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			dp[i][j] = 1;
		}
	}

	for (int l = 2; l <= n; ++l) {
		for (int i = 1; i + l - 1 <= n; ++i) {
			int j = i + l - 1;

			int ndx = min_element(a + i, a + j + 1) - a;

			int left = 0;
			for (int k = i; k <= ndx; ++k) {
				left = add(left, mul(dp[i][k - 1], dp[k][ndx - 1]));
			}

			int right = 0;
			for (int k = ndx; k <= j; ++k) {
				right = add(right, mul(dp[ndx + 1][k], dp[k + 1][j]));
			}

			dp[i][j] = mul(left, right);
		}
	}

	cout << dp[1][n] << "\n";
}