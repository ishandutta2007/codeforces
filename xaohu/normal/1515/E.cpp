#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int n, P, fac[405], dp[405][405], C[405][405];

int main() {
	cin >> n >> P;
	rep(i, 0, n) {
		C[i][0] = C[i][i] = 1;
		rep(j, 1, i - 1)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	long long ans = 0;
	rep(i, 1, n)
		rep(j, 1, n) {
			long long ways = 1;
			rep(k, 1, i) {
				if (k == i) {
					if (i == j)
						dp[i][j] = (dp[i][j] + ways);
				}
				else if (j >= k) {
					dp[i][j] = (dp[i][j] + ways * dp[i - k - 1][j - k] % P * C[j][k] % P) % P;
				}
				ways = 2 * ways % P;
			}
			if (i == n)
				ans = (ans + dp[i][j]) % P;
		}
	cout << ans << "\n";
	return 0;
}