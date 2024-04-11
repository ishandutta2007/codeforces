#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 200200;
const int inf = 1e9 + 7;

int n;
int a[MAXN] = {};

struct Edge {
    int nex;
    int to;
} edge[MAXN << 1];
int head[MAXN], cnt = 0;

void add (int u, int v) {
    swap(u, v);
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    head[u] = cnt;
}

int dis[MAXN] = {};

queue <int> q;

int main () {
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) {
        if (i - a[i] >= 1) {
            if (a[i] % 2 != a[i - a[i]] % 2) add(i, n + 1);
            else add(i, i - a[i]);
        }
        if (i + a[i] <= n) {
            if (a[i] % 2 != a[i + a[i]] % 2) add(i, n + 1);
            else add(i, i + a[i]);
        }
    }
    for (i = 1; i <= n; i++) dis[i] = inf;
    q.push(n + 1);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (i = head[f]; i; i = edge[i].nex) if (dis[edge[i].to] == inf) q.push(edge[i].to), dis[edge[i].to] = dis[f] + 1;
    }
    for (i = 1; i <= n; i++) if (dis[i] == inf) printf("-1 "); else printf("%d ", dis[i]);
    return 0;
}