#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 1;
const int LOG_N = 20 + 1;
const int M = 1e9 + 7;

int sieve[MX], dp[LOG_N][MX], pow_2[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < MX; ++i) {
		if (sieve[i])
			continue;
		for (int j = i; j < MX; j += i) {
			sieve[j] = i;
		}
	}

	for (int i = 0; i < LOG_N; ++i) {
		for (int j = 0; j < MX; ++j) {
			if (!i) {
				dp[i][j] = 1;
			} else if (!j) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = add(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	pow_2[0] = 1;
	for (int i = 1; i < MX; ++i) {
		pow_2[i] = add(pow_2[i - 1], pow_2[i - 1]);
	}

	int q;
	cin >> q;

	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = pow_2[y - 1];
		while (x > 1) {
			int p = sieve[x];
			int cnt = 0;
			while (x % p == 0) {
				x /= p;
				++cnt;
			}
			ans = mul(ans, dp[cnt][y]);
		}
		cout << ans << '\n';
	}
}