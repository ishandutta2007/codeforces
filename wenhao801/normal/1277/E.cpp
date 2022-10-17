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

int n, m;
const int MAXN = 500500;

struct Edge {
    int nex;
    int to;
} edge[MAXN << 1] = {};
int head[MAXN << 1], cnt = 0;

void add (int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    head[u] = cnt;
}

int dfn[MAXN], low[MAXN];
bool ans[MAXN] = {};

void tarjan (int x, int fa) {
    dfn[x] = ++cnt;
    low[x] = cnt;
    int i, j;
    int treeson = 0;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (!dfn[j]) {
            tarjan(j, x);
            low[x] = min(low[x], low[j]);
            if (x != fa && low[j] >= dfn[x]) ans[x] = true;
            if (x == fa) treeson++;
        }
        else low[x] = min(low[x], dfn[j]);
    }
    if (x == fa && treeson >= 2) ans[x] = true;
}

bool vis[MAXN] = {};
int ansA, ansB;
int A, B;

void init () {
	cnt = 0;
	ansA = ansB = 0;
	int i;
	for (i = 1; i <= n; i++) head[i] = 0, dfn[i] = 0, low[i] = 0, ans[i] = false, vis[i] = false;
}

bool mA = false, mB = false;

void dfs (int x, bool o) {
	if (x == A) { mA = true; return; }
	if (x == B) { mB = true; return; }
	if (vis[x]) return;
	vis[x] = true;
	cnt++;
	int i, j;
	for (i = head[x]; i; i = edge[i].nex) dfs(edge[i].to, false);
	if (o) {
		if (mA && !mB) ansA += cnt;
		else if (mB && !mA) ansB += cnt;
	}
	return;
}

int main () {
	int T = read();
	while (T--) {
		n = read(), m = read(), A = read(), B = read();
		init();
		int u, v;
		int i, j;
		for (i = 1; i <= m; i++) {
			u = read(), v = read();
			add(u, v);
			add(v, u);
		}
		cnt = 0;
		tarjan(1, 1);
		if (!ans[A] || !ans[B]) {
			puts("0");
			continue;
		}
		vis[A] = vis[B] = true;
		for (i = 1; i <= n; i++)
			if (!vis[i]) cnt = 0, mA = mB = false, dfs(i, true);
		printf("%lld\n", (long long)(ansA) * (long long)(ansB));
	}
    return 0;
}