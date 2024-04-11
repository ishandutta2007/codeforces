#include<bits/stdc++.h>

const int N = 110;
const int M = 20;
const int moder = 1e8;

int dp[N << 1][N][M][M];

int main(){
	int n1, n2, k1, k2;
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	dp[0][0][0][0] = 1;
	for (int i = 0; i < n1 + n2; ++ i){
		for (int j = 0; j <= n1; ++ j){
			for (int u = 0; u <= k1; ++ u){
				for (int v = 0; v <= k2; ++ v){
					if (j < n1 && u < k1){
						int &x = dp[i + 1][j + 1][u + 1][0];
						x = (x + dp[i][j][u][v]) % moder;
					}
					if (i - j < n2 && v < k2){
						int &x = dp[i + 1][j][0][v + 1];
						x = (x + dp[i][j][u][v]) % moder;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= k1; ++ i){
		for (int j = 0; j <= k2; ++ j){
			ans = (ans + dp[n1 + n2][n1][i][j]) % moder;
		}
	}
	printf("%d\n", ans);
	return 0;
}