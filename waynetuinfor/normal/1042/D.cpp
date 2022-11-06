#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
long long a[maxn], s[maxn];

struct treap {
    treap *lc, *rc;
    long long val;
    int pri, sz;
    treap(long long v): pri(rand()), sz(1), val(v), lc(nullptr), rc(nullptr) {}
    void pull() {
        sz = 1;
        if (lc) sz += lc->sz;
        if (rc) sz += rc->sz;
    }
};

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) return a->rc = merge(a->rc, b), a->pull(), a;
    else return b->lc = merge(a, b->lc), b->pull(), b;
}

void split(treap *t, long long k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    if (t->val <= k) a = t, split(t->rc, k, a->rc, b), a->pull();
    else b = t, split(t->lc, k, a, b->lc), b->pull();
}

void insert(treap *&t, long long v) {
    treap *a, *b;
    split(t, v - 1, a, b);
    t = merge(merge(a, new treap(v)), b);
}

void dfs(treap *tr) {
    if (tr->lc) dfs(tr->lc);
    printf("%lld ", tr->val);
    if (tr->rc) dfs(tr->rc);
}

int main() {
    srand(clock());
    int n;
    long long t; scanf("%d %lld", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    long long ans = 0;
    treap *tr = new treap(0);
    for (int i = 1; i <= n; ++i) {
        treap *a, *b;
        split(tr, s[i] - t, a, b);
        if (b) ans += b->sz;
        tr = merge(a, b);
        insert(tr, s[i]);
    }
    printf("%lld\n", ans);
}