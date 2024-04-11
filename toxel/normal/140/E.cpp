#include<bits/stdc++.h>

const int N = 5010;
const int M = 1000010;

int dp1[N][N], dp2[N][N], l[M], dp[2][N];
int n, m, moder;

int main(){
	scanf("%d%d%d", &n, &m, &moder);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &l[i]);
	}
	dp1[0][0] = 1;
	for (int i = 1; i < N; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp1[i][j] = (1ll * dp1[i - 1][j] * (j - 1) + 1ll * dp1[i - 1][j - 1] * (m - j + 1)) % moder;
		}
	}
	dp2[0][0] = 1;
	for (int i = 1; i < N; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp2[i][j] = (1ll * dp2[i - 1][j] * (j - 1) + 1ll * dp2[i - 1][j - 1] * j) % moder;
		}
	}
	dp[0][0] = 1;
	int now = 0, pre = 1;
	for (int i = 0; i < n; ++ i){
		now ^= 1;
		int sum = 0;
		for (int j = 1; j <= std::min(l[i], m); ++ j){
			dp[now][j] = 1ll * pre * dp1[l[i]][j] % moder;
			if (i && j <= std::min(l[i - 1], m)){
				dp[now][j] = (dp[now][j] - 1ll * dp[now ^ 1][j] * dp2[l[i]][j]) % moder;
				dp[now][j] += dp[now][j] < 0 ? moder : 0;
			}
			sum += dp[now][j];
			sum -= sum >= moder ? moder : 0;
		}
		pre = sum;
	}
	printf("%d\n", pre % moder);
	return 0;
}