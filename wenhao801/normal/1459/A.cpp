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
		int n = read();
		scanf("%s", s + 1); scanf("%s", t + 1);
		int cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] < t[i]) ++cnt1; if (s[i] > t[i]) ++cnt0;
		}
		if (cnt0 < cnt1) puts("BLUE");
		if (cnt0 > cnt1) puts("RED");
		if (cnt0 == cnt1) puts("EQUAL");
	}
	return 0;
}