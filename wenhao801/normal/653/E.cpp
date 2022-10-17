#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 300300;
int n, m, K;

map <int, bool> E[MAXN];
queue <int> q; set <int> s, cs;

int cur, vis[MAXN];
void bfs (int S) {
    int i, j; q.push(S); s.erase(S); vis[S] = cur;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        cs = s;
        for (auto i: cs) if (!vis[i] && !E[x][i]) {
            vis[i] = cur; q.push(i); s.erase(i);
        }
    }
}

bool tmp[MAXN];

int main () {
    n = read(), m = read(), K = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        E[u][v] = 1, E[v][u] = 1;
    }
    for (i = 2; i <= n; i++) s.insert(i);
    for (i = 2; i <= n; i++) if (!vis[i]) ++cur, bfs(i);
    int deg = 0;
    for (i = 2; i <= n; i++) if (!E[1][i]) {
        tmp[vis[i]] = 1; ++deg;
    }
    for (i = 1; i <= cur; i++) if (!tmp[i]) { puts("impossible"); return 0; }
    puts(cur <= K && deg >= K ? "possible" : "impossible");
    return 0;
}