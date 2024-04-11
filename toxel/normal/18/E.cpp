#include<bits/stdc++.h>

const int N = 510;
typedef std::pair <int, int> pii;
const int M = 26;

char s[N][N];
int dp[N][M][M];
pii pre[N][M][M];
int cnt[N][2][M];
int prelu[N][M][M], preru[N][M][M], preld[N][M][M], prerd[N][M][M];
pii sitlu[N][M][M], sitru[N][M][M], sitld[N][M][M], sitrd[N][M][M];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++ j){
			++ cnt[i][j & 1][s[i][j] - 'a'];
		}
	}
	for (int i = 0; i < M; ++ i){
		for (int j = 0; j < M; ++ j){
			if (i == j){
				dp[0][i][j] = INT_MAX;
			}
			else{
				dp[0][i][j] = m - (cnt[0][0][i] + cnt[0][1][j]);
			}
		}
	}
	for (int i = 1; i < n; ++ i){
		memset(dp[i], 0x7f, sizeof(dp[i]));
		for (int j = 0; j < M; ++ j){
			for (int k = 0; k < M; ++ k){
				if (j == k) continue;
				for (int u = 0; u < M; ++ u){
					if (u == j) continue;
					for (int v = 0; v < M; ++ v){
						if (v == k || v == u) continue;
						int x = dp[i - 1][u][v] + m - (cnt[i][0][j] + cnt[i][1][k]);
						if (x < dp[i][j][k]){
							dp[i][j][k] = x;
							pre[i][j][k] = {u, v};
						}
					}
				}
			}
		}
	}
	int min = INT_MAX;
	pii now;
	for (int i = 0; i < M; ++ i){
		for (int j = 0; j < M; ++ j){
			if (dp[n - 1][i][j] < min){
				min = dp[n - 1][i][j];
				now = {i, j};
			}
		}
	}
	for (int i = n - 1; i >= 0; -- i){
		for (int j = 0; j < m; ++ j){
			s[i][j] = (j & 1 ? now.second : now.first) + 'a';
		}
		now = pre[i][now.first][now.second];
	}
	printf("%d\n", min);
	for (int i = 0; i < n; ++ i){
		puts(s[i]);
	}
	return 0;
}