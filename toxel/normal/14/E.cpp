#include<bits/stdc++.h>

const int N = 25;
typedef long long ll;

ll dp[N][N][N][4][4];

int main(){
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 0; i < 4; ++ i){
		for (int j = 0; j < 4; ++ j){
			if (i == j) continue;
			dp[1][0][0][i][j] = 1;
		}
	}
	for (int i = 2; i < n; ++ i){
		for (int j = 0; j <= n; ++ j){
			for (int k = 0; k <= n; ++ k){
				for (int u = 0; u < 4; ++ u){
					for (int v = 0; v < 4; ++ v){
						if (u == v) continue;
						for (int w = 0; w < 4; ++ w){
							if (v == w) continue;
							dp[i][j + (u < v && v > w)][k + (u > v && v < w)][v][w] += dp[i - 1][j][k][u][v];
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 4; ++ i){
		for (int j = 0; j < 4; ++ j){
			ans += dp[n - 1][t][t - 1][i][j];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}