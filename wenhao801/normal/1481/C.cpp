#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

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
int n, m, a[MAXN], b[MAXN], c[MAXN];
int ans[MAXN]; int vis[MAXN]; vector <int> buc[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(), m = read(); int i, j;
		int lim = max(m, n);
		for (i = 1; i <= lim; i++)  ans[i] = vis[i] = 0, buc[i].clear();
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i <= n; i++) { b[i] = read(); vis[b[i]] = i; if (b[i] != a[i]) buc[b[i]].push_back(i); }
		for (i = 1; i <= m; i++) c[i] = read();
		for (i = m; i >= 1; i--) {
			if (buc[c[i]].size()) {
				ans[i] = buc[c[i]].back(); buc[c[i]].pop_back();
			}
		}
		bool fin = vis[c[m]];
		for (i = 1; i <= n; i++) if (buc[i].size()) fin = 0;
		if (!fin) { puts("NO"); continue; }
		puts("YES");
		for (i = 1; i <= m; i++) {
			if (!ans[i]) printf("%d ", ans[m] ? ans[m] : vis[c[m]]);
			else printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}