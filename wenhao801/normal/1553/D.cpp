#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100200;
bitset <MAXN> f[2], b[26];
char s[MAXN], t[MAXN]; int n, m;

int main () {
	int T = read();
	while (T--) {
		scanf("%s", s + 1); scanf("%s", t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		f[0].reset(), f[1].reset();
		int i, j; f[1 ^ (n & 1)][m + 1] = 1;
		for (i = 0; i < 26; i++) b[i].reset();
		for (i = 1; i <= m; i++) b[t[i] - 'a'][i] = 1;
		for (i = n; i >= 1; i--) {
			int now = i & 1, las = now ^ 1;
			f[now] |= ((f[las] >> 1) & b[s[i] - 'a']);
			if (f[now][1]) { puts("YES"); break; }
		}
		if (!i) puts("NO");
	}
	return 0;
}