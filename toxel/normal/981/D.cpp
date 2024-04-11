#include<bits/stdc++.h>

const int N = 60;
typedef long long ll;

bool dp[N][N];
ll a[N], pre[N];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	ll now = 0;
	for (int i = 60; i >= 0; -- i){
		now |= 1ll << i;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = true;
		for (int j = 0; j < k; ++ j){
			for (int u = 1; u <= n; ++ u){
				for (int v = 0; v < u; ++ v){
					dp[j + 1][u] = dp[j + 1][u] || dp[j][v] && ((now & pre[u] - pre[v]) == now);
				}
			}
		}
		if (!dp[k][n]){
			now ^= 1ll << i;
		}
	}
	printf("%I64d\n", now);
	return 0;
}