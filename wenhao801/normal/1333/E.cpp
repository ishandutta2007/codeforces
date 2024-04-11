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

int ans[505][505];

int main () {
	int n = read(), i, j, id = 0;
	if (n <= 2) { puts("-1"); return 0; }
	for (i = n; i > 3; i--) {
		if (i & 1) {
			for (j = 1; j <= i; j++) ans[j][i] = ++id;
			for (j = i - 1; j >= 1; j--) ans[i][j] = ++id;
		}
		else {
			for (j = 1; j <= i; j++) ans[i][j] = ++id;
			for (j = i - 1; j >= 1; j--) ans[j][i] = ++id;
		}
	}
	ans[1][1] = ++id;
	ans[2][2] = ++id;
	ans[2][1] = ++id;

	ans[3][1] = ++id;
	ans[2][3] = ++id;
	ans[3][3] = ++id;
	
	ans[1][2] = ++id;
	ans[3][2] = ++id;
	ans[1][3] = ++id;
	
	for (i = 1; i <= n; i++) { for (j = 1; j <= n; j++) printf("%d ", ans[i][j]); puts(""); }
	return 0;
}