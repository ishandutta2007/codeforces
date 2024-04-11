#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, lg = 20;
int p[maxn], l[maxn], to[maxn], nxt[lg][maxn];
long long w[lg][maxn];

struct segtree {
#define m ((l + r) >> 1)
    int maxv;
    segtree *lc, *rc;
    segtree(int l, int r) {
        maxv = 0;
        if (l == r) lc = rc = nullptr;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r);
    }
    void pull() { maxv = max(lc->maxv, rc->maxv); }
    int query(int l, int r, int ql, int qr) {
        if (l > qr || ql > r) return 0;
        if (l >= ql && r <= qr) return maxv;
        return max(lc->query(l, m, ql, qr), rc->query(m + 1, r, ql, qr));
    }
    void modify(int l, int r, int p, int v) {
        if (l == r) return maxv = max(maxv, v), void();
        if (p <= m) lc->modify(l, m, p, v);
        else rc->modify(m + 1, r, p, v);
        pull();
    }
#undef m
} *sgt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i] >> l[i];
    sgt = new segtree(1, n);
    for (int i = n; i > 0; --i) {
        to[i] = upper_bound(p + 1, p + n + 1, p[i] + l[i]) - p - 1;
        to[i] = max(p[i] + l[i], sgt->query(1, n, i, to[i]));
        sgt->modify(1, n, i, to[i]);
    }
    for (int i = 0; i < lg; ++i) for (int j = 0; j < maxn; ++j) nxt[i][j] = w[i][j] = maxn;
    for (int i = 1; i <= n; ++i) {
        nxt[0][i] = upper_bound(p + 1, p + n + 1, to[i]) - p; 
        nxt[0][i] = min(nxt[0][i], n);
        w[0][i] = max(0, p[nxt[0][i]] - to[i]);
    }
    for (int j = 1; j < lg; ++j) {
        for (int i = 1; i <= n; ++i) if (nxt[j - 1][i] < n) {
            nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
            w[j][i] = w[j - 1][i] + w[j - 1][nxt[j - 1][i]];
        }
    }
    int q; cin >> q; while (q--) {
        int l, r; cin >> l >> r;
        long long ans = 0;
        for (int i = lg - 1; i >= 0; --i) {
            if (nxt[i][l] <= r) ans += w[i][l], l = nxt[i][l];
        }
        if (l < r) ans += max(0, p[r] - to[l]);
        cout << ans << endl;
    }
    return 0;
}