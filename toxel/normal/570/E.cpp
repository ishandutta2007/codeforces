#include<bits/stdc++.h>

const int N = 510;
const int moder = 1e9 + 7;

int dp[2][N][N];
int n, m;
char s[N][N];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	if (s[0][0] != s[n - 1][m - 1]){
		return printf("0\n"), 0;
	}
	dp[0][0][n - 1] = 1;
	int now = 0;
	for (int i = 1; i <= n + m - 2 >> 1; ++ i){
		memset(dp[now ^ 1], 0, sizeof(dp[now]));
		for (int j = 0; j < i; ++ j){
			for (int k = n - i; k < n; ++ k){
				int y1 = i - j - 1, y2 = n + m - k - i - 1;
				if (k < j || y2 < y1 || y2 >= m){
					continue;
				}
				if (j + 1 <= k - 1 && s[j + 1][y1] == s[k - 1][y2]){
					int &x = dp[now ^ 1][j + 1][k - 1];
					x = (x + dp[now][j][k]) % moder;
				}
				if (j <= k - 1 && y1 + 1 <= y2 && s[j][y1 + 1] == s[k - 1][y2]){
					int &x = dp[now ^ 1][j][k - 1];
					x = (x + dp[now][j][k]) % moder;
				}
				if (j + 1 <= k && y1 <= y2 - 1 && s[j + 1][y1] == s[k][y2 - 1]){
					int &x = dp[now ^ 1][j + 1][k];
					x = (x + dp[now][j][k]) % moder;
				}
				if (y1 + 1 <= y2 - 1 && s[j][y1 + 1] == s[k][y2 - 1]){
					int &x = dp[now ^ 1][j][k];
					x = (x + dp[now][j][k]) % moder;
				}
			}
		}
		now ^= 1;
	}
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N; ++ j){
			ans = (ans + dp[now][i][j]) % moder;
		}
	}
	return printf("%d\n", ans), 0;
}