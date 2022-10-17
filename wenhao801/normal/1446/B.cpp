#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int nexa[5050][26], nexb[5050][26];
char a[5050], b[5050];
int f[5050][5050];

int main () {
	int n = read(), m = read();
	scanf("%s", a + 1); scanf("%s", b + 1); int i, j;
	for (i = 0; i < 26; i++) nexa[n + 1][i] = n + 1, nexb[m + 1][i] = m + 1;
	for (i = n; i >= 1; i--) {
		for (j = 0; j < 26; j++) nexa[i][j] = nexa[i + 1][j];
		nexa[i][a[i] - 'a'] = i;
	}
	for (i = m; i >= 1; i--) {
		for (j = 0; j < 26; j++) nexb[i][j] = nexb[i + 1][j];
		nexb[i][b[i] - 'a'] = i;
	}
	int ans = 0;
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) f[i][j] = -2;
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) if (a[i] == b[j]) {
		f[i][j] = max(f[i][j], 2);
		for (int k = 0; k < 26; k++) if (nexa[i + 1][k] != n + 1 && nexb[j + 1][k] != m + 1) {
			// printf("%d %d -> %d %d: %d\n", i, j, nexa[i + 1][k], nexb[j + 1][k], f[i][j] + 4 - (nexa[i + 1][k] - i) - (nexb[j + 1][k] - i));
			f[nexa[i + 1][k]][nexb[j + 1][k]] = max(f[nexa[i + 1][k]][nexb[j + 1][k]], f[i][j] + 4 - (nexa[i + 1][k] - i) - (nexb[j + 1][k] - j));
		}
	}
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) ans = max(ans, f[i][j]); //, printf("f %d %d = %d\n", i,j , f[i][j]);
	cout << ans << endl;
	return 0;
}