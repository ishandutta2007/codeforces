#include<bits/stdc++.h>

const int N = 5010;
const int M = 100010;

int dp[N][N];
int a[N], maxcnt[M], maxmod[10];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int j = 0; j <= n; ++ j){
		memset(maxmod, 0, sizeof(maxmod));
		for (int i = 1; i <= n; ++ i){
			maxcnt[a[i]] = 0;
		}
		for (int i = 0; i <= n; ++ i){
			if (i < j){
				dp[i][j] = dp[j][i];
			}
			else if (i > j){
				dp[i][j] = std::max(std::max(dp[0][j], maxmod[a[i] % 7]), std::max(maxcnt[a[i] + 1], maxcnt[a[i] - 1])) + 1;
			}
			if (i){
				maxcnt[a[i]] = std::max(maxcnt[a[i]], dp[i][j]);
				maxmod[a[i] % 7] = std::max(maxmod[a[i] % 7], dp[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			ans = std::max(ans, dp[i][j]);
		}
	}
	return printf("%d\n", ans), 0;
}