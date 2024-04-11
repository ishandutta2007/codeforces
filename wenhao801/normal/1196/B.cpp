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

int odd[200200] = {};		
int cnt;

int main () {
	int Q = read();
	int i, j;
	while (Q--) {
		cnt = 0;
		int n = read(), k = read();
		for (i = 1; i <= n; i++) {
			int x = read();
			if (x % 2) odd[++cnt] = i;
		}
		if (cnt < k) { puts("NO"); continue; }
		if ((cnt - k) % 2 == 1) { puts("NO"); continue; }
		puts("YES");
		for (i = 1; i < k; i++)
			printf("%d ", odd[i]);
		printf("%d\n", n);
	}
	return 0;
}