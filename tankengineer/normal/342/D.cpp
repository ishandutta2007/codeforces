#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10005, MOD = 1000000007;
int n, sx, sy, cnt;
char map[3][N];
int dp[N][1 << 3];

int dps() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int st = 0; st < 1 << 3; ++st) {
			bool v[3];
			for (int j = 0; j < 3; ++j) {
				v[j] = ~st >> j & 1;
				if (map[j][i] == 'X') {
					if (!v[j]) {
						dp[i][st] = 0;
					}
					v[j] = false;
				}
			}
			if (dp[i][st] == 0) {
				continue;
			}
			if (v[0]) {
				if (v[1]) {
					if (v[2]) {
						(dp[i + 1][7] += dp[i][st]) %= MOD;
						(dp[i + 1][1] += dp[i][st]) %= MOD;
						(dp[i + 1][4] += dp[i][st]) %= MOD;
					} else {
						(dp[i + 1][3] += dp[i][st]) %= MOD;
						(dp[i + 1][0] += dp[i][st]) %= MOD;
					}
				} else {
					if (v[2]) {
						(dp[i + 1][5] += dp[i][st]) %= MOD;	
					} else {
						(dp[i + 1][1] += dp[i][st]) %= MOD;
					}
				}
			} else {
				if (v[1]) {
					if (v[2]) {
						(dp[i + 1][0] += dp[i][st]) %= MOD;
						(dp[i + 1][6] += dp[i][st]) %= MOD;
					} else {
						(dp[i + 1][2] += dp[i][st]) %= MOD;
					}
				} else {
					if (v[2]) {
						(dp[i + 1][4] += dp[i][st]) %= MOD;
					} else {
						(dp[i + 1][0] += dp[i][st]) %= MOD;
					}
				}
			}
		}
	}
	int ret = dp[n][0];
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) {
		scanf("%s", map[i]);
		map[i][n] = 'X';
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == '.') {
				++cnt;
			}
			if (map[i][j] == 'O') {
				sx = i;
				sy = j;
			}
		}
	}
	if (sx == 2) {
		for (int i = 0; i < n; ++i) {
			swap(map[0][i], map[2][i]);
		}
		sx = 0;
	}
	if (cnt & 1) {
		printf("0\n");
		return 0;
	}
	map[sx][sy] = 'X';
	bool f1 = false, f2 = false, f3 = false, f4 = false;
	int ans = 0;
	if (sy > 1 && map[sx][sy - 1] == '.' && map[sx][sy - 2] == '.') { 
		f1 = true;
		map[sx][sy - 1] = map[sx][sy - 2] = 'X';
		ans += dps();
		map[sx][sy - 1] = map[sx][sy - 2] = '.';
	}
	if (sy < n - 2 && map[sx][sy + 1] == '.' && map[sx][sy + 2] == '.') {
		f2 = true;
		map[sx][sy + 1] = map[sx][sy + 2] = 'X';
		(ans += dps()) %= MOD;	
		map[sx][sy + 1] = map[sx][sy + 2] = '.';
	}
	if (sx == 0 && map[sx + 1][sy] == '.' && map[sx + 2][sy] == '.') {
		f3 = true;
		map[sx + 1][sy] = map[sx + 2][sy] = 'X';
		(ans += dps()) %= MOD;
		map[sx + 1][sy] = map[sx + 2][sy] = '.';
	}
	if (f1 && f2) {
		map[sx][sy - 1] = map[sx][sy - 2] = 'X';
		map[sx][sy + 1] = map[sx][sy + 2] = 'X';
		(ans += MOD - dps()) %= MOD;
		map[sx][sy - 1] = map[sx][sy - 2] = '.';
		map[sx][sy + 1] = map[sx][sy + 2] = '.';
	}
	if (f1 && f3) {
		map[sx][sy - 1] = map[sx][sy - 2] = 'X';
		map[sx + 1][sy] = map[sx + 2][sy] = 'X';
		(ans += MOD - dps()) %= MOD;
		map[sx + 1][sy] = map[sx + 2][sy] = '.';
		map[sx][sy - 1] = map[sx][sy - 2] = '.';
	}
	if (f2 && f3) {
		map[sx][sy + 1] = map[sx][sy + 2] = 'X';
		map[sx + 1][sy] = map[sx + 2][sy] = 'X';
		(ans += MOD - dps()) %= MOD;
		map[sx + 1][sy] = map[sx + 2][sy] = '.';
		map[sx][sy + 1] = map[sx][sy + 2] = '.';
	}
	if (f1 && f2 && f3) {
		map[sx][sy - 1] = map[sx][sy - 2] = 'X';
		map[sx][sy + 1] = map[sx][sy + 2] = 'X';
		map[sx + 1][sy] = map[sx + 2][sy] = 'X';
		(ans += dps()) %= MOD;
		map[sx + 1][sy] = map[sx + 2][sy] = '.';
		map[sx][sy - 1] = map[sx][sy - 2] = '.';
		map[sx][sy + 1] = map[sx][sy + 2] = '.';
	}
	printf("%d\n", ans);
	return 0;
}