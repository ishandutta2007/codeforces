#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

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
const int MAXN = 5050;
const ll inf = 1e18;
int n, b, c[MAXN], d[MAXN];
vector <int> E[MAXN]; priority_queue <int, vector<int>, greater<int>> pq[MAXN], tmp;

ll f[MAXN][MAXN], tmp2[MAXN]; int siz[MAXN];
void dfs (int x) {
	siz[x] = 1; int i, j; pq[x].push(c[x]);
	for (i = 0; i <= n; i++) f[x][i] = inf;
	f[x][1] = d[x];
	for (auto v: E[x]) {
		dfs(v);
		if (siz[x] < siz[v]) swap(pq[x], pq[v]);
		while (!pq[v].empty()) pq[x].push(pq[v].top()), pq[v].pop();
		for (i = 0; i <= siz[x] + siz[v]; i++) tmp2[i] = f[x][i];
		for (i = 0; i <= siz[x]; i++) for (j = 0; j <= siz[v]; j++) {
			tmp2[i + j] = min(tmp2[i + j], f[x][i] + f[v][j]);
		}
		siz[x] += siz[v];
		for (i = 0; i <= siz[x]; i++) f[x][i] = tmp2[i];
	}
	ll s = 0;
	for (i = 1; i <= siz[x]; i++) {
		s += pq[x].top(); tmp.push(pq[x].top()); pq[x].pop();
		f[x][i] = min(f[x][i], s);
	}
	while (!tmp.empty()) pq[x].push(tmp.top()), tmp.pop();
}

int main () {
	n = read(), b = read(); int i, j;
	c[1] = read(); d[1] = c[1] - read();
	for (i = 2; i <= n; i++) { c[i] = read(); d[i] = c[i] - read(); j = read(); E[j].push_back(i); }
	dfs(1);
	for (i = n; i >= 0; i--) if (f[1][i] <= b) { cout << i << endl; return 0; }
	puts("0");
	return 0;
}