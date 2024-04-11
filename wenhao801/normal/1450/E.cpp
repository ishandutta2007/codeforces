#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 220;
int n, m;

struct edge { int u, v, w; } e[2020];
int dis[MAXN][MAXN];
void chkmin(int &u, int v) { u = min(u, v); }

int main() {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) dis[i][j] = i == j ? 0 : 1e9;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        if (w) chkmin(dis[u][v], 1), chkmin(dis[v][u], -1);
        else chkmin(dis[u][v], 1), chkmin(dis[v][u], 1);
        e[i] = {u, v, w};
    }
    for (int k = 1; k <= n; k++) for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
        chkmin(dis[i][j], dis[i][k] + dis[k][j]);
    for (int k = 1; k <= n; k++) for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
        chkmin(dis[i][j], dis[i][k] + dis[k][j]);
    for (i = 1; i <= n; i++) if (dis[i][i] < 0) { puts("NO"); return 0; }
    int ans = -1, id = 0;
    for (i = 1; i <= n; i++) {
        if (*min_element(dis[i] + 1, dis[i] + n + 1) >= 0) {
            for (j = 1; j <= m; j++) {
                int u = e[j].u, v = e[j].v, w = e[j].w;
                if (!w && abs(dis[i][u] - dis[i][v]) != 1) break;
                if (w && dis[i][v] != dis[i][u] + 1) break;
            }
            if (j <= m) continue;
            if (ans < *max_element(dis[i] + 1, dis[i] + n + 1)) ans = *max_element(dis[i] + 1, dis[i] + n + 1), id = i;
        }
    }
    if (ans == -1) { puts("NO"); return 0; }
    puts("YES"); printf("%d\n", ans);
    for (i = 1; i <= n; i++) cout << dis[id][i] << ' '; cout << endl;
    return 0;
}