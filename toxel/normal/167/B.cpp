#include<bits/stdc++.h>

const int N = 210;

double dp[N][N][N << 1];
int p[N], a[N];

int main(){
	int n, l, k;
	scanf("%d%d%d", &n, &l, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	dp[0][0][k + N] = 1.0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= i; ++ j){
			for (int k = 0; k < N << 1; ++ k){
				dp[i + 1][j][k] += dp[i][j][k] * (100 - p[i]) / 100;
				if (~a[i]){
					int x = k + a[i];
					if (x > N + 200){
						x = N + 200;
					}
					dp[i + 1][j + 1][x] += dp[i][j][k] * p[i] / 100;
				}
				else{
					dp[i + 1][j + 1][k - 1] += dp[i][j][k] * p[i] / 100;
				}
			}
		}
	}
	double ans = 0;
	for (int i = l; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			ans += dp[n][i][j + N];
		}
	}
	return printf("%.10lf\n", ans), 0;
}