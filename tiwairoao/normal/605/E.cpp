#include <bits/stdc++.h>

const int N = 1000;

double pro[N + 5][N + 5]; int n;
double dp[N + 5], tmp[N + 5]; bool vis[N + 5];
void update(int x) {
	assert (tmp[x] != 1);
	dp[x] = dp[x] / (1 - tmp[x]), vis[x] = true;
	for (int i = 1; i <= n; i++) if (!vis[i])
		dp[i] += tmp[i] * pro[i][x] * dp[x], tmp[i] *= (1 - pro[i][x]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		scanf("%lf", &pro[i][j]), pro[i][j] /= 100;
	for (int i = 1; i < n; i++) dp[i] = 1, tmp[i] = 1; update(n);
	for (int i = 1; i < n; i++) {
		int x = -1;
		for (int j = 1; j <= n; j++) if (!vis[j])
			if (x == -1 || (tmp[j] != 1 &&
				dp[j] / (1 - tmp[j]) < dp[x] / (1 - tmp[x])))
					x = j;
		update(x);
		if (x == 1) break;
	}
	printf("%.9f\n", dp[1]);
}