#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 51123987;

char s[200];
int res[151][52][52][52];
int next[151][3];

int main() {
	int n;
	scanf ("%d\n", &n);
	gets (s);
	for (int i = 0; i < 3; i++) next[n][i] = n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) next[i][j] = next[i + 1][j];
		next[i][s[i] - 'a'] = i;
	}
	memset (res, 0, sizeof (res));
	int m = (n + 2) / 3;
	res[0][0][0][0] = 1;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int a = 0; a <= m; a++)
			for (int b = 0; b <= m; b++)
				for (int c = 0; c <= m; c++) {
					if (a + b + c == n && abs (a - b) < 2 && abs (a - c) < 2 && abs (b - c) < 2) ans = (ans + res[i][a][b][c]) % mod;
					if (next[i][0] != n) res[next[i][0]][a + 1][b][c] = (res[next[i][0]][a + 1][b][c] + res[i][a][b][c]) % mod;
					if (next[i][1] != n) res[next[i][1]][a][b + 1][c] = (res[next[i][1]][a][b + 1][c] + res[i][a][b][c]) % mod;
					if (next[i][2] != n) res[next[i][2]][a][b][c + 1] = (res[next[i][2]][a][b][c + 1] + res[i][a][b][c]) % mod;
				}
	printf ("%d\n", ans);
	return 0;
}