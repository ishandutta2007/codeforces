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

int cnt[2]; char a[101];

int main () {
	int T = read();
	while (T--) {
		scanf("%s", a + 1);
		int len = strlen(a + 1);
		int i, j;
		cnt[0] = cnt[1] = 0;
		for (i = 1; i <= len; i++) ++cnt[a[i] - '0'];
		int tmp = min(cnt[0], cnt[1]);
		if (tmp & 1) puts("DA"); else puts("NET");
	}
	return 0;
}