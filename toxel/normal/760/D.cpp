#include<bits/stdc++.h>

const int N = 100010;

int dp[N];
int n;
std::map <int, int> Hash;

int main(){
	scanf("%d", &n);
	dp[0] = 0;
	for (int i = 1, t; i <= n; ++ i){
		scanf("%d", &t);
		Hash[t] = i;
		dp[i] = dp[i - 1] + 20;
		auto u = Hash.lower_bound(t - 89);
		dp[i] = std::min(dp[i], dp[u -> second - 1] + 50);
		u = Hash.lower_bound(t - 1439);
		dp[i] = std::min(dp[i], dp[u -> second - 1] + 120);
		printf("%d\n", dp[i] - dp[i - 1]);
	}
	return 0;
}