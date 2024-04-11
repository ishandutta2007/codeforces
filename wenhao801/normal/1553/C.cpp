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

char s[11];

int main () {
	int T = read();
	while (T--) {
		scanf("%s", s + 1); int n = 10, i, j;
		int ans = 10, now[2] = {};
		for (i = 1; i <= n; i++) {
			if (s[i] == '0' || s[i] == '1') now[i & 1] += s[i] - '0';
			else now[i & 1] += i & 1;
			if (now[1] > now[0] + ((n - i + 1) >> 1)) { ans = min(ans, i); break; }
		}
		now[0] = now[1] = 0;
		for (i = 1; i <= n; i++) {
			if (s[i] == '0' || s[i] == '1') now[i & 1] += s[i] - '0';
			else now[i & 1] += !(i & 1);
			if (now[0] > now[1] + ((n - i) >> 1)) { ans = min(ans, i); break; }
		}
		cout << ans << endl;
	}
	return 0;
}