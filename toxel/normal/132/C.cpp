#include<bits/stdc++.h>

const int N = 110;

bool dp[N][N][N << 1][2];
char s[N];
int n;

int main(){
	scanf("%s%d", s, &n);
	int len = strlen(s);
	dp[0][0][N][0] = true;
	for (int i = 0; i < len; ++ i){
		for (int j = 0; j < N; ++ j){
			for (int k = 0; k < N << 1; ++ k){
				for (int u = 0; u < 2; ++ u){
					if (!dp[i][j][k][u]) continue;
					if (s[i] == 'T'){
						dp[i + 1][j][k][u ^ 1] = true;
						dp[i + 1][j + 1][k + (u ? -1 : 1)][u] = true;
					}
					else{
						dp[i + 1][j + 1][k][u ^ 1] = true;
						dp[i + 1][j][k + (u ? -1 : 1)][u] = true;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N << 1; ++ j){
			for (int k = 0; k < 2; ++ k){
				if (i > n || i + n & 1) continue;
				if (dp[len][i][j][k]){
					ans = std::max(std::abs(j - N), ans);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}