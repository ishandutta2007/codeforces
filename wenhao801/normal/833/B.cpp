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

const int MAXN = 35050;

int n, k;
int btmp[MAXN];
struct segtree {
    struct tree { int ls, rs, lazy, mx; }; tree t[MAXN << 2];
    int cnt = 1;
    void pushup (int x) { t[x].mx = max(t[t[x].ls].mx, t[t[x].rs].mx);  }
    void build (int l, int r, int x) {
        if (l == r) { t[x].ls = t[x].rs = t[x].lazy = 0, t[x].mx = btmp[l]; return; }
        int mid = (l + r) >> 1; t[x].lazy = 0;
        t[x].ls = ++cnt; build(l, mid, t[x].ls);
        t[x].rs = ++cnt; build(mid + 1, r, t[x].rs);
        pushup(x);
    }
    void init () { cnt = 1; build(1, n + 1, 1); }
    void pushdown (int x) {
        if (t[x].lazy) {
            t[t[x].ls].mx += t[x].lazy, t[t[x].ls].lazy += t[x].lazy;
            t[t[x].rs].mx += t[x].lazy, t[t[x].rs].lazy += t[x].lazy;
            t[x].lazy = 0;
        }
    }
    void modify (int l, int r, int L, int R, int x) {
        if (l <= L && R <= r) { ++t[x].mx, ++t[x].lazy; return; }
        pushdown(x); int mid = (L + R) >> 1;
        if (l <= mid) modify(l, r, L, mid, t[x].ls);
        if (mid < r) modify(l, r, mid + 1, R, t[x].rs);
        pushup(x);
    }
    int query (int l, int r, int L, int R, int x) {
        if (l > r) return 0;
        if (l <= L && R <= r) return t[x].mx;
        int ret = 0, mid = (L + R) >> 1; pushdown(x);
        if (l <= mid) ret = max(ret, query(l, r, L, mid, t[x].ls));
        if (mid < r) ret = max(ret, query(l, r, mid + 1, R, t[x].rs));
        return ret;
    }
} seg;

int las[MAXN], tmp[MAXN];
int a[MAXN], dp[MAXN][55];

int main () {
    n = read(), k = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= n; i++) las[i] = tmp[a[i]], tmp[a[i]] = i;
    for (i = 1; i <= k; i++) {
        seg.init();
        for (j = 1; j <= n; j++) {
            seg.modify(las[j] + 1, j, 1, n + 1, 1);
            btmp[j + 1] = dp[j][i] = seg.query(1, j, 1, n + 1, 1);
            // printf("%d ", dp[j][i]);
        }
    }
    printf("%d\n", dp[n][k]);
    return 0;
}