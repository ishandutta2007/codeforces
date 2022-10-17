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

char s[1010], t[1010];

int main () {
	int T = read();
	while (T--) {
		scanf("%s", s + 1); scanf("%s", t + 1);
		int n = strlen(s + 1), m = strlen(t + 1), i, j, k;
		bool fin = 0;
		for (i = 1; i <= n; i++) for (j = i; j <= n; j++) {
			if (j - i + 1 > m) break;
			int now = 1;
			for (k = i; k <= j; k++) if (s[k] != t[now]) { now = -1; break; } else ++now;
			if (now == -1) continue;
			for (k = j - 1; k >= 1; k--) if (s[k] != t[now]) break; else ++now;
			if (now > m) { fin = 1; break; }
		}
		puts(fin ? "YES" : "NO");
	}
	return 0;
}