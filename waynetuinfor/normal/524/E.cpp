#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 2e5 + 10;
int ans[maxn];
vector<int> xs[maxn], ys[maxn];

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

struct query {
    int l, r, d, u, id;
    query(int aa, int bb, int cc, int dd, int ee) {
        l = aa; r = bb; d = cc; u = dd; id = ee;
    }
    query() {}
};

query qry[maxn];
vector<int> xq[maxn], yq[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    static SegmentTree mem[2000000];
    static SegmentTree *ptr;
    int pos;
    SegmentTree() {}
    ~SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        pos = 0;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        pos = min(lc->pos, rc->pos);
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) {
            pos = v;
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    int ask(int L, int R, int l, int r) {
        if (L > r || l > R) return maxn;
        if (L >= l && R <= r) return pos;
        return min(lc->ask(L, M, l, r), rc->ask(M + 1, R, l, r));
    }
#undef M
} *stx, *sty;

SegmentTree SegmentTree::mem[2000000];
SegmentTree* SegmentTree::ptr = mem;

int main() {
    int n, m, k, q; rit(n, m, k, q);
    for (int i = 0; i < k; ++i) {
        int x, y; rit(x, y);
        xs[x].push_back(y); ys[y].push_back(x);
    }
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2; rit(x1, y1, x2, y2);
        qry[i] = query(x1, x2, y1, y2, i);
        xq[x2].push_back(i); yq[y2].push_back(i);
    }
    stx = new (SegmentTree::ptr++) SegmentTree(0, maxn - 1); sty = new (SegmentTree::ptr++) SegmentTree(0, maxn - 1);
    for (int i = 0; i < maxn; ++i) if (xs[i].size() || xq[i].size()) {
        for (int j : xs[i]) stx->modify(0, maxn - 1, j, i); 
        for (int j : xq[i]) {
            if (stx->ask(0, maxn - 1, qry[j].d, qry[j].u) < qry[j].l) ++ans[j];
        }
    }
    for (int i = 0; i < maxn; ++i) if (ys[i].size() || yq[i].size()) {
        for (int j : ys[i]) sty->modify(0, maxn - 1, j, i);
        for (int j : yq[i]) {
            if (sty->ask(0, maxn - 1, qry[j].l, qry[j].r) < qry[j].d) ++ans[j];
        }
    }
    for (int i = 0; i < q; ++i) {
        if (ans[i] == 2) puts("NO");
        else puts("YES");
    }
    return 0;
}