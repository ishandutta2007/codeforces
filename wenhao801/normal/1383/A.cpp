#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

int fa[33];
inline int gf (int x) { return (fa[x] == x ? x : (fa[x] = gf(fa[x]))); }
char a[100100], b[100100];
int main () {
	int T = read();
	while (T--) {
		int n = read(); int i, j;
		scanf("%s", a + 1); scanf("%s", b + 1); 
		for (i = 0; i < 30; i++) fa[i] = i;
		for (i = 1; i <= n; i++) {
			if (a[i] > b[i]) break;
			fa[gf(a[i] - 'a')] = gf(b[i] - 'a');
		}
		if (i <= n) puts("-1"); else {
			for (i = 0, j = 0; i < 30; i++) j += gf(i) == i;
			printf("%d\n", 30 - j);
		}
	}
	return 0;
}