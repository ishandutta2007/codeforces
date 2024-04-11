#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

const int N = 1 << 20, LOG = 20;

int dp[N | 1];

const int MOD = 1000000007;

int main() {
	for (int i = 0; i < N; ++i) {
		dp[i] = 1;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		(dp[a] <<= 1) %= MOD;
	}
	for (int i = 0; i < LOG; ++i) {
		for (int j = N - 1; j >= 0; --j) {
			if (j >> i & 1) {
				dp[j ^ (1 << i)] = (long long)dp[j ^ (1 << i)] * dp[j] % MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int sign = __builtin_popcount(i) & 1 ? -1 : 1;
		ans = ((ans + dp[i] * sign) % MOD + MOD) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}