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
#define ll long long
const int MAXN = 100100;
vector <int> E[MAXN];

ll f[MAXN][2]; int l[MAXN], r[MAXN];
void dfs (int x, int fa) {
	for (auto i: E[x]) if (i != fa) {
		dfs(i, x);
		f[x][0] += max(f[i][0] + abs(l[x] - l[i]), f[i][1] + abs(l[x] - r[i]));
		f[x][1] += max(f[i][0] + abs(r[x] - l[i]), f[i][1] + abs(r[x] - r[i]));
	}
}

int main () {
	int T = read();
	while (T--) {
		int n = read(), i;
		for (i = 1; i <= n; i++) f[i][0] = f[i][1] = 0, E[i].clear();
		for (i = 1; i <= n; i++) l[i] = read(), r[i] = read();
		for (i = 1; i < n; i++) {
			int u = read(), v = read();
			E[u].push_back(v), E[v].push_back(u);
		}
		dfs(1, 0); printf("%lld\n", max(f[1][0], f[1][1]));
	}
	return 0;
}