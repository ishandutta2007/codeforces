#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 1000 + 1;
const int MXA = 1e5;

int dp[MX][MX];
int a[MX];

int add(int a ,int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += M;
	}
	return a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	int ans = 0;
	int pre_cnt = 0;
	for (int b = MXA / (k - 1); b; --b) {
		fill(dp[0], dp[0] + k + 1, 0);
		dp[0][0] = 1;

		int pre = 0;
		for (int i = 1; i <= n; ++i) {
			while (pre + 1 < i && a[pre + 1] + b <= a[i]) {
				++pre;
			}

			for (int j = 0; j <= k; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j) {
					dp[i][j] = add(dp[i][j], dp[pre][j - 1]);
				}
			}
		}

		ans = add(ans, mul(b, sub(dp[n][k], pre_cnt)));
		pre_cnt = dp[n][k];
	}
	cout << ans << "\n";
}