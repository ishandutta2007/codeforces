#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 1001000;
char a[MAXN], b[MAXN];
int nex[MAXN], f[MAXN][26];

int main() {
	scanf("%s", a + 1); int n = strlen(a + 1), i, j;
	if (n >= 2) f[1][a[2] - 'a'] = 1;
	for (i = 2, j = 0; i <= n; i++) {
		while (j && a[i] != a[j + 1]) j = nex[j];
		if (a[i] == a[j + 1]) ++j;
		nex[i] = j;
		for (int k = 0; k < 26; k++) f[i][k] = f[j][k];
		if (i < n) f[i][a[i + 1] - 'a'] = i;
	}
	int q = read(); while (q--) {
		scanf("%s", b + 1); int m = strlen(b + 1);
		for (i = 1; i <= m; i++) a[i + n] = b[i];
		
		for (i = n + 1, j = nex[n]; i <= n + m; i++) {
			while (j > n && a[i] != a[j + 1]) j = nex[j];
			if (j && a[i] != a[j + 1]) j = f[j][a[i] - 'a']; 
			if (a[i] == a[j + 1]) ++j;
			nex[i] = j; printf("%d ", j);
		}
		putchar('\n');
	}
	return 0;
}