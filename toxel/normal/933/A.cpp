#include<bits/stdc++.h>

const int N = 2010;

int dp[10][N], pre[10][N], suf[10][N], a[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		pre[1][i] = pre[1][i - 1] + (a[i] == 1);
		pre[2][i] = pre[2][i - 1] + (a[i] == 2);
	}
	for (int i = n; i >= 1; -- i){
		suf[1][i] = suf[1][i + 1] + (a[i] == 1);
		suf[2][i] = suf[2][i + 1] + (a[i] == 2);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++ i){
		ans = std::max(ans, pre[1][i] + suf[2][i + 1]);
	}
	for (int l = 1; l <= n; ++ l){
		memset(dp, 0, sizeof(dp));
		for (int r = l; r <= n; ++ r){
			if (r == l){
				dp[a[l]][l] = 1;
			}
			else{
				dp[2][r] = dp[2][r - 1] + (a[r] == 2);
				dp[1][r] = std::max(dp[2][r - 1], dp[1][r - 1]) + (a[r] == 1);
			}
			ans = std::max(std::max(dp[1][r], dp[2][r]) + pre[1][l - 1] + suf[2][r + 1], ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}