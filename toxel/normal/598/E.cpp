#include<bits/stdc++.h>

const int N = 32;
const int M = 52;

int dp[N][N][M];

int main(){
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i < N; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp[i][j][0] = 0;
			if (i * j < M) dp[i][j][i * j] = 0;
			for (int k = 1, sz = std::min(i * j, M); k < sz; ++ k){
				for (int u = 1; u < i; ++ u){
					for (int v = 0; v <= k; ++ v){
						dp[i][j][k] = std::min(dp[i][j][k], dp[u][j][v] + dp[i - u][j][k - v] + j * j);
					}
				}
				for (int u = 1; u < j; ++ u){
					for (int v = 0; v <= k; ++ v){
						dp[i][j][k] = std::min(dp[i][j][k], dp[i][u][v] + dp[i][j - u][k - v] + i * i);
					}
				}
			}
			if (i != j){
				for (int k = 0, sz = std::min(i * j + 1, M); k < M; ++ k){
					dp[j][i][k] = dp[i][j][k];
				}
			}
		}
	}
	int test;
	scanf("%d", &test);
	while (test --){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", dp[n][m][k]);
	}
	return 0;
}