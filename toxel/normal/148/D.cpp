#include<bits/stdc++.h>

const int N = 1010;

double dp[N][N][2];

int main(){
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < 2; ++ j){
			dp[0][i][j] = j ? 1.0 : 0.0;
		}
	}
	for (int i = 1; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			dp[i][j][0] = 1.0 * i / (i + j) + (j ? 1.0 * j / (i + j) * (1.0 - dp[i][j - 1][1]) : 0.0);
			dp[i][j][1] = 1.0 * i / (i + j) + 1.0 * j / (i + j) * (j ? 1.0 * i / (i + j - 1) * (1 - dp[i - 1][j - 1][0]) + 1.0 * (j - 1) / (i + j - 1) * (j > 1 ? (1 - dp[i][j - 2][0]) : 0.0) : 0.0);
		}
	}
	int w, b;
	scanf("%d%d", &w, &b);
	printf("%.12lf\n", dp[w][b][0]);
	return 0;
}