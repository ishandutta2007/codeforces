#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int x[maxn], h[maxn], ans[maxn];

struct segtree {
    segtree *lc, *rc;
    int tag, v;
    segtree(int l, int r) {
        v = tag = 0;
        if (l == r) lc = rc = nullptr;
        else lc = new segtree(l, (l + r) / 2), rc = new segtree((l + r) / 2 + 1, r);
    }
    void modify(int l, int r, int ql, int qr, int x) {
        push();
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) return v += x, tag += x, void();
        lc->modify(l, (l + r) / 2, ql, qr, x), rc->modify((l + r) / 2 + 1, r, ql, qr, x);
        v = max(lc->v, rc->v);
    }
    int query(int l, int r, int ql, int qr) {
        push();
        if (l > qr || ql > r) return 0;
        if (l >= ql && r <= qr) return v;
        return max(lc->query(l, (l + r) / 2, ql, qr), rc->query((l + r) / 2 + 1, r, ql, qr));
    }
    void push() {
        if (tag == 0 || lc == nullptr) return;
        lc->tag += tag; lc->v += tag; rc->tag += tag; rc->v += tag;
        tag = 0;
    }
} *sgt;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", x + i, h + i);
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sgt = new segtree(0, n - 1);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return x[i] < x[j]; });
    for (int i = n - 1; i >= 0; --i) {
        int d = 30, t = i;
        while (d--) if (t + (1 << d) < o.size()) if (x[o[t + (1 << d)]] < x[o[i]] + h[o[i]]) t += (1 << d);
        if (t == i) ans[i] = 1;
        else ans[i] = sgt->query(0, n - 1, i + 1, t);
        sgt->modify(0, n - 1, i, n - 1, 1);
        sgt->modify(0, n - 1, i, i, ans[i]);
        // printf("i = %d t = %d\n", i, t);
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i) p[o[i]] = i;
    // for (int i = 0; i < n; ++i) printf("%d ", p[i]); puts("");
    for (int i = 0; i < n; ++i) printf("%d ", ans[p[i]]); puts("");
    return 0;
}