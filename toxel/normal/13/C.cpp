#include<bits/stdc++.h>

const int N = 5010;
typedef long long ll;

int a[N], b[N];
ll dp[2][N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	std::sort(b, b + n);
	int m = std::unique(b, b + n) - b;
	for (int i = 0; i < m; ++ i){
		dp[0][i] = std::abs(b[i] - a[0]);
	}
	int now = 0;
	for (int i = 1; i < n; ++ i){
		ll min = LLONG_MAX;
		for (int j = 0; j < m; ++ j){
			min = std::min(dp[now][j], min);
			dp[now ^ 1][j] = min + std::abs(b[j] - a[i]);
		}
		now ^= 1;
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i < m; ++ i){
		ans = std::min(ans, dp[now][i]);
	}
	return printf("%I64d\n", ans), 0;
}