#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <bitset>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 300300;
int n, m; vector <int> s[MAXN], E[MAXN];
int ans = 1, col[MAXN];
bitset <MAXN> now;

bool isin (int x, int c) { return (*lower_bound(s[x].begin(), s[x].end(), c)) == c; }
void dfs (int x, int fa) {
	for (auto i: E[x]) if (i != fa) {
		for (auto j: s[i]) if (col[j]) now[col[j]] = 0;
		for (auto j: s[i]) if (!col[j]) {
			col[j] = now._Find_first(), now[col[j]] = 0; //, printf("set col %d = %d\n", j, col[j]);
		}
		for (auto j: s[i]) now[col[j]] = 1;
		dfs(i, x);
	}
}

int main () {
	n = read(), m = read(); int i, j, id = 0;
	for (i = 1; i <= n; i++) {
		j = read(); ans = max(ans, j);
		if (j > s[id].size()) id = i;
		while (j--) s[i].push_back(read());
		sort(s[i].begin(), s[i].end());
	}
	for (i = 1; i < n; i++) {
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
	}
	printf("%d\n", ans);
	j = 1; for (auto i: s[id]) col[i] = j, j++;
	now.set(); now[0] = 0;
	dfs(id, 0);
	for (i = 1; i <= m; i++) if (!col[i]) col[i] = 1;
	for (i = 1; i <= m; i++) printf("%d ", col[i]);
	for (i = 1; i <= m; i++) assert(col[i] >= 1 && col[i] <= ans);
	return 0;
}