#include<bits/stdc++.h>

const int N = 30001;
const int M = 300;

int cnt[N], dp[N][M << 1];
int n, d;

void add(int x, int y, int z){
	int dis = y + d - M;
	if (x + dis >= N){
		return;
	}
	dp[x + dis][y] = std::max(dp[x + dis][y], z + cnt[x + dis]);
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &d);
	int max = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
		max = std::max(max, x);
	}
	dp[d][M] = cnt[d];
	for (int i = d; i < max; ++ i){
		for (int j = 0; j < M << 1; ++ j){
			if (dp[i][j] == -1){
				continue;
			}
			if (j + d - M > 1){
				add(i, j - 1, dp[i][j]);
			}
			add(i, j, dp[i][j]);
			add(i, j + 1, dp[i][j]);
		}
	}
	int ans = 0;
	for (int i = d; i <= max; ++ i){
		for (int j = 0; j < M << 1; ++ j){
			ans = std::max(ans, dp[i][j]);
		}
	}
	return printf("%d\n", ans + cnt[0]), 0;
}