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

const int MAXN = 200200;

struct Edge {
	int nex;
	int to;
} edge[MAXN << 1];
int head[MAXN], cnt = 0;

void add (int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].nex = head[u];
	head[u] = cnt;
}

int dep[MAXN] = {};
int dep2[MAXN] = {};
int b[MAXN] = {};

int n, m, k;

#include <queue>
queue <int> q;

bool cmp (int x, int y) { return dep[x] < dep[y]; }
int main () {
	n = read(), m = read(), k = read();
	int i, j;
	for (i = 1; i <= k; i++) b[i] = read();
	for (i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	dep[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (i = head[f]; i; i = edge[i].nex) {
			j = edge[i].to;
			if (dep[j] || j == 1) continue;
			q.push(j);
			dep[j] = dep[f] + 1;
		}
	}
	dep2[n] = 0;
	while (!q.empty()) q.pop(); q.push(n);
	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (i = head[f]; i; i = edge[i].nex) {
			j = edge[i].to;
			if (dep2[j] || j == n) continue;
			q.push(j);
			dep2[j] = dep2[f] + 1;
		}
	}
	sort(b + 1, b + k + 1, cmp);
	int ans = 0;
	for (i = 1; i < k; i++) ans = max(ans, dep[b[i]] + 1 + dep2[b[i + 1]]);
	printf("%d\n", min(ans, dep[n]));
	return 0;
}