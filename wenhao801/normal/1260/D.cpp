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

const int MAXN = 400400;
int m, n, k, T;
int a[MAXN] = {};

bool cmp (int x, int y) { return x > y; }

int tree[MAXN << 1] = {};
int lazy[MAXN << 1] = {};

void pushup (int root) { tree[root] = max(tree[root << 1], tree[root << 1 | 1]); }
void pushdown (int l, int r, int root) {
    tree[root << 1] = max(tree[root << 1], lazy[root]);
    tree[root << 1 | 1] = max(tree[root << 1 | 1], lazy[root]);
    lazy[root << 1] = max(lazy[root << 1], lazy[root]);
    lazy[root << 1 | 1] = max(lazy[root << 1 | 1], lazy[root]);
    lazy[root] = 0;
}

void build (int l, int r, int root) {
    if (l == r) { tree[root] = 0; return; }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
}

void modify (int l, int r, int k, int L, int R, int root) {
    //printf("mod(%d %d %d %d %d %d)\n", l, r, k, L, R, root);
    if (l <= L && R <= r) {
        tree[root] = max(tree[root], k);
        lazy[root] = max(lazy[root], k);
        return;
    }
    pushdown(L, R, root);
    int mid = (L + R) >> 1;
    if (mid >= l) modify(l, r, k, L, mid, root << 1);
    if (mid < r) modify(l, r, k, mid + 1, R, root << 1 | 1);
    pushup(root);
    return;
}

int query (int l, int r, int L, int R, int root) {
    if (l <= L && R <= r) return tree[root];
    pushdown(L, R, root);
    int mid = (L + R) >> 1;
    int ret = 0;
    if (mid >= l) ret = max(ret, query(l, r, L, mid, root << 1));
    if (mid < r) ret = max(ret, query(l, r, mid + 1, R, root << 1 | 1));
    pushup(root);
    return ret;
}

bool check (int x) {
    if (x == 0) return true;
    int tot = 0;
    int i, j;
    int rua = a[x];
    for (i = 1; i <= n; i++) {
        if (query(i, i, 1, n, 1) > rua) tot += 3;
        else tot++;
    }
    return tot <= T;
}

int main () {
    m = read(), n = read() + 1, k = read(), T = read();
    int i, j;
    for (i = 1; i <= m; i++) a[i] = read();
    for (i = 1; i <= k; i++) {
        int l = read(), r = read(), d = read();
        modify(l, r, d, 1, n, 1);
    }
    sort(a + 1, a + m + 1, cmp);
    int l = 0, r = m;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}