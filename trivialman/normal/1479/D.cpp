#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define PB push_back
const int N = 3e5 + 5;
mt19937 rng(time(0));

struct dat {
    int l, r, x;
} tr[N << 5];
int T, n, m, q, x, y, z, l, r, cnt = 0;
int a[N], fa[N], occ[N], root[N], ha[N];
array<int, 2> st[20][N << 1];
vector<int> g[N];

void bil(int &node, int old) { tr[node = ++cnt] = tr[old]; }

void upd(int idx, int i, int x, int l = 1, int r = n) {
    if (l == r)
        tr[idx].x ^= x;
    else {
        int mid = l + r >> 1;
        if (i <= mid) bil(tr[idx].l, tr[idx].l), upd(tr[idx].l, i, x, l, mid);
        else bil(tr[idx].r, tr[idx].r), upd(tr[idx].r, i, x, mid + 1, r);
        tr[idx].x = tr[tr[idx].l].x ^ tr[tr[idx].r].x;
    }
}

void dfs(int x, int f, int d) {
    bil(root[x], root[f]);
    upd(root[x], a[x], ha[a[x]]);
    st[0][++m] = {d, x}, occ[x] = m, fa[x] = f;
    for (auto u : g[x]) if (u != f)
        dfs(u, x, d + 1), st[0][++m] = {d, x};
}

inline int lca(int x, int y) {
    int l = min(occ[x], occ[y]), r = max(occ[x], occ[y]), i = log2(r - l);
    return l == r ? x : min(st[i][l], st[i][r - (1 << i)])[1];
}

int find(int i1, int i2, int i3, int i4, int l1, int r1, int l2 = 1, int r2 = n) {
    if ((tr[i1].x ^ tr[i2].x ^ tr[i3].x ^ tr[i4].x) == 0) return -1;
    if (l2 == r2) return tr[i1].x ^ tr[i2].x ^ tr[i3].x ^ tr[i4].x ? l2 : -1;
    int mid = l2 + r2 >> 1, res = -1;
    if (l1 <= mid) res = find(tr[i1].l, tr[i2].l, tr[i3].l, tr[i4].l, l1, r1, l2, mid);
    if (res == -1 && r1 > mid) res = find(tr[i1].r, tr[i2].r, tr[i3].r, tr[i4].r, l1, r1, mid + 1, r2);
    return res;
}

int main() {
    scanf("%d%d", &n, &q);
    rep(i, 1, n) ha[i] = rng();
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n - 1) scanf("%d%d", &x, &y), g[x].PB(y), g[y].PB(x);
    dfs(1, 0, 1);
    rep(i, 1, 19) rep(j, 1, m) st[i][j] = min(st[i - 1][j], st[i - 1][min(j + (1 << i - 1), m)]);

    rep(i, 1, q) {
        scanf("%d%d%d%d", &x, &y, &l, &r), z = lca(x, y);
        printf("%d\n", find(root[x], root[y], root[z], root[fa[z]], l, r));
    }
    return 0;
}