#include<bits/stdc++.h>

const int N = 2010;
typedef long long ll;

ll dp[N * 3];
int n;
int t[N], c[N];

int main(){
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; ++ i){
		scanf("%d%d", &t[i], &c[i]);
		for (int j = N * 3 - 1; j >= 0; -- j){
			if (j + t[i] + 1 >= 3 * N) continue;
			dp[j + t[i] + 1] = std::min(dp[j + t[i] + 1], dp[j] + c[i]);
		}
	}
	ll ans = LLONG_MAX;
	for (int i = n; i < N * 3; ++ i){
		ans = std::min(ans, dp[i]);
	}
	return printf("%I64d\n", ans), 0;
}