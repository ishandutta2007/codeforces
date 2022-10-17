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

const int MAXN = 100100;
int n, K, pos[2][MAXN], top[2];
char a[MAXN];

int main () {
	n = read(), K = read(); int i, j;
	scanf("%s", a + 1);
	for (i = 1; i <= n; i++) pos[a[i] - '0'][++top[a[i] - '0']] = i;
	if (!top[0] || !top[1]) { puts("tokitsukaze"); return 0; }
	if (pos[0][top[0]] - pos[0][1] + 1 <= K || pos[1][top[1]] - pos[1][1] + 1 <= K) {
		puts("tokitsukaze");
		return 0;
	}
	for (i = 1; i <= n - K + 1; i++) {
		int l = i, r = i + K - 1;
		if (pos[0][top[0]] <= r && (pos[0][1] >= l || pos[0][lower_bound(pos[0] + 1, pos[0] + top[0] + 1, l) - pos[0] - 1] - pos[0][1] + 1 <= K));
		else if (pos[0][1] >= l && (pos[0][top[0]] <= r || pos[0][top[0]] - pos[0][upper_bound(pos[0] + 1, pos[0] + top[0] + 1, r) - pos[0]] + 1 <= K));
		else { puts("once again"); return 0; }

		if (pos[1][top[1]] <= r && (pos[1][1] >= l || pos[1][lower_bound(pos[1] + 1, pos[1] + top[1] + 1, l) - pos[1] - 1] - pos[1][1] + 1 <= K));
		else if (pos[1][1] >= l && (pos[1][top[1]] <= r || pos[1][top[1]] - pos[1][upper_bound(pos[1] + 1, pos[1] + top[1] + 1, r) - pos[1]] + 1 <= K));
		else { puts("once again"); return 0; }
	}
	puts("quailty");
	return 0;
}