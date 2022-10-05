#include<bits/stdc++.h>

const int N = 110;

bool dp[N][N][N];
char s[N];
int n, K;

int main(){
	scanf("%d%d%s", &n, &K, s);
	dp[0][0][0] = true;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= n; ++ j){
			for (int k = 0; k <= n; ++ k){
				if (!dp[i][j][k]){
					continue;
				}
				if (s[i] == 'Y' || s[i] == '?'){
					dp[i + 1][j][0] = true;
				}
				if (s[i] == 'N' || s[i] == '?'){
					dp[i + 1][std::max(j, k + 1)][k + 1] = true;
				}
			}
		}
	}
	for (int i = 0; i <= n; ++ i){
		if (dp[n][K][i]){
			return printf("YES\n"), 0;
		}
	}
	return printf("NO\n"), 0;
}