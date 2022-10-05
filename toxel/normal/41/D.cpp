#include<bits/stdc++.h>

const int N = 110;
const int M = 1010;

bool dp[N][N][M];
bool pre[N][N][M]; // true for left
char s[N][N];

int main(){
	int n, m, kk;
	scanf("%d%d%d", &n, &m, &kk);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < m; ++ i){
		dp[n - 1][i][s[n - 1][i] - '0'] = true;
	}
	for (int i = n - 1; i; -- i){
		for (int j = 0; j < m; ++ j){
			for (int k = 0; k < M; ++ k){
				if (!dp[i][j][k]) continue;
				if (j){
					int x = k + s[i - 1][j - 1] - '0';
					dp[i - 1][j - 1][x] = true;
					pre[i - 1][j - 1][x] = true;
				}
				if (j != m - 1){
					int x = k + s[i - 1][j + 1] - '0';
					dp[i - 1][j + 1][x] = true;
					pre[i - 1][j + 1][x] = false;
				}
			}
		}
	}
	for (int j = M - 1; j >= 0; -- j){
		if (j % (kk + 1)) continue;
		for (int i = 0; i < m; ++ i){
			if (dp[0][i][j]){
				int now = i, x = j;
				std::vector <bool> ans;
				for (int k = 0; k < n - 1; ++ k){
					ans.push_back(pre[k][now][x]);
					x -= s[k][now] - '0';
					now += ans[ans.size() - 1] ? 1 : -1;
				}
				std::reverse(ans.begin(), ans.end());
				printf("%d\n%d\n", j, now + 1);
				for (auto u : ans){
					putchar(u ? 'L' : 'R');
				}
				putchar('\n');
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}