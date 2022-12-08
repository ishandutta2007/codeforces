#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9, N = 311111;
int dp[N][31], n, a[N];
void MIN(int &a, int b) {if (a > b) a = b;}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i <= n; ++i) 
		for (int j = 0; j <= 30; ++j) dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 30; ++j) {
			int t = min(j, a[i] / 100);
			if (j) MIN(dp[i][j - t], dp[i - 1][j] + a[i] / 100 - t);
			t = j + a[i] / 1000;
			if (t <= 30) MIN(dp[i][t], dp[i - 1][j] + a[i] / 100);
		}
	}
	int ans = inf;
	for (int j = 0; j <= 30; ++j) ans = min(ans, dp[n][j]);
	printf("%d\n", ans * 100);
	return 0;
}