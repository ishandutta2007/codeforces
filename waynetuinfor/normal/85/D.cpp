#include <bits/stdc++.h>
#define int long long
#define tsize(t) (t ? t->sz : 0)
#define tsum(t) (t ? t->sum : 0)
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct treap {
    treap *lc, *rc;
    int val, pri, sum, sz;
    treap(int v): val(v) {
        lc = rc = nullptr;
        sz = 1;
        pri = rand();
        sum = v;
    }
    void pull() {
        sz = tsize(lc) + tsize(rc) + 1;
        sum = val + tsum(lc) + tsum(rc);
    }
} *tr[5], *another;

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
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

void split(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return (a = nullptr, b = nullptr), void();
    if (t->val <= k) {
        a = t;
        split(t->rc, k, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        b->pull();
    }
}

int get_pos(int v) {
    treap *a, *b;
    split(another, v - 1, a, b);
    int ret = tsize(a) + 1;
    another = merge(a, b);
    return ret;
}

vector<treap*> get_suff(int v) {
    vector<treap*> ret;
    for (int i = 0; i < 5; ++i) {
        treap *a, *b;
        split(tr[i], v, a, b);
        ret.push_back(b);
        tr[i] = a;
    }
    return ret;
}

void insert(treap *&t, int v) {
    treap *a, *b;
    split(t, v - 1, a, b);
    t = merge(merge(a, new treap(v)), b);
}

void erase(treap *&t, int v) {
    treap *a, *b, *c, *d;
    split(t, v - 1, a, b);
    split(b, v, c, d);
    t = merge(a, d);
}

int32_t main() {
    srand(7122);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s == "add") {
            int x; cin >> x;
            int k = get_pos(x);
            vector<treap*> suff = get_suff(x);
            for (int i = 0; i < 5; ++i) {
                int j = (i + 1) % 5;
                tr[j] = merge(tr[j], suff[i]);
            }
            insert(tr[k % 5], x);
            insert(another, x);
        }
        if (s == "del") {
            int x; cin >> x;
            int k = get_pos(x);
            vector<treap*> suff = get_suff(x);
            for (int i = 0; i < 5; ++i) {
                int j = (i - 1 + 5) % 5;
                tr[j] = merge(tr[j], suff[i]);
            }
            erase(tr[k % 5], x);
            erase(another, x);
        }
        if (s == "sum") {
            cout << tsum(tr[3]) << '\n';
        }
    }
    return 0;
}