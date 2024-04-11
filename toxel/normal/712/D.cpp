#include<bits/stdc++.h>

const int N = 200010;
const int moder = 1e9 + 7;

int dp[N << 1], prefix[N << 1];
int a, b, K, t;

int main(){
	scanf("%d%d%d%d", &a, &b, &K, &t);
	dp[N] = 1;
	for (int i = 1; i <= t; ++ i){
		for (int j = 1; j < N << 1; ++ j){
			prefix[j] = (prefix[j - 1] + dp[j]) % moder;
		}
		for (int k = 0; k < N << 1; ++ k){
			if (k - K < 0 || k + K >= N << 1){
				continue;
			}
			dp[k] = (prefix[k + K] - prefix[k - K - 1] + moder) % moder;
		}
	}
	for (int i = 1; i < N << 1; ++ i){
		prefix[i] = (prefix[i - 1] + dp[i]) % moder;
	}
	int ans = 0;
	for (int i = 0; i < N << 1; ++ i){
		if (!dp[i] || i + a - b - 1 < 0){
			continue;
		}
		ans = (ans + 1ll * dp[i] * prefix[i + a - b - 1]) % moder;
	}
	return printf("%d\n", ans), 0;
}