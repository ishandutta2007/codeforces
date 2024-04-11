#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
int n, k, dp[55][55][2], cb[55][55], INV;

int rev(int a) {
	return a == 1 ? 1 : (long long)(MOD - MOD / a) * rev(MOD % a) % MOD;
}

int main() {
	INV = rev(2);
	for (int i = 0; i <= 50; ++i) {
		cb[i][0] = cb[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			cb[i][j] = (cb[i - 1][j] + cb[i - 1][j - 1]) % MOD;
		}
	}
	dp[1][0][0] = 1;
	dp[0][0][1] = 1;
	for (int n = 2; n <= 50; ++n) {
		for (int left = 0; left < n; ++left) {
			int right = n - 1 - left;
			for (int lm = 0; lm * 2 <= left; ++lm) {
				for (int rm = 0; rm * 2 <= right; ++rm) {
					for (int cl = 0; cl < 2; ++cl) {
						for (int cr = 0; cr < 2; ++cr) {
							int cn = !(cl && cr);
							(dp[n][lm + rm + cn][cn] += (long long)dp[left][lm][cl] * dp[right][rm][cr] % MOD * n % MOD * cb[n - 1][left] % MOD * INV % MOD) %= MOD;
						}
					}
				}
			}
		}
	}
	int n;
	scanf("%d%d", &n, &k);
	int ans = (dp[n][k][0] + dp[n][k][1]) % MOD;
	ans = (long long)ans * rev(n) % MOD;
	printf("%d\n", ans);
	return 0;
}