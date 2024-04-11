#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const long long inf = 1e18;
int t[maxn], o[maxn];
int n, k, b, c;

struct treap {
    treap *lc, *rc;
    long long sum, val, tag;
    int pri, sz;
    treap(long long v): val(v), tag(0), pri(rand()), sz(1), sum(v), lc(nullptr), rc(nullptr) {}
    void pull() {
        sz = (lc ? lc->sz : 0) + (rc ? rc->sz : 0) + 1;
        sum = (lc ? lc->sum : 0) + (rc ? rc->sum : 0) + val;
    }
    void push() {
        if (tag == 0) return;
        if (lc) lc->tag += tag, lc->val += tag, lc->sum += lc->sz * 1ll * tag;
        if (rc) rc->tag += tag, rc->val += tag, rc->sum += rc->sz * 1ll * tag;
        tag = 0;
    } 
};

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    a->push(); b->push();
    if (a->pri > b->pri) return a->rc = merge(a->rc, b), a->pull(), a;
    else return b->lc = merge(a, b->lc), b->pull(), b;
}

void split_by_sz(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    t->push();
    int lsz = (t->lc ? t->lc->sz : 0);
    if (lsz + 1 <= k) a = t, split_by_sz(t->rc, k - lsz - 1, a->rc, b), a->pull();
    else b = t, split_by_sz(t->lc, k, a, b->lc), b->pull();
}

void split_by_val(treap *t, long long k, treap *&a, treap *&b) {
    if (!t) return a = b = nullptr, void();
    t->push();
    if (t->val <= k) a = t, split_by_val(t->rc, k, a->rc, b), a->pull();
    else b = t, split_by_val(t->lc, k, a, b->lc), b->pull();
}

long long solve(int r) {
    int p = 0;
    treap *tr = nullptr;
    long long res = inf;
    vector<int> cand;
    for (int i = 0; i < n; ++i) {
        int k = t[i];
        while (((k % 5) + 5) % 5 != r) ++k;
        cand.push_back(k);
    }
    sort(cand.begin(), cand.end()); cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
    for (int i = 0; i < cand.size(); ++i) {
        int z = cand[i];
        long long gap = (i > 0 ? (cand[i] - cand[i - 1]) / 5 : 0);
        if (tr) tr->sum += tr->sz * 1ll * min(gap * b, 5 * gap * c), tr->tag += min(gap * b, 5 * gap * c), tr->val += min(gap * b, 5 * gap *  c);
        while (p < n && t[p] <= z) {
            long long d = min((z - t[p]) * 1ll * c, (z - t[p]) / 5 * 1ll * b + (z - t[p]) % 5 * 1ll * c);
            treap *a, *b;
            split_by_val(tr, d - 1, a, b);
            tr = merge(merge(a, new treap(d)), b);
            ++p;
        }
        if (!tr || tr->sz < k) continue;
        treap *a, *b;
        split_by_sz(tr, k, a, b);
        res = min(res, a->sum);
        tr = merge(a, b);
    }
    return res;
}

int main() {
    srand(time(nullptr));
    scanf("%d %d %d %d", &n, &k, &b, &c);
    for (int i = 0; i < n; ++i) scanf("%d", t + i);
    sort(t, t + n);
    long long ans = inf;
    for (int i = 0; i < 5; ++i) ans = min(ans, solve(i));
    printf("%lld\n", ans);
    return 0;
}