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
char a[100100];
int main () {
	int T = read();
	while (T--) {
		int n = read(), las = -1;
		scanf("%s", a + 1);
		for (int i = 1; i <= n; i++) {
			int tmp = a[i] - '0';
			int x = tmp, y = tmp + 1;
			if (y != las) putchar('1'), las = y;
			else putchar('0'), las = x;
		}
		puts("");
	}
	return 0;
}