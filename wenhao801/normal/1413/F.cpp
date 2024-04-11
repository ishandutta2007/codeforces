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

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 500500;
int dep[MAXN], fa[MAXN], siz[MAXN], dfn[MAXN], idfn[MAXN], cnt, n;
pii e[MAXN]; int w[MAXN]; vector <int> E[MAXN];

void dfs (int x, int f) {
    fa[x] = f, dep[x] = dep[f] + 1, siz[x] = 1;
    ++cnt; dfn[x] = cnt, idfn[cnt] = x;
    for (auto i: E[x]) if (i != f) {
        dfs(i, x);
        siz[x] += siz[i];
    }
}

int t[MAXN << 2][2], val[MAXN]; bool tag[MAXN << 2];
void pre (int x, int f) {
    val[x] ^= val[f];
    for (auto i: E[x]) if (i != f) pre(i, x);
}

void pushup (int x) {
    t[x][0] = max(t[x << 1][0], t[x << 1 | 1][0]);
    t[x][1] = max(t[x << 1][1], t[x << 1 | 1][1]);
}
void cover (int x) {
    swap(t[x][0], t[x][1]);
    tag[x] ^= 1;
}
void pushdown (int x) {
    if (tag[x]) {
        cover(x << 1), cover(x << 1 | 1);
        tag[x] = 0;
    }
}
void build (int l, int r, int x) {
    t[x][0] = t[x][1] = tag[x] = 0;
    if (l == r) { t[x][val[idfn[l]]] = dep[idfn[l]]; return; }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
    pushup(x);
}
void modify (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) { cover(x); return; }
    int mid = (L + R) >> 1; pushdown(x);
    if (l <= mid) modify(l, r, L, mid, x << 1);
    if (mid < r) modify(l, r, mid + 1, R, x << 1 | 1);
    pushup(x);
}

int qrs[MAXN], ans[MAXN];

int main () {
    n = read(); int i, j, k;
    for (i = 1; i < n; i++) {
        e[i].fr = read(), e[i].se = read(); w[i] = read();
        E[e[i].fr].push_back(e[i].se), E[e[i].se].push_back(e[i].fr);
    }
    dfs(1, 0); for (i = 1, j = 1; i <= n; i++) j = (dep[i] > dep[j] ? i : j);
    cnt = 0; dfs(j, 0);
    for (i = 1; i < n; i++)
        val[dep[e[i].fr] < dep[e[i].se] ? e[i].se : e[i].fr] = w[i];
    pre(j, 0);
    for (i = 1, k = 1; i <= n; i++) k = (dep[i] > dep[k] ? i : k);

    build(1, n, 1);
    int m = read();
    for (i = 1; i <= m; i++) {
        qrs[i] = read();
        int x = qrs[i]; x = dep[e[x].fr] < dep[e[x].se] ? e[x].se : e[x].fr;
        modify(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
        ans[i] = t[1][0] - 1;
    }

    cnt = 0; dfs(k, 0); memset(val, 0, sizeof val);
    for (i = 1; i < n; i++)
        val[dep[e[i].fr] < dep[e[i].se] ? e[i].se : e[i].fr] = w[i];
    pre(k, 0);

    build(1, n, 1);
    for (i = 1; i <= m; i++) {
        int x = qrs[i]; x = dep[e[x].fr] < dep[e[x].se] ? e[x].se : e[x].fr;
        modify(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
        printf("%d\n", max(ans[i], t[1][0] - 1));
    }
    
    return 0;
}