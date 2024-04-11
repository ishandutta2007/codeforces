#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

struct treap {
    treap *lc, *rc;
    int pri, val, sz;
    treap(int v): val(v), sz(1), lc(nullptr), rc(nullptr), pri(rand()) {}
    void pull() { sz = (lc ? lc->sz : 0) + (rc ? rc->sz : 0) + 1; }
};

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) return a->rc = merge(a->rc, b), a->pull(), a;
    else return b->lc = merge(a, b->lc), b->pull(), b;
}

void split(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    if (t->val <= k) a = t, split(t->rc, k, a->rc, b), a->pull();
    else b = t, split(t->lc, k, a, b->lc), b->pull();
}

treap *uni(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    treap *p, *q;
    if (a->pri > b->pri) {
        split(b, a->val - 1, p, q);
        treap *t = new treap(a->val); t->pri = a->pri;
        return merge(uni(p, a->lc), merge(t, uni(q, a->rc)));
    } else {
        split(a, b->val - 1, p, q);
        treap *t = new treap(b->val); t->pri = b->pri;
        return merge(uni(p, b->lc), merge(t, uni(q, b->rc)));
    }
}

int left(treap *t) {
    if (t->lc) return left(t->lc);
    return t->val;
}

int ans[maxn];

void dfs(treap *t, int x) {
    if (!t) return;
    dfs(t->lc, x);
    ans[t->val] = x;
    dfs(t->rc, x);
}

treap *tr[101];

int main() {
    srand(time(nullptr));
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), tr[a[i]] = merge(tr[a[i]], new treap(i));
    int q; scanf("%d", &q); 
    while (q--) {
        int l, r, x, y; scanf("%d %d %d %d", &l, &r, &x, &y);
        if (x == y) continue;
        treap *a, *b, *c, *d;
        split(tr[x], l - 1, a, b), split(b, r, c, d);
        treap *e, *f, *g, *h;
        split(tr[y], l - 1, e, f), split(f, r, g, h);
        tr[x] = merge(a, d);
        treap *t = uni(c, g);
        tr[y] = merge(e, merge(t, h));
    }
    for (int i = 1; i <= 100; ++i) dfs(tr[i], i);
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]); puts("");
    return 0;
}