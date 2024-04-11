#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005, MOD = 1000000007;

int n, k;

int dp[N][N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = j; l <= n; l += j) {
				if ((dp[i][j] += dp[i - 1][l]) >= MOD) {
					dp[i][j] -= MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		(ans += dp[k][i]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}