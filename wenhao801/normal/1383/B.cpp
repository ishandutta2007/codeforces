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

const int MAXN = 100100;
int n, a[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		bool fin = 0;
		for (i = 30; i >= 0; i--) {
			int cnt[2] = {};
			for (j = 1; j <= n; j++) ++cnt[(a[j] >> i) & 1];
			if (cnt[1] % 2 == 0) continue;
			fin = 1;
			if ((n - cnt[1]) % 2 == 0 && ((cnt[1] - 1) >> 1) % 2 == 1) {
				puts("LOSE");
			}
			else puts("WIN"); break;
		}
		if (!fin) puts("DRAW");
	}
	return 0;
}