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

#define pii pair <int, int>
#define fr first
#define se second
const int MAXN = 30030;
int n, m, S, T; vector <pii> E[MAXN];
struct Edge { int u, v, w; } e[MAXN];

int f[MAXN], f2[MAXN];

int dfn[MAXN], low[MAXN], cnt, ban, res;
int ans = 2e9 + 7, cost, U, V;
bool tarjan (int x) {
    dfn[x] = low[x] = ++cnt; bool ret = x == T;
    for (auto i: E[x]) if (i.se != f2[x] && i.se != ban) {
        if (!dfn[i.fr]) {
            f[i.fr] = x, f2[i.fr] = i.se;
            bool tmp = tarjan(i.fr); ret |= tmp;
            low[x] = min(low[x], low[i.fr]);
            if (low[i.fr] == dfn[i.fr] && tmp) {
                if (e[res].w > e[i.se].w) res = i.se;
            }
        }
        else low[x] = min(low[x], dfn[i.fr]);
    }
    return ret;
}

vector <int> a;

int main () {
    e[0].w = 1e9 + 7;
    n = read(), m = read(); int i, j;
    S = read(), T = read();
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[i].u = u, e[i].v = v, e[i].w = w;
        E[u].emplace_back(v, i), E[v].emplace_back(u, i);
    }
    tarjan(S);
    if (!dfn[T]) { puts("0\n0"); return 0; }
    if (res) ans = e[res].w, cost = 1, U = res;
    for (i = T; i != S; i = f[i]) a.emplace_back(f2[i]);
    for (auto i: a) {
        ban = i;
        cnt = res = 0;
        for (j = 1; j <= n; j++) dfn[j] = low[j] = f[i] = f2[i] = 0;
        tarjan(S);
        if (dfn[T] && res) {
            int c = e[i].w + e[res].w;
            if (c < ans) ans = c, cost = 2, U = i, V = res;
        }
    }
    if (ans > 2e9) puts("-1");
    else {
        printf("%d\n", ans);
        if (cost == 1) printf("1\n%d\n", U);
        else printf("2\n%d %d\n", U, V);
    }
    return 0;
}