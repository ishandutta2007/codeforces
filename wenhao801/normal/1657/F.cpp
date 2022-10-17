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

#define vi vector <int>
#define all(v) v.begin(), v.end()
#define size(v) (int(v.size()))
const int MAXN = 1600600;

int n, q; vi E[MAXN];
int fa[MAXN], dep[MAXN];

void pre (int x, int f) {
    fa[x] = f, dep[x] = dep[f] + 1;
    for (auto i: E[x]) if (i != f) pre(i, x);
}
vi path (int u, int v) {
    vi vu, vv;
    while (dep[u] > dep[v]) vu.emplace_back(u), u = fa[u];
    while (dep[u] < dep[v]) vv.emplace_back(v), v = fa[v];
    while (u != v) vu.emplace_back(u), vv.emplace_back(v), u = fa[u], v = fa[v];
    vu.emplace_back(u); reverse(all(vv));
    for (auto i: vv) vu.emplace_back(i);
    return vu;
}

int c[MAXN][3], ans[MAXN]; char s[MAXN];

namespace twosat {
    int N;
    vi G[MAXN << 1];
    void add (int x, bool u, int y, bool v) {
        G[x + (!u) * N].emplace_back(y + v * N);
        G[y + (!v) * N].emplace_back(x + u * N);
    }
    int dfn[MAXN], low[MAXN], cnt, stk[MAXN], top, col[MAXN], cc;
    bool vis[MAXN];
    void tarjan (int x) {
        dfn[x] = low[x] = ++cnt; vis[x] = 1; stk[++top] = x;
        for (auto i: G[x]) {
            if (!dfn[i]) tarjan(i), low[x] = min(low[x], low[i]);
            else if (vis[i]) low[x] = min(low[x], dfn[i]);
        }
        if (low[x] == dfn[x]) {
            col[x] = ++cc; vis[x] = 0;
            while (stk[top] != x) col[stk[top]] = cc, vis[stk[top]] = 0, --top;
            --top;
        }
    }
    bool main () {
        for (int i = 1; i <= 2 * N; i++) if (!dfn[i]) tarjan(i);
        for (int i = 1; i <= N; i++) if (col[i] == col[N + i]) return 0;
        return 1;
    }
}

int main () {
    n = read(), q = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].emplace_back(v), E[v].emplace_back(u);
    }
    pre(1, 0); twosat::N = n + q;
    for (int qid = 1; qid <= q; qid++) {
        int u = read(), v = read(); scanf("%s", s);
        vi vec = path(u, v);
        for (int i = 0; i < size(vec); i++) {
            int cu = s[i] - 'a' + 1, cv = s[size(vec) - i - 1] - 'a' + 1;
            if (!c[vec[i]][0]) {
                c[vec[i]][0] = cu, c[vec[i]][1] = cv;
                if (cu == cv) ++c[vec[i]][1];
            }
            if (cu != c[vec[i]][0]) twosat::add(qid + n, 1, vec[i], 1);
            if (cu != c[vec[i]][1]) twosat::add(qid + n, 1, vec[i], 0);
            if (cv != c[vec[i]][0]) twosat::add(qid + n, 0, vec[i], 1);
            if (cv != c[vec[i]][1]) twosat::add(qid + n, 0, vec[i], 0);
        }
    }
    if (!twosat::main()) { puts("NO"); return 0; }
    for (i = 1; i <= n; i++) {
        if (c[i][0]) ans[i] = c[i][twosat::col[i] > twosat::col[i + twosat::N]];
        else ans[i] = 1;
    }
    puts("YES");
    for (i = 1; i <= n; i++) putchar('a' + ans[i] - 1);
    return 0;
}