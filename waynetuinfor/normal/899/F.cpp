#include <bits/stdc++.h>
using namespace std;

inline int get(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
}

inline char rev(int c) {
    if (c < 26) return (char)(c + 'a');
    if (c < 52) return (char)(c - 26 + 'A');
    return (char)(c - 52 + '0');
}

struct treap {
    treap *lc, *rc;
    int pri, sz, val;
    long long s;
    treap(int k) {
        val = k;
        s = (1ll << k);
        pri = rand();
        sz = 1;
        lc = rc = nullptr;
    }
    void pull() {
        s = (lc ? lc->s : 0) | (rc ? rc->s : 0) | (1ll << val); 
        sz = (lc ? lc->sz : 0) + (rc ? rc->sz : 0) + 1;
    }
};

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
    if (!t) return a = b = nullptr, void();
    int lsz = t->lc ? t->lc->sz : 0;
    if (lsz + 1 <= k) {
        a = t;
        split(t->rc, k - lsz - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(b->lc, k, a, b->lc);
        b->pull();
    }
}

treap * del(treap *t, int ck) {
    if (!t) return nullptr;
    treap *retl = t->lc, *retr = t->rc;
    if (t->lc && t->lc->s & (1ll << ck)) retl = del(t->lc, ck);
    if (t->rc && t->rc->s & (1ll << ck)) retr = del(t->rc, ck);
    if (t->val == ck) return merge(retl, retr);
    t->lc = retl, t->rc = retr;
    t->pull();
    return t;
}

void dfs(treap *t) {
    if (!t) return;
    if (t->lc) dfs(t->lc);
    cout << rev(t->val);
    if (t->rc) dfs(t->rc);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    treap *t = nullptr;
    for (int i = 0; i < n; ++i) t = merge(t, new treap(get(s[i])));
    while (m--) {
        int l, r; char ch; cin >> l >> r >> ch;
        treap *a, *b, *c, *d;
        split(t, l - 1, a, b);
        split(b, r - l + 1, c, d);
        c = del(c, get(ch));
        t = merge(a, merge(c, d));
    }
    dfs(t);
    cout << endl;
}