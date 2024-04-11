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

using ll = long long;
int n, m, dn, dm, p[11], vis[11];
int ans = 0;

void dfs (int now) {
	if (now == dn + dm) {
		ll u = 0, v = 0, i, j = 1;
		for (i = dn - 1; i >= 0; i--) u = u * 7 + p[j], j++;
		for (i = dm - 1; i >= 0; i--) v = v * 7 + p[j], j++;
		if (u < n && v < m) {
			++ans;
		}
		return;
	}
	for (int i = 0; i < 7; i++) if (!vis[i]) {
		p[now + 1] = i; vis[i] = 1;
		dfs(now + 1);
		p[now + 1] = 0; vis[i] = 0;
	}
}

int main () {
	n = read(), m = read();
	int i, j;
	for (i = n - 1; i; i /= 7) ++dn;
	for (i = m - 1; i; i /= 7) ++dm;
	dn = max(dn, 1), dm = max(dm, 1);
	if (dn + dm > 7) { puts("0"); return 0; }
	dfs(0); printf("%d\n", ans);
	return 0;
}