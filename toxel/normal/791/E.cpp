#include<bits/stdc++.h>

const int N = 80;

int dp[N][N][N][2], prev[N], prek[N], prex[N], revv[N], revk[N], revx[N];
int n;
char s[N];

int main(){
	scanf("%d%s", &n, s + 1);
	int v = 0, K = 0, x = 0;
	for (int i = 1; i <= n; ++ i){
		prev[i] = prev[i - 1];
		prek[i] = prek[i - 1];
		prex[i] = prex[i - 1];
		if (s[i] == 'V'){
			++ v;
			++ prev[i];
			revv[v] = i;
		}
		else if (s[i] == 'K'){
			++ K;
			++ prek[i];
			revk[K] = i;
		}
		else{
			++ x;
			++ prex[i];
			revx[x] = i;
		}
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= v; ++ i){
		for (int j = 0; j <= K; ++ j){
			for (int k = 0; k <= x; ++ k){
				if (i){
					int sit = revv[i];
					int sum = std::min(prev[sit], i) + std::min(prek[sit], j) + std::min(prex[sit], k);
					dp[i][j][k][1] = std::min(dp[i][j][k][1], std::min(dp[i - 1][j][k][0], dp[i - 1][j][k][1]) + sit - sum);
				}
				if (j){
					int sit = revk[j];
					int sum = std::min(prev[sit], i) + std::min(prek[sit], j) + std::min(prex[sit], k);
					dp[i][j][k][0] = std::min(dp[i][j][k][0], dp[i][j - 1][k][0] + sit - sum);
				}
				if (k){
					int sit = revx[k];
					int sum = std::min(prev[sit], i) + std::min(prek[sit], j) + std::min(prex[sit], k);
					dp[i][j][k][0] = std::min(dp[i][j][k][0], std::min(dp[i][j][k - 1][0], dp[i][j][k - 1][1]) + sit - sum);
				}
			}
		}
	}
	return printf("%d\n", std::min(dp[v][K][x][0], dp[v][K][x][1])), 0;
}