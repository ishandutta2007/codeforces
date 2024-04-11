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

int cnt[200200][27] = {};
char a[200200] = {};
int n;

int main () {
	scanf("%s", a + 1);
	n = strlen(a + 1);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 26; j++) cnt[i][j] = cnt[i - 1][j];
		cnt[i][a[i] - 'a' + 1]++;
	}
	int Q = read();
	while (Q--) {
		int l = read(), r = read(); j = 0;
		for (i = 1; i <= 26; i++) if (cnt[r][i] - cnt[l - 1][i] > 0) j++;
		if (j >= 3) puts("Yes");
		else if (j == 2 && a[l] != a[r]) puts("Yes");
		else if (l == r) puts("Yes");
		else puts("No");
	}
	return 0;
}