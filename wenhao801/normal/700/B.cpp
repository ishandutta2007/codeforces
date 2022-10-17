#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 202000;
vector <int> E[MAXN];

int n, K, s[MAXN]; long long ans = 0;

void dfs (int x, int f) {
	for (auto i: E[x]) if (i != f) dfs(i, x), s[x] += s[i];
	ans += min(s[x], 2 * K - s[x]);
}

int main () {
	n = read(), K = read();
	int i, j;
	for (i = 1; i <= K * 2; i++) ++s[read()];
	for (i = 1; i < n; i++) {
		int u = read(), v = read();
		E[u].emplace_back(v), E[v].emplace_back(u);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}