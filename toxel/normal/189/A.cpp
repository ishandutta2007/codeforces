#include<bits/stdc++.h>

const int N = 4010;

int dp[N];

int main(){
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; ++ i){
		if (i - a >= 0 && dp[i - a] != -1){
			dp[i] = std::max(dp[i], dp[i - a] + 1);
		}
		if (i - b >= 0 && dp[i - b] != -1){
			dp[i] = std::max(dp[i], dp[i - b] + 1);
		}
		if (i - c >= 0 && dp[i - c] != -1){
			dp[i] = std::max(dp[i], dp[i - c] + 1);
		}
	}
	return printf("%d\n", dp[n]), 0;
}