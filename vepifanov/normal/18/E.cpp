#include <cstdio>

using namespace std;

int n;
int m;

int cnt[500][26][2];
int col[500][26][26];
int res[500][26][26];
int pa[500][26][26];
int pb[500][26][26];
char w[501][501];
int x[501][501];

int out (int i, int a, int b) {
	if (i > 0) out (i - 1, pa[i][a][b], pb[i][a][b]);
	for (int j = 0; j < m; j++) printf ("%c", 'a' + ((j & 1) * b + (1 - (j & 1)) * a));
	printf ("\n");
}

int main () {
	scanf ("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++) gets (w[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			x[i][j] = w[i][j] - 'a';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < 2; k++) {
				cnt[i][j][k] = 0;
				for (int t = k; t < m; t += 2) cnt[i][j][k] += int (x[i][t] != j);
			}
	for (int i = 0; i < n; i++)
		for (int a = 0; a < 26; a++)
			for (int b = 0; b < 26; b++) {
				res[i][a][b] = 1e9;
				col[i][a][b] = cnt[i][a][0] + cnt[i][b][1];
				if (i == 0) res[i][a][b] = col[i][a][b];
			}
	for (int i = 0; i < n; i++)
		for (int a = 0; a < 26; a++)
			for (int b = 0; b < 26; b++)
				if (a != b)
					for (int x = 0; x < 26; x++)
						for (int y = 0; y < 26; y++)
							if (x != y && a != x && b != y && res[i + 1][x][y] > res[i][a][b] + col[i + 1][x][y]) {
								res[i + 1][x][y] = res[i][a][b] + col[i + 1][x][y];
								pa[i + 1][x][y] = a;
								pb[i + 1][x][y] = b;
							}
	int ans = 1e9, aa = 0, ab = 0;
	for (int a = 0; a < 26; a++)
		for (int b = 0; b < 26; b++)
			if (a != b && ans > res[n - 1][a][b]) {
				ans = res[n - 1][a][b];
				aa = a;
				ab = b;
			}
	printf ("%d\n", ans);
	out (n - 1, aa, ab);
	return 0;
}