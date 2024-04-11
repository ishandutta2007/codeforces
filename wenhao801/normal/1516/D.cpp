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

const int MAXN = 100100, LIM = 1e5;
int pid[MAXN], top, p[MAXN];
void genp () {
	int i, j; pid[1] = -1;
	for (i = 2; i <= LIM; i++) {
		if (pid[i] != -1) ++top, pid[i] = top, p[top] = i;
		for (j = 1; j <= top; j++) {
			if (i * p[j] > LIM) break;
			pid[i * p[j]] = -1;
			if (i % p[j] == 0) break;
		}
	}
}

int las[MAXN], a[MAXN], L[MAXN][22], mx[MAXN];

int main () {
	genp(); int i, j, n = read(), q = read();
	for (i = 1; i <= n; i++) {
		a[i] = read(); int x = a[i];
		for (j = 1; j <= top && p[j] * p[j] <= x; j++) if (x % p[j] == 0) {
			while (x % p[j] == 0) x /= p[j];
			mx[i] = max(mx[i], las[j]);
			las[j] = i;
		}
		if (x != 1) { mx[i] = max(mx[i], las[pid[x]]), las[pid[x]] = i; }
	}
	for (i = 1; i <= n; i++) mx[i] = max(mx[i], mx[i - 1]), L[i][0] = mx[i];	
	for (i = 1; i <= 20; i++) for (j = 1; j <= n; j++) L[j][i] = L[L[j][i - 1]][i - 1];
	while (q--) {
		int l = read(), r = read(), ans = 1;
		for (i = 20; i >= 0; i--) if (L[r][i] >= l) ans += 1 << i, r = L[r][i];
		printf("%d\n", ans);
	}
	return 0;
}