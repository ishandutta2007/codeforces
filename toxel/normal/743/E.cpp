#include<bits/stdc++.h>

const int N = 1010;
const int M = 8;

int a[M] = {1, 2, 3, 4, 5, 6, 7, 8};
int pre[M][N], n, num[N], dp[N][1 << M];
int Hash[M][N];

int main(){
	memset(Hash, -1, sizeof(Hash));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &num[i]);
		for (int j = 0; j < M; ++ j){
			pre[j][i] = pre[j][i - 1] + (j == num[i] - 1);
		}
	}
	for (int i = 0; i < M; ++ i){
		for (int j = n; j >= 0; -- j){
			Hash[i][pre[i][j]] = j;
		}
	}
	int ans = 0;
	int left = -1, right = n;
	while (left < right){
		memset(dp, -1, sizeof(dp));
		int mid = left + right + 1 >> 1;
		dp[0][0] = 0;
		for (int i = 0; i <= n; ++ i){
			if (i){
				for (int j = 0; j < 1 << M; ++ j){
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
				}
			}
			for (int j = 0; j < 1 << M; ++ j){
				if (dp[i][j] == -1){
					continue;
				}
				for (int k = 0; k < M; ++ k){
					if (!(j >> k & 1)){
						int sit = Hash[k][pre[k][i] + mid];
						if (sit == -1){
							continue;
						}
						int &x = dp[sit][j | (1 << k)];
						x = std::max(x, dp[i][j]);
						sit = Hash[k][pre[k][i] + mid + 1];
						int &y = dp[sit][j | (1 << k)];
						y = std::max(y, dp[i][j] + 1);
					}
				}
			}
		}
		if (dp[n][(1 << M) - 1] != -1){
			ans = std::max(ans, mid * M + dp[n][(1 << M) - 1]);
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	return printf("%d\n", ans), 0;
}