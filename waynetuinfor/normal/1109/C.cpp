#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(347189);

struct treap {
    treap *lc, *rc, *prv, *nxt, *st, *ed;
    long long sum, pref, half;
    int v, t, pri; 
    treap(int t, int v): lc(nullptr), rc(nullptr), prv(nullptr), nxt(nullptr), st(this), ed(this),
                         pri(rng()), v(v), sum(0), t(t), pref(0), half(0) {}
    void pull() {
        pref = sum = half = 0;
        prv = nxt = nullptr;
        st = ed = this;
        if (lc) {
            lc->ed->nxt = this;
            prv = lc->ed;
            st = lc->st;
            pref = max(pref, lc->pref);
            assert(prv);
            half = sum = lc->sum + (t - prv->t) * 1ll * prv->v;
            pref = max(pref, sum);
        } 
        if (rc) {
            rc->st->prv = this;
            nxt = rc->st;
            ed = rc->ed;
            pref = max(pref, sum + (nxt->t - t) * 1ll * v + rc->pref);
            assert(nxt);
            sum += rc->sum + (nxt->t - t) * 1ll * v;
            pref = max(pref, sum);
        }
    }
};

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) return a->rc = merge(a->rc, b), a->pull(), a;
    else return b->lc = merge(a, b->lc), b->pull(), b;
}

void split(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    if (t->t <= k) a = t, split(t->rc, k, a->rc, b), a->pull();
    else b = t, split(t->lc, k, a, b->lc), b->pull();
}

void insert(treap *&tr, int t, int s) {
    treap *a, *b;
    split(tr, t - 1, a, b);
    tr = merge(merge(a, new treap(t, s)), b);
}

void erase(treap *&tr, int t) {
    treap *a, *b, *c, *d;
    split(tr, t - 1, a, b);
    split(b, t, c, d);
    delete c;
    tr = merge(a, d);
}

int dfs(treap *t, long long v) {
    if (t->lc && t->lc->pref >= v) return dfs(t->lc, v);
    if (t->half >= v) return t->t;
    if (t->rc && t->rc->pref + t->half + (t->nxt->t - t->t) * 1ll * t->v >= v) return dfs(t->rc, v - (t->half + (t->nxt->t - t->t) * 1ll * t->v));
    return -1;
}

treap *right(treap *tr) {
    treap *res = tr;
    while (res->rc) res = res->rc;
    return res;
}

treap *find(treap *tr, int t) {
    if (tr->t == t) return tr;
    if (tr->t > t) return find(tr->lc, t);
    else return find(tr->rc, t);
}

int main() {
    int q; scanf("%d", &q);
    treap *bst = nullptr;
    set<int> f;
    for (int i = 0; i < q; ++i) {
        int z; scanf("%d", &z);
        if (z == 1) {
            int t, s; scanf("%d%d", &t, &s);
            insert(bst, t, -s);
            f.insert(t);
        }
        if (z == 2) {
            int t; scanf("%d", &t);
            erase(bst, t);
            f.erase(t);
        }
        if (z == 3) {
            int l, r, v; scanf("%d%d%d", &l, &r, &v);
            if (v == 0) {
                printf("%.20lf\n", 1.0 * l);
                continue;
            }
            auto itl = f.lower_bound(l);
            auto itr = f.upper_bound(r);
            if (itl == f.end() || itr == f.begin()) {
                puts("-1");
                continue;
            }
            itr = prev(itr);
            int tl = *itl, tr = *itr;
            if (tl > tr) {
                puts("-1");
                continue;
            }
            treap *a, *b, *c, *d;
            split(bst, tl - 1, a, b);
            split(b, tr, c, d);
            if (!c) {
                puts("-1");
                bst = merge(a, merge(c, d));
                continue;
            }
            int x = dfs(c, v);
            if (x == -1) {
                treap *y = right(c);
                assert(c->pref < v);
                if (c->sum + y->v * 1ll * (r - y->t) >= v) printf("%.20lf\n", y->t + 1.0 * (v - c->sum) / y->v);
                else puts("-1");
            } else {
                int z = *prev(f.lower_bound(x));
                treap *lz, *rz;
                split(c, z, lz, rz); 
                assert(lz->sum <= v);
                double need = 1.0 * (v - lz->sum) / lz->ed->v;
                printf("%.20lf\n", lz->ed->t + need);
                c = merge(lz, rz);
            }
            bst = merge(a, merge(c, d));
        }
    }
}