#include <iostream>
#define int long long

using namespace std;

const int MAX_N = 2e5 + 7, M = 1e9 + 7;
int dp[MAX_N][3];

int calc_mod(int n, int x) {
	int res = n / 3;
	if (n % 3 >= x) res++;
	return res;
}

signed main() {
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	int cnt_0 = (r / 3) - ((l - 1) / 3);
	int cnt_1 = calc_mod(r, 1) - calc_mod(l - 1, 1);
	int cnt_2 = calc_mod(r, 2) - calc_mod(l - 1, 2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * cnt_0) % M;
			dp[i + 1][(j + 1) % 3] = (dp[i + 1][(j + 1) % 3] + dp[i][j] * cnt_1) % M;
			dp[i + 1][(j + 2) % 3] = (dp[i + 1][(j + 2) % 3] + dp[i][j] * cnt_2) % M;
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}