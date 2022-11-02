#include<cstdio>
#include<cstring>

const int MAXN = 1005, MAXM = 1005;

int n, m, k;

char map[MAXN][MAXM];

const int UNCOLORED = -1;
int maxcol, col[MAXN][MAXM], cnt[MAXN * MAXM];

const int dx[4] = {-1, 0, 1, 0},
	      dy[4] = {0, 1, 0, -1};

void color(int x, int y, int c) {
	col[x][y] = c;
	for (int d = 0; d < 4; ++d) {
		int tx = x + dx[d], ty = y + dy[d];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
			if (map[tx][ty] == '.') {
				if (col[tx][ty] == UNCOLORED) {
					color(tx, ty, c);
				}
			} else {
				++cnt[c];
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			col[i][j] = UNCOLORED;
		}
	}
	//memset(col, 0, sizeof(col));
	maxcol = UNCOLORED;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '.' && col[i][j] == UNCOLORED) {
				++maxcol;
				cnt[maxcol] = 0;
				color(i, j, maxcol);
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		printf("%d\n", cnt[col[x][y]]);
	}
	return 0;
}