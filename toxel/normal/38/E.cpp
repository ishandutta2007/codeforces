#include<bits/stdc++.h>

const int N = 3010;
typedef std::pair <int, int> pii;
typedef long long ll;

pii p[N];
ll dp[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1, x, c; i <= n; ++ i){
		scanf("%d%d", &x, &c);
		p[i] = {x, c};
	}
	std::sort(p + 1, p + n + 1);
	memset(dp, 0x3f, sizeof(dp));
	dp[1] = p[1].second;
	for (int i = 2; i <= n; ++ i){
		dp[1] += p[i].first - p[1].first;
	}
	for (int i = 2; i <= n; ++ i){
		for (int j = 1; j <= i - 1; ++ j){
			dp[i] = std::min(dp[i], dp[j] + p[i].second - 1ll * (p[i].first - p[j].first) * (n - i + 1));
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++ i){
		ans = std::min(ans, dp[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}