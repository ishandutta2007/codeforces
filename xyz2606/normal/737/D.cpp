#include<bits/stdc++.h>
using namespace std;
int dp[2 * 4001 * 4001 * 2];
#define _(x, i, j, k) ((x) * (4001 * 4001 * 2) + (i) * (4001 * 2) + (j) * 2 + (k))
int s[4001];
int a[4001];
int main() {
	int n;
	scanf("%d", &n);
//n = 4000;
	s[0] = 0;
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	memset(dp, 0x80, sizeof(dp));
	int cur(0);
	for(int k(100); k >= 1; k--) {
		int mn(k == 1 ? 0 : k * (k - 1) / 2);
		int os(k % 2 == 1 ? k / 2 * (k + 1) / 2 : k / 2 * k / 2 - 1);
		//2 * i >= n - len + 2
		//0 : n - j >= i - 1, i - 1 >= n - j - k
		//1 : n - j <= i + 1, i - 1 - k <= n - j
		//len
		for(int len(0); len <= n; len++) {
			for(int i(1); i + len - 1 <= n; i++) {
				int j(i + len - 1);
				if(abs(i - 1 - n + j) <= k) {
				}else {
					continue;
				}
				//printf("%d %d %d %d\n", len, i, os, n);
				if(len < k) {
					dp[_(cur, i, j, 0)] = dp[_(cur, i, j, 1)] = s[i - 1] - (s[n] - s[j]);
				}else {
					dp[_(cur, i, j, 0)] = dp[_(cur, i + k, j, 1)];
					dp[_(cur, i, j, 1)] = dp[_(cur, i, j - k, 0)];
					if(k != 100 && len >= k + 1) {
						dp[_(cur, i, j, 0)] = max(dp[_(cur, i, j, 0)], dp[_(cur ^ 1, i + k + 1, j, 1)]);
						dp[_(cur, i, j, 1)] = min(dp[_(cur, i, j, 1)], dp[_(cur ^ 1, i, j - k - 1, 0)]);
					}
					//printf("%d %d %d %d %d\n", k, i, j, dp[cur][i][j][0], dp[cur][i][j][1]);
				}
			}
		}
		cur ^= 1;
	}
	//printf("%d\n", clock());
	cout << dp[_(cur ^ 1, 1, n, 0)] << endl;
}