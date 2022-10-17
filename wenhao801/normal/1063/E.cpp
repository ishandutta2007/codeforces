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

const int MAXN = 1010;
int n, want[MAXN], to[MAXN];

bool vis[MAXN];
int v[MAXN][MAXN]; int cur = 1;
void set (int x, int val) { v[cur][x] = val; }
void enter () { ++cur; }

int main () {
	n = read(); int i, j = 1;
	for (i = 1; i <= n; i++) want[i] = read(), j &= want[i] == i, to[want[i]] = i;
	if (j) { printf("%d\n", n); for (i = 1; i <= n; i++) { for (j = 1; j <= n; j++) putchar('.'); putchar('\n'); } return 0; }
	printf("%d\n", n - 1);
	int r = 0;
	for (r = n; r >= 1; r--) if (want[r] != r) break;
	int now = want[r]; 
	while (now != r) {
		vis[now] = 1;
		if (want[now] < now) set(want[now], -1), set(now, -1);
		else set(now, 1), set(want[now], 1);
		enter(); now = want[now];
	}
	for (i = r - 1; i >= 1; i--) if (want[i] != i && !vis[i]) {
		int now = i; set(r, -1);
		while (want[now] != i) {
			vis[now] = 1;
			if (want[now] < now) set(want[now], -1), set(now, -1);
			else set(now, 1), set(want[now], 1);
			enter(); now = want[now];
		} vis[now] = 1;
		set(now, 1), set(r, 1);
		enter();
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) putchar(v[i][j] ? (v[i][j] == -1 ? '\\' : '/') : '.');
		putchar('\n');
	}
	return 0;
}