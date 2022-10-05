#include<bits/stdc++.h>
#define ll long long

const int N = 110;
const ll INF = 0x7f7f7f7f7f7f7f7fll;

int c[N], p[N][N];
int n, m, k;
ll dp[N][N][N];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			scanf("%d", &p[i][j]);
		}
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= i; ++ j){
			for (int k = 0; k <= m; ++ k){
				if (dp[i][j][k] == INF){
					continue;
				}
				if (c[i + 1]){
					if (c[i + 1] == k){
						dp[i + 1][j][k] = std::min(dp[i + 1][j][k], dp[i][j][k]);
					}
					else{
						ll &x = dp[i + 1][j + 1][c[i + 1]];
						x = std::min(x, dp[i][j][k]);
					}
					continue;
				}
				for (int jj = 1; jj <= m; ++ jj){
					if (jj == k){
						dp[i + 1][j][k] = std::min(dp[i + 1][j][k], dp[i][j][k] + p[i + 1][jj]);
					}
					else{
						ll &x = dp[i + 1][j + 1][jj];
						x = std::min(x, dp[i][j][k] + p[i + 1][jj]);
					}
				}
			}
		}
	}
	ll min = INF;
	for (int i = 1; i <= m; ++ i){
		min = std::min(min, dp[n][k][i]);
	}
	return printf("%I64d\n", min == INF ? -1 : min), 0;
}