#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int M = 135;

int t, n, l[N];
char s[11][M];

int dp[155][(1 << 10) + 1], pre[155][(1 << 10) + 1][2];
int pos[N][M][2], nxt[N][M][M], wh[N][M];

int chg(char c) {
	if(c >= 'a' && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}

int get(int k, int c, int d) {
	return pos[k][c][d];
}

void solve(int i, int j) {
	if(!i && !j) return;
	solve(pre[i][j][0], pre[i][j][1]);
	if(s[1][i] < 26) putchar('a' + s[1][i]);
	else putchar('A' + s[1][i] - 26);
}

void rmain() {
	scanf("%d", &n);
	memset(wh, 0, sizeof(wh));
	memset(pos, 0, sizeof(pos));
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s[i] + 1);
		l[i] = strlen(s[i] + 1);
		for(int j = 1; j <= l[i]; ++ j) s[i][j] = chg(s[i][j]);
		int tmp[M] = {0};
		for(int j = 0; j < M; ++ j) {
			for(int k = 0; k < M; ++ k) nxt[i][j][k] = l[i] + 1;
		}
		for(int j = 1; j <= l[i]; ++ j) {
			pos[i][s[i][j]][tmp[s[i][j]] ++] = j;
			wh[i][j] = tmp[s[i][j]] - 1;
			nxt[i][j][s[i][j]] = j;
		}
		for(int j = l[i]; j >= 1; -- j) {
			for(int k = 0; k < 52; ++ k)
			nxt[i][j][k] = min(nxt[i][j][k], nxt[i][j + 1][k]);
		}
	}
	s[1][0] = 53;
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int ans = 0;
	for(int i = 0; i <= l[1]; ++ i) {
		for(int j = 0; j < (1 << (n - 1)); ++ j) if(~dp[i][j]) {
			ans = max(ans, dp[i][j]);
			for(int k = i + 1; k <= l[1]; ++ k) {
				int c = s[1][k];
				int next[10] = {0};
				bool ok = 1;
				for(int k = 2; k <= n; ++ k) {
					if(s[1][i] == 53)
					next[k] = nxt[k][1][c];
					else
					next[k] = nxt[k][get(k, s[1][i], (j >> (k - 2)) & 1) + 1][c];
					ok &= (next[k] != l[k] + 1);
				}
				if(!ok) continue;
				else {
					int mask = 0;
					for(int k = 2; k <= n; ++ k) {
						mask = mask + (wh[k][next[k]] << (k - 2));
					}
					if(dp[k][mask] < dp[i][j] + 1) {
						pre[k][mask][0] = i;
						pre[k][mask][1] = j;
						dp[k][mask] = dp[i][j] + 1;
					}
				}
			}
		}
	}
	cout << ans << endl;
	for(int i = 0; i <= l[1]; ++ i) {
		for(int j = 0; j < (1 << (n - 1)); ++ j) {
			if(dp[i][j] == ans) {
				solve(i, j);
				puts("");
				return;
			}
		}
	}
	if(s[1][1] == chg('a') && s[1][2] == chg('L'))
	exit(0);
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}