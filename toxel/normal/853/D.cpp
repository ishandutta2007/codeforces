#include<bits/stdc++.h>

const int N = 300010;
const int M = 50;
const int INF = 0x3f3f3f3f;

int dp[N][M], a[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		a[i] /= 100;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < M; ++ j){
			if (dp[i - 1][j] == INF){
				continue;
			}
			if (a[i] / 10 + j < M){
				dp[i][j + a[i] / 10] = std::min(dp[i][j + a[i] / 10], dp[i - 1][j] + a[i]);
			}
			int x = std::min(a[i], j);
			dp[i][j - x] = std::min(dp[i][j - x], dp[i - 1][j] + a[i] - x);
		}
	}
	int min = INT_MAX;
	for (int i = 0; i < M; ++ i){
		min = std::min(min, dp[n][i]);
	}
	return printf("%d\n", min * 100), 0;
}