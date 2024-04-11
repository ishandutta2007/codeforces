#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 5e3 + 1;

int dp[MX][MX];

int add(int a, int b) {
	int res = a + b;
	return res < M ? res : res - M;
}

int mul(int a, int b) {
	return (long long) a * b % M;
}

int modpow(int a, int b) {
	if (!b)
		return 1;
	if (b % 2)
		return mul(a, modpow(a, b - 1));
	int tmp = modpow(a, b / 2);
	return mul(tmp, tmp);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	dp[0][0] = 1;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= k && j <= n; ++j) {
			dp[i][j] = add(mul(dp[i - 1][j - 1], n - j + 1), mul(dp[i - 1][j], j));
		}
	}

	int ans = 0;
	int inv = modpow(m, M - 2);
	for (int i = 1; i <= k; ++i) {
		ans = add(ans, mul(modpow(inv, i), dp[k][i]));
	}
	cout << ans << '\n';
}