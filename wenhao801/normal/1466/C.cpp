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
char s[100010];

int main () {
	int T = read();
	while (T--) {
		scanf("%s", s + 1);
		int n = strlen(s + 1); int ans = 0;
		for (int i = 2; i <= n; i++) {
			if (s[i] == s[i - 1] && s[i] != '.') s[i] = '.', ++ans;
			if (s[i] == s[i - 2] && s[i] != '.') s[i] = '.', ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}