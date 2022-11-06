#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 2e5 + 5;
const long long rand_c = 124789124789ll, rand_d = 128749017495ll;
long long h[maxn], d[maxn];

long long rnd() {
    static long long x = 1374890789ll;
    return x = (x ^ rand_c) + rand_d;
}

struct treap {
    treap *lc, *rc;
    long long sum, val;
    int sz, pri;
    treap(long long v): val(v), sum(v), lc(nullptr), rc(nullptr), sz(1), pri(rand()) {}
    void pull() {
        sz = 1, sum = val;
        if (lc) sz += lc->sz, sum += lc->sum;
        if (rc) sz += rc->sz, sum += rc->sum;
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

void split_by_sz(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    int lsz = (t->lc ? t->lc->sz : 0);
    if (lsz + 1 <= k) a = t, split_by_sz(t->rc, k - lsz - 1, a->rc, b), a->pull();
    else b = t, split_by_sz(t->lc, k, a, b->lc), b->pull();
}

void insert(treap *&t, long long v) {
    if (v <= 0) return;
    treap *a, *b;
    split(t, v - 1, a, b);
    t = merge(merge(a, new treap(v)), b);
}

void erase(treap *&t, long long v) {
    if (v <= 0) return;
    treap *a, *b, *c, *d;
    split(t, v - 1, a, b);
    split(b, v, c, d);
    treap *e = merge(c->lc, c->rc);
    t = merge(a, merge(e, d));
}

int main() {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    long long s = 0;
    for (int i = 0; i < n; ++i) scanf("%lld %lld", &h[i], &d[i]), s += d[i];
    long long c = (1 << a);
    treap *tr = nullptr;
    for (int i = 0; i < n; ++i) insert(tr, h[i] - d[i]);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        erase(tr, h[i] - d[i]);
        long long z = h[i] * c;
        insert(tr, z - d[i]);
        int sz = max(0, (tr ? tr->sz : 0) - b);
        treap *l, *r;
        split_by_sz(tr, sz, l, r);
        long long p = s + (r ? r->sum : 0);
        ans = max(ans, p);
        tr = merge(l, r);
        erase(tr, z - d[i]);
        insert(tr, h[i] - d[i]);
    }
    printf("%lld\n", ans);
}