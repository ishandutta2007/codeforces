#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
#define size(t) (t ? t->sz : 0)

struct treap {
    treap *lc, *rc;
    int val, pri, sz;
    bool tag;
    treap(int v): val(v) {
        pri = rand();
        lc = rc = nullptr;
        sz = 1;
        tag = false;
    }
    void pull() {
        sz = size(lc) + size(rc) + 1;
    }
    void push() {
        if (!tag) return;
        if (lc) lc->tag = !lc->tag;
        if (rc) rc->tag = !rc->tag;
        swap(lc, rc);
        tag = false;
    }
} *t;

treap* merge(treap* a, treap* b) {
    if (!a || !b) return a ? a : b;
    a->push(); b->push();
    if (a->pri > b->pri) {
        a->rc = merge(a->rc, b);
        a->pull();
        return a;
    } else {
        b->lc = merge(a, b->lc);
        b->pull();
        return b;
    }
}

void split(treap* t, int k, treap*& a, treap*& b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    t->push();
    if (k >= size(t->lc) + 1) {
        a = t;
        split(t->rc, k - size(t->lc) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        b->pull();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, m; cin >> n >> q >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        t = merge(t, new treap(a[i]));
    }
    while (q--) {
        int tp, l, r; cin >> tp >> l >> r;
        if (tp == 1) {
            treap *a, *b, *c, *d, *e, *f;
            split(t, l - 1, a, b);
            split(b, r - l, c, d);
            split(d, 1, e, f);
            t = merge(merge(a, e), merge(c, f));
        } else {
            treap *a, *b, *c, *d;
            split(t, l - 1, a, b);
            split(b, r - l + 1, c, d);
            c->tag = !c->tag;
            t = merge(a, merge(c, d));
        }
    }
    for (int i = 1; i <= m; ++i) {
        int k; cin >> k;
        treap *a, *b, *c, *d;
        split(t, k - 1, a, b);
        split(b, 1, c, d);
        cout << c->val << ' ';
        t = merge(a, merge(c, d));
    }
    cout << endl;
    return 0;
}