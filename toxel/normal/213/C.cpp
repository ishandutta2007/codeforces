#include<bits/stdc++.h>

const int N = 310;

int a[N][N];
int dp[N << 1][N][N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			scanf("%d", &a[i][j]);
		}
	}
	dp[0][0][0] = a[0][0];
	for (int i = 1; i <= 2 * n - 2; ++ i){
		for (int x1 = 0; x1 < n; ++ x1){
			int y1 = i - x1;
			if (y1 < 0 || y1 >= n) continue;
			for (int x2 = 0; x2 < n; ++ x2){
				int y2 = i - x2;
				if (y2 < 0 || y2 >= n) continue;
				dp[i][x1][x2] = x1 == x2 ? a[x1][y1] : a[x1][y1] + a[x2][y2];
				int max = INT_MIN;
				for (int j = 0; j < 2; ++ j){
					int x3 = j ? x1 : x1 - 1;
					int y3 = j ? y1 - 1 : y1;
					if (x3 < 0 || y3 < 0) continue;
					for (int k = 0; k < 2; ++ k){
						int x4 = k ? x2 : x2 - 1;
						int y4 = k ? y2 - 1 : y2;
						if (x4 < 0 || y4 < 0) continue;
						max = std::max(max, dp[i - 1][x3][x4]);
					}
				}
				dp[i][x1][x2] += max;
			}
		}
	}
	printf("%d\n", dp[2 * n - 2][n - 1][n - 1]);
	return 0;
}