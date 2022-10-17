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

const int MAXN = 1010;
int n;
struct node { int l, r, id; bool operator < (const node &tmp) const { return (l + r) > (tmp.l + tmp.r); } } a[MAXN];
int val[MAXN];
bool cmp (node x, node y) { return x.id < y.id; }

int buc[MAXN];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i].l = read();
	for (i = 1; i <= n; i++) a[i].r = read(), a[i].id = i;
	sort(a + 1, a + n + 1);
	a[0].l = -1;
	for (i = 1; i <= n; i++) {
		if (a[i].l + a[i].r == a[i - 1].l + a[i - 1].r) val[a[i].id] = val[a[i - 1].id];
		else val[a[i].id] = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (i = 1; i <= n; i++) {
		int tmp = 0;
		for (j = val[i] + 1; j <= n; j++) tmp += buc[j];
		if (tmp != a[i].l) { puts("NO"); return 0; }
		++buc[val[i]];
	}
	for (i = 1; i <= n; i++) buc[i] = 0;
	for (i = n; i >= 1; i--) {
		int tmp = 0;
		for (j = val[i] + 1; j <= n; j++) tmp += buc[j];
		if (tmp != a[i].r) { puts("NO"); return 0; }
		++buc[val[i]];
	}
	puts("YES");
	for (i = 1; i <= n; i++) cout << val[i] << ' ';
	return 0;
}