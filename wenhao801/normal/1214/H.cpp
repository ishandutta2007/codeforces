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
int n, K;
vector <int> E[MAXN];

int dep[MAXN], fa[MAXN], ans[MAXN];
void pre (int x, int f) { fa[x] = f, dep[x] = dep[f] + 1; for (auto i: E[x]) if (i != f) pre(i, x); }

bool sp[MAXN];

int dfs (int x, int f, int d, int cur, int dt) {
	int ret = d; cur = (cur + dt - 1 + K) % K + 1;
	ans[x] = cur;
	for (auto i: E[x]) if (i != f) ret = max(ret, dfs(i, x, d + 1, cur, dt));
	return ret;
}

int main () {
	n = read(), K = read();
	int i, j;
	for (i = 1; i < n; i++) {
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
	}
	pre(1, 0); for (i = j = 1; i <= n; i++) if (dep[i] > dep[j]) j = i;
	pre(j, 0); int rt = j, x = 1; for (i = 1; i <= n; i++) if (dep[i] > dep[x]) x = i;
	if (dep[x] < K || K == 2) {
		puts("Yes");
		for (i = 1; i <= n; i++) printf("%d ", 1 + (dep[i] & 1));
		return 0;
	}
	for (i = x; i; i = fa[i]) sp[i] = 1, ans[i] = (dep[i] - 1) % K + 1;
	for (i = x; i; i = fa[i]) {
		for (auto j: E[i]) if (!sp[j]) {
			int du = dep[i], dv = dep[x] - du + 1;
			int tmp = dfs(j, i, 1, ans[i], du < dv ? -1 : 1);
			if (min(du, dv) + tmp >= K) { puts("No"); return 0; }
		}
	}
	puts("Yes"); for (i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}