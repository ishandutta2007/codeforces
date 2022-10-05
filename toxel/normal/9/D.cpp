#include<bits/stdc++.h>

const int N = 40;

long long dp[N][N];
int n, h;

int main(){
	scanf("%d%d", &n, &h);
	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; ++ i){
		for (int j = 0; j < i; ++ j){
			for (int k = 0; k < i; ++ k){
				for (int ii = 0; ii < i; ++ ii){
					dp[i][std::max(j, k) + 1] += dp[ii][j] * dp[i - 1 - ii
					][k];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = h; i <= n; ++ i){
		ans += dp[n][i];
	}
	return printf("%I64d\n", ans), 0;
}