#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5, log_t = 17;
int l[log_t][maxn], r[log_t][maxn], a[maxn];

namespace segtree {
    pair<int, int> st[log_t][maxn * 4]; 
    pair<int, int> merge(const pair<int, int> &x, const pair<int, int> &y) {
        int fi = min(x.first, y.first);
        int se = max(x.second, y.second);
        return make_pair(fi, se);
    }
    void build(int l, int r, int i, int a[], int b[], int o = 0) {
        if (r - l == 1) return st[i][o] = make_pair(a[l], b[l]), void();
        build(l, (l + r) >> 1, i, a, b, o * 2 + 1);
        build((l + r) >> 1, r, i, a, b, o * 2 + 2);
        st[i][o] = merge(st[i][o * 2 + 1], st[i][o * 2 + 2]);
    }
    pair<int, int> query(int l, int r, int ql, int qr, int i, int o = 0) {
        if (l >= qr || ql >= r) return make_pair(maxn, -1);
        if (l >= ql && r <= qr) return st[i][o];
        return merge(query(l, (l + r) >> 1, ql, qr, i, o * 2 + 1),
                     query((l + r) >> 1, r, ql, qr, i, o * 2 + 2));
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = n; i < n + n; ++i) scanf("%d", &a[i]);
    if (n == 1) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) a[i] = a[i + n];
    for (int i = n + n; i < n + n + n; ++i) a[i] = a[i - n];
    for (int i = 0; i < n + n + n; ++i) {
        l[0][i] = max(0, i - a[i]);
        r[0][i] = min(n + n + n - 1, i + a[i]);
    }
    for (int i = 1; i < log_t; ++i) {
        segtree::build(0, n + n + n, i - 1, l[i - 1], r[i - 1]);
        for (int j = 0; j < n + n + n; ++j) 
            tie(l[i][j], r[i][j]) = segtree::query(0, n + n + n, l[i - 1][j], r[i - 1][j] + 1, i - 1);
    }
    segtree::build(0, n + n + n, log_t - 1, l[log_t - 1], r[log_t - 1]);
    for (int i = 0; i < n; ++i) {
        int tl = i + n, tr = i + n, ans = 0;
        for (int j = log_t - 1; j >= 0; --j) {
            int ql, qr;
            tie(ql, qr) = segtree::query(0, n + n + n, tl, tr + 1, j);
            if (qr - ql + 1 < n) {
                tl = ql, tr = qr;
                ans ^= (1 << j);
            }
        }
        printf("%d ", ans + 1);
    }
    puts("");
    return 0;
}