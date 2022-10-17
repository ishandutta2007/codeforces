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

struct Edge {
	int nex;
	int to;
} edge[2020];
int head[1010], cnt = 0;

void add (int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].nex = head[u];
	head[u] = cnt;
}

int n;

int p, q;
bool vis[1010];

void dfs (int x, int f) {
	int i, j, k = 0;
	for (i = head[x]; i; i = edge[i].nex) {
		j = edge[i].to;
		if (j == f || vis[j]) continue;
		k++, dfs(j, x);
	}
	if (!k || (!f && k == 1)) {
		if (!p) p = x;
		else if (!q) q = x;
	}
}

int main () {
	n = read();
	int i, j;
	for (i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	for (i = 1; i <= n / 2; i++) {
		p = q = 0;
		for (j = 1; j <= n && vis[j]; j++);
		dfs(j, 0);
		printf("? %d %d\n", p, q); fflush(stdout);
		int res = read();
		if (res == p) { printf("! %d\n", p); fflush(stdout); return 0; }
		if (res == q) { printf("! %d\n", q); fflush(stdout); return 0; }
		vis[p] = vis[q] = true;
	}
	for (i = 1; i <= n && vis[i]; i++);
	printf("! %d\n", i); fflush(stdout);
	return 0;
}