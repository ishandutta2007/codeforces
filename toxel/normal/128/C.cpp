#include<bits/stdc++.h>

const int N = 1010;
const int moder = 1e9 + 7;

int n, m, k;
int dp[N][N], pre[N][N];

int main(){
	for (int i = 1; i < N; ++ i){
		dp[i][0] = 1;
		pre[i][0] = i;
	}
	for (int i = 1; i < N; ++ i){
		for (int j = i << 1 | 1; j < N; ++ j){
			dp[j][i] = dp[j - 1][i] + pre[j - 2][i - 1];
			dp[j][i] -= dp[j][i] >= moder ? moder : 0;
			pre[j][i] = pre[j - 1][i] + dp[j][i];
			pre[j][i] -= pre[j][i] >= moder ? moder : 0;
		}
	}
	scanf("%d%d%d", &n, &m, &k);
	int ans = 1ll * dp[n][k] * dp[m][k] % moder;
	printf("%d\n", ans);
	return 0;
}