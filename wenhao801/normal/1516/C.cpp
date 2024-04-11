#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

bitset <505000> buc;
int n, a[110];

int main () {
	n = read(); int i, j, mn = 999;
	for (i = 1; i <= n; i++) {
		a[i] = read();
		int x = a[i]; j = 0;
		while (x && x % 2 == 0) x >>= 1, ++j;
		mn = min(mn, j);
	}
	for (i = 1; i <= n; i++) a[i] >>= mn;
	int s = 0;
	for (i = 1; i <= n; i++) s += a[i];
	if (s & 1) { puts("0"); return 0; }
	buc[0] = 1;
	for (i = 1; i <= n; i++) buc = buc | (buc << a[i]);
	if (buc[s >> 1]) { puts("1"); for (i = 1; i <= n; i++) if (a[i] & 1) { cout << i << endl; break; } }
	else puts("0");
	return 0;
}