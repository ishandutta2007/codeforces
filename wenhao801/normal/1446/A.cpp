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
#define ll long long
#define pii pair<int, int>
pii a[200200];
bool cmp (pii x, pii y) { return x.first < y.first; }
int main () {
	int T = read();
	while (T--) {
		int n = read(); ll w; cin >> w;
		for (int i = 1; i <= n; i++) a[i].first = read(), a[i].second = i;
		sort(a + 1, a + n + 1, cmp);
		int top = n; while (top && a[top].first > w) --top;
		if (!top) { puts("-1"); continue; }
		if (a[top].first >= ((w + 1) >> 1)) { printf("1\n%d\n", a[top].second); continue; }
		int i; ll s = 0; for (i = top; i >= 1; i--) { s += a[i].first; if (s >= ((w + 1) >> 1)) { break; } }
		if (s >= ((w + 1) >> 1)) { printf("%d\n", top - i + 1); for (i; i <= top; i++) cout << a[i].second << ' '; cout << endl; }
		else puts("-1");
	}
	return 0;
}