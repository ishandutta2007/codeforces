#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int dp[N][N][N], a, b, c;
int pre[N][N][N];
char s1[N], s2[N], vi[N];

int ne[N];

void print(int a, int b, int c) {
	if(a == 1 || b == 1) return;
	if(pre[a][b][c] == 0) return;
	if(pre[a][b][c] > 0) {
		print(a - 1, b - 1, pre[a][b][c] - 233);
		putchar(s1[a - 1]);
	}
	else {
		if(pre[a][b][c] == -2) print(a - 1, b, c);
		else if(pre[a][b][c] == -3) print(a, b - 1, c);
	}
}

main(void) {
	scanf("%s", s1 + 1); a = strlen(s1 + 1);
	scanf("%s", s2 + 1); b = strlen(s2 + 1);
	scanf("%s", vi + 1); c = strlen(vi + 1);
	ne[0] = -1;
	int cur = 0;
	for(int i = 1; i <= c; ++ i) {
		int now = ne[i - 1];
		while(now != -1 && vi[now + 1] != vi[i]) now = ne[now];
		++ now;
		ne[i] = now;
	}
	memset(dp, -1, sizeof(dp));
	dp[1][1][0] = 0;
	for(int i = 1; i <= a; ++ i) {
		for(int j = 1; j <= b; ++ j) {
			for(int k = 0; k < c; ++ k) {
				if(s1[i] == s2[j]) {
					int now = k;
					while(now != -1 && s1[i] != vi[now + 1]) now = ne[now];
					++ now;
					if(now != c) {
						if(dp[i + 1][j + 1][now] <= dp[i][j][k] + 1) {
							pre[i + 1][j + 1][now] = k + 233;
							dp[i + 1][j + 1][now] = max(dp[i + 1][j + 1][now], dp[i][j][k] + 1);
						}
					}
				}
				if(dp[i + 1][j][k] <= dp[i][j][k]) {
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
					pre[i + 1][j][k] = -2;
				}
				if(dp[i][j + 1][k] <= dp[i][j][k]) {
					dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
					pre[i][j + 1][k] = -3;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= a + 1; ++ i) {
		for(int j = 0; j <= b + 1; ++ j) {
			for(int k = 0; k < c; ++ k) ans = max(ans, dp[i][j][k]);
		}
	}
	if(!ans) {
		puts("0");
		return 0;
	}
	for(int i = 1; i <= a + 1; ++ i) {
		for(int j = 1; j <= b + 1; ++ j) {
			for(int k = 0; k < c; ++ k) {
				if(ans == dp[i][j][k]) {
					print(i, j, k);
					return 0;
				}
			}
		}
	}
}