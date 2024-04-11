#include<bits/stdc++.h>

const int N = 110;
const int INF = 0x7f7f7f7f;
const int M = 10010;

int min[N][N], a[N], pre[N];
int dp[M];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	memset(min, 0x7f, sizeof(min));
	int sum = 0, cnt = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		cnt += x;
		for (int j = 1; j <= x; ++ j){
			scanf("%d", &pre[j]);
			sum += pre[j];
			pre[j] += pre[j - 1];
		}
		min[i][0] = 0;
		for (int j = 1; j <= x; ++ j){
			for (int k = 0; k + j <= x; ++ k){
				min[i][j] = std::min(pre[k + j] - pre[k], min[i][j]);
			}
		}
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = M - 1; j >= 0; -- j){
			if (dp[j] == INF) continue;
			for (int k = 0; k < N; ++ k){
				if (min[i][k] == INF) break;
				if (j + k >= M) continue;
				dp[j + k] = std::min(dp[j + k], dp[j] + min[i][k]);
			}
		}
	}
	printf("%d\n", sum - dp[cnt - m]);
	return 0;
}