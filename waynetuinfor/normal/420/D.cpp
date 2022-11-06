#include <bits/stdc++.h>
#define getchar gtx
#define size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 1e6 + 10;
int ans[maxn], x[maxn], y[maxn];
bool v[maxn];

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

struct treap {
    treap *lc, *rc;
    int val, pri, sz;
    treap(int v): val(v) {
        pri = rand();
        sz = 1;
        lc = rc = nullptr;
    }
    void pull() {
        sz = size(lc) + size(rc) + 1;
    }
};

treap *merge(treap* a, treap* b) {
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

void split(treap* t, int k, treap*& a, treap*& b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    if (size(t->lc) + 1 <= k) {
        a = t;
        split(t->rc, k - size(t->lc) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        b->pull();
    }
}

void go(treap* t, int l, int r) {
    if (!t) return;
    go(t->lc, l, l + size(t->lc) - 1);
    go(t->rc, l + size(t->lc) + 1, r);
    ans[l + size(t->lc)] = t->val;
}

int main() {
    srand(7122);
    int n, m; rit(n, m);
    treap *t = nullptr;
    for (int i = 0; i < n; ++i) t = merge(t, new treap(-1));
    for (int i = 0; i < m; ++i) rit(x[i], y[i]);
    for (int i = m - 1; i >= 0; --i) {
        treap *a, *b, *c, *d;
        split(t, 1, a, b);
        if (a->val == -1) a->val = x[i];
        else if (a->val != -1 && a->val != x[i]) return 0 * puts("-1");
        split(b, y[i] - 1, c, d);
        t = merge(merge(c, a), d);
    }
    go(t, 1, n);
    for (int i = 1; i <= n; ++i) if (ans[i] != -1) {
        if (v[ans[i]]) return 0 * puts("-1");
        v[ans[i]] = true;
    }
    vector<int> vec;
    for (int i = 1; i <= n; ++i) if (!v[i]) vec.push_back(i);
    size_t ind = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] != -1) printf("%d ", ans[i]);
        else printf("%d ", vec[ind++]);
    }
    puts("");
    return 0;
}