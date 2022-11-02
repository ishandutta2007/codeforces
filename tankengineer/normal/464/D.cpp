#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int BAR = 700;

int n, k;

double dp[2][BAR];

int main() {
	scanf("%d%d", &n, &k);
	int cur = 0;
	memset(dp[cur], 0, sizeof(dp[cur]));
	for (int i = 1; i <= n; ++i) {
		int nxt = cur ^ 1;
		for (int j = 1; j < BAR; ++j) {
			dp[nxt][j] = dp[cur][j] * (k - 1);
			if (j + 1 < BAR) {
				dp[nxt][j] += (dp[cur][j + 1] + j) / (j + 1);
			} else {
				dp[nxt][j] += (dp[cur][j] + j) / (j + 1);
			}
			dp[nxt][j] += (dp[cur][j] + (double)(1 + j) / 2) * j / (j + 1);
			dp[nxt][j] /= k;
		}
		cur = nxt;
	}
	double ans = k * dp[cur][1];
	printf("%.12f\n", ans);
	return 0;
}