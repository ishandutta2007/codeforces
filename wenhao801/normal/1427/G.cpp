#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
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

using ll = long long;
using pii = pair <int, int>;
#define fr first
#define se second
const int MAXN = 220, inf = 8;
int n, a[MAXN][MAXN];

pii b[MAXN * MAXN]; int top;

struct Edge { int nex, to, f; } edge[MAXN * MAXN * 8];
int head[MAXN * MAXN], cnt = 1;
int add(int u, int v, int f) {
    edge[++cnt].to = v; edge[cnt].nex = head[u]; head[u] = cnt; edge[cnt].f = f;
    edge[++cnt].to = u; edge[cnt].nex = head[v]; head[v] = cnt; edge[cnt].f = 0;
    return cnt - 1;
}

queue <int> q; int S, T;
bool vis[MAXN * MAXN];
int push(int x, int rem, int t) {
    if (!rem || x == t) return rem;
    vis[x] = 1;
    for (int i = head[x]; i; i = edge[i].nex) if (edge[i].f && !vis[edge[i].to]) {
        int tmp = push(edge[i].to, min(edge[i].f, rem), t);
        if (tmp) { edge[i].f -= tmp, edge[i ^ 1].f += tmp; return tmp; }
    }
    return 0;
}
int EK(int s, int t, int rem) {
    int ret = 0;
    while (rem) {
        memset(vis, 0, sizeof vis);
        int tmp = push(s, rem, t);
        if (!tmp) break;
        rem -= tmp, ret += tmp;
    } 
    return ret;
}

inline int tr(int x, int y) { return (x - 1) * n + y; }
int id[MAXN * MAXN];

const int to[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    n = read(); int i, j;
    S = n * n + 1, T = S + 1;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) {
        a[i][j] = read();
        if (a[i][j] >= 1) {
            b[++top] = {a[i][j], tr(i, j)};
            id[tr(i, j)] = add(tr(i, j), T, inf);
        }
    }
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) if (a[i][j] != -1) {
        for (int k = 0; k < 4; k++) {
            int tx = i + to[k][0], ty = j + to[k][1];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && a[tx][ty] != -1)
                add(tr(i, j), tr(tx, ty), 1);
        }
    }
    sort(b + 1, b + top + 1);
    ll cur = 0, ans = 0;
    b[top + 1].fr = b[top].fr;
    for (i = 1; i <= top; i = j) {
        for (j = i; b[j].fr == b[i].fr; j++) {
            int tmp = edge[id[b[j].se] ^ 1].f; cur -= tmp;
            edge[id[b[j].se]].f = edge[id[b[j].se] ^ 1].f = 0;
            assert(EK(b[j].se, S, tmp) == tmp);
            add(S, b[j].se, inf); cur += EK(S, T, inf);
        }
        ans += cur * (b[j].fr - b[i].fr);
    }
    printf("%lld\n", ans);
    return 0;
}