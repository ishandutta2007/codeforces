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
#include <map>
map <int, int> cnt;
char a[1001000];

int main () {
	int T = read();
	while (T--) {
		cnt.clear();
		scanf("%s", a + 1);
		int len = strlen(a + 1); int i, j;
		int tmp = 0;
		for (i = 1; i <= len; i++) {
			if (a[i] == '+') ++tmp; else --tmp;
			if (cnt[tmp] == 0) cnt[tmp] = i;
		}
		long long ans = 0;
		for (i = 1; i <= len; i++) ans += cnt[-i];
		printf("%lld\n", ans + len);
	}
	return 0;
}