#include<stdio.h>
#include<string.h>
int chk[210][12][2100];
char in[110][110];
char x[210][2][15];
int min(int a, int b) { return a > b ? b : a; }
void add(char *s, int chk[][2100]) {
	int n = strlen(s);
	for (int j = 0; j <= 10; j++) {
		int b = 0;
		for (int k = 0; k < j && k < n; k++) b = b * 2 + s[k] - '0';
		for (int k = j; k < n; k++) {
			b = b * 2 + s[k] - '0';
			b %= (1 << (1 + j));
			chk[j][b] = 1;
		}
	}
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", in[i]);
		add(in[i], chk[i]);
		int l = strlen(in[i]);
		for (int k = 0; k < 13 && k < l; k++) x[i][0][k] = in[i][k];
		for (int k = 0; k < 13 && k < l; k++) x[i][1][k] = in[i][l - k - 1];
	}
	scanf("%d", &m);
	int u, v;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		char tmp[101];
		int j;

		sprintf(tmp, "%s%s", x[u][0], x[v][0]);
		for (j = 0; j < 13 && tmp[j]; j++) x[n + i][0][j] = tmp[j];
		tmp[j] = 0;

		sprintf(tmp, "%s%s", x[v][1], x[u][1]);
		for (j = 0; j < 13 && tmp[j]; j++) x[n + i][1][j] = tmp[j];
		tmp[j] = 0;

		int X = strlen(x[u][1]);
		for (int j = 0; j < X; j++) tmp[X - j - 1] = x[u][1][j];
		sprintf(tmp + X, "%s", x[v][0]);
		add(tmp, chk[n + i]);

		int m = 11;
		for (int j = 10; j >= 0; j--) {
			for (int k = 0; k < (1 << (j + 1)); k++) chk[n + i][j][k] |= chk[u][j][k] | chk[v][j][k];
			for (int k = 0; k < (1 << (j + 1)); k++) if (chk[n + i][j][k] == 0) m = j;
		}

		printf("%d\n", m);

	}
	return 0;
}