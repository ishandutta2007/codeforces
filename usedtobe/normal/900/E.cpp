#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
int pc[N], n, m;
int pre[2][N][2], dp[N], cost[N];
char s[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%d", &m);
	for (int i = 1; i <= n; ++i) {
		for (int t = 0; t < 2; ++t)
			for (int j = 0; j < 2; ++j) 
				pre[t][i][j] += pre[t][i - 1][j];
		if (s[i] != '?') pre[i & 1][i][s[i] - 'a']++;
		pc[i] = pc[i - 1];
		if (s[i] == '?') pc[i]++;
		if (i < m) continue;
		dp[i] = dp[i - 1];
		cost[i] = cost[i - 1];
		if (m & 1) {
			if (pre[i & 1][i][1] - pre[i & 1][i - m][1]) continue;
			if (pre[(i & 1) ^ 1][i - 1][0] - pre[(i & 1) ^ 1][i - m][0]) continue;
		} else {
			if (pre[i & 1][i][0] - pre[i & 1][i - m][0]) continue;
			if (pre[(i & 1) ^ 1][i - 1][1] - pre[(i & 1) ^ 1][i - m][1]) continue;
		}
		if (dp[i] < dp[i - m] + 1 || (dp[i] == dp[i - m] + 1 && cost[i] > cost[i - m] + pc[i] - pc[i - m])) {
			dp[i] = dp[i - m] + 1;
			cost[i] = cost[i - m] + pc[i] - pc[i - m];
		}
	}
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		if (dp[i] > dp[p] || (dp[p] == dp[i] && cost[i] < cost[p])) {
			p = i;
		}
	}
	printf("%d\n", cost[p]);
	return 0;
}