#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct treap {
    treap *lc, *rc;
    int val, pri, sz, tag;
    treap(int v): tag(0), val(v), pri(rand()), sz(1), lc(nullptr), rc(nullptr) {}
    void pull() { sz = 1 + (lc ? lc->sz : 0) + (rc ? rc->sz : 0); }
    void push() {
        if (tag == 0) return;
        if (lc) lc->val += tag, lc->tag += tag;
        if (rc) rc->val += tag, rc->tag += tag;
        tag = 0;
    }
};

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    a->push(); b->push();
    if (a->pri > b->pri) return a->rc = merge(a->rc, b), a->pull(), a;
    else return b->lc = merge(a, b->lc), b->pull(), b;
}

void split_by_val(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    t->push();
    if (t->val <= k) a = t, split_by_val(t->rc, k, a->rc, b), a->pull();
    else b = t, split_by_val(t->lc, k, a, b->lc), b->pull();
}

void split_by_sz(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    t->push();
    int lsz = (t->lc ? t->lc->sz : 0);
    if (lsz + 1 <= k) a = t, split_by_sz(t->rc, k - lsz - 1, a->rc, b), a->pull();
    else b = t, split_by_sz(t->lc, k, a, b->lc), b->pull();
}

int v[maxn], t[maxn];

void insert(treap *&t, int k) {
    treap *a, *b;
    split_by_val(t, k - 1, a, b);    
    t = merge(merge(a, new treap(k)), b);
}

int main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> t[i];
    treap *tr = nullptr;
    for (int i = 0; i < n; ++i) {
        insert(tr, v[i]);
        long long ans = 0;
        while (tr && tr->sz > 0) {
            treap *a, *b;
            split_by_sz(tr, 1, a, b);
            if (a->val > t[i]) {
                tr = merge(a, b);
                break;
            }
            ans += a->val;
            delete a;
            tr = b;
        }
        int sz = (tr ? tr->sz : 0);
        ans += t[i] * 1ll * sz;
        if (tr) tr->val -= t[i], tr->tag -= t[i];
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}