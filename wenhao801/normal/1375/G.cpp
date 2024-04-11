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

const int MAXN = 200200;
vector <int> E[MAXN];

int cnt[2];
void dfs (int x, int f, bool v) {
	cnt[v]++; for (auto i: E[x]) if (i != f) dfs(i, x, !v);
}

int main () {
	int n = read(); int i, j;
	for (i = 1; i < n; i++) { int u = read(), v = read(); E[u].push_back(v), E[v].push_back(u); }
	dfs(1, 0, 0); printf("%d\n", min(cnt[0] - 1, n - cnt[0] - 1));
	return 0;
}