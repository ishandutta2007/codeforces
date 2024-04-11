#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int mod = 998244353;
int n, k;
int a[N], dp[N], dpd[N];
int ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int q = 1; q * (k - 1) <= 110000; q++) {
		for (int i = 0; i <= n; i++)
			dp[i] = 0;
		dp[0] = 1;

		for (int j = 1; j <= k; j++) {
			for (int i = 0; i <= n; i++)
				dpd[i] = 0;

			int pre = 0;
			for (int i = 1; i <= n; i++)
				dp[i] = (dp[i] + dp[i - 1]) % mod;

			for (int i = 1; i <= n; i++) {
				while (pre < n && a[pre + 1] <= a[i] - q)
					pre++;
				dpd[i] = dp[pre];
			}
			memcpy(dp, dpd, sizeof dp);
		}

		for (int i = 0; i <= n; i++)
			ans = (ans + dp[i]) % mod;
	}
	printf("%d\n", ans);
}