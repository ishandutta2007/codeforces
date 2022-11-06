#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const int inf = 1000000000 + 1;
const long long linf = 2e18;

namespace lichao {
    struct line {
        int a, b;
        line(int a = 0, int b = 0) : a(a), b(b) {}
        long long operator()(int x) const {
            if (a == -inf && b == -inf) return -linf;
            return a * 1ll * x + b;
        }
    };

    const int maxc = 5e6;
    int lc[maxc], rc[maxc], sz;
    line st[maxc];

    void init() { sz = 0; }

    int gnode() {
        lc[sz] = rc[sz] = -1;
        st[sz] = line(-inf, -inf);
        return sz++;
    }

    void modify(int l, int r, line tl, int o) {
        // printf("l = %d r = %d\n", l, r);
        int m = (l + r) / 2;
        bool lcp = st[o](l) < tl(l);
        bool mcp = st[o](m) < tl(m);
        if (mcp) swap(st[o], tl);
        if (r - l == 1) return;
        if (lcp != mcp) {
            if (lc[o] == -1) lc[o] = gnode();
            modify(l, m, tl, lc[o]);
        } else {
            if (rc[o] == -1) rc[o] = gnode();
            modify(m, r, tl, rc[o]);
        }
    }

    long long query(int l, int r, int x, int o) {
        if (r - l == 1) return st[o](x);
        long long res = st[o](x);
        int m = (l + r) / 2;
        if (x < m && lc[o] != -1) 
            res = max(res, query(l, m, x, lc[o]));
        if (x >= m && rc[o] != -1)
            res = max(res, query(m, r, x, rc[o]));
        return res;
    }
}

vector<pair<int, int>> st[maxn * 4];

void modify(int l, int r, int ql, int qr, int a, int b, int o = 0) {
    if (l >= ql && r <= qr) {
        st[o].emplace_back(a, b);
        return;
    }

    if (l >= qr || ql >= r) return;

    modify(l, (l + r) >> 1, ql, qr, a, b, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, a, b, o * 2 + 2);
}

long long ans[maxn];

void dfs(int l, int r, const vector<pair<int, int>> &qr, int o = 0) {
    lichao::init();
    int root = lichao::gnode();
    for (int i = 0; i < (int)st[o].size(); ++i) {
        lichao::line ln(st[o][i].first, st[o][i].second);
        lichao::modify(-inf, inf, ln, root);
    }
    for (int i = 0; i < (int)qr.size(); ++i) {
        int x = qr[i].first, j = qr[i].second;
        ans[j] = max(ans[j], lichao::query(-inf, inf, x, root));
    }
    if (r - l == 1) return;

    int m = (l + r) >> 1;
    vector<pair<int, int>> lq, rq;
    for (int i = 0; i < (int)qr.size(); ++i) {
        if (qr[i].second < m) lq.push_back(qr[i]);
        else rq.push_back(qr[i]);
    }

    dfs(l, m, lq, o * 2 + 1);
    dfs(m, r, rq, o * 2 + 2);
}

int a[maxn], b[maxn], t[maxn];
bool hq[maxn];

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> query;

    int s = 0;
    memset(t, -1, sizeof(t));
    for (int i = 0; i < n; ++i) {
        int tp; scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d", &a[i], &b[i]);
            t[i] = i;
        }
        if (tp == 2) {
            int p; scanf("%d", &p); --p;
            modify(0, n, t[p], i, a[p], b[p]);
            t[p] = -1;
        }
        if (tp == 3) {
            int q; scanf("%d", &q);
            query.emplace_back(q, i);
            hq[i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (t[i] != -1)
            modify(0, n, t[i], n, a[i], b[i]);
    }

    for (int i = 0; i < n; ++i) ans[i] = -linf;
    dfs(0, n, query);

    for (int i = 0; i < n; ++i) {
        if (!hq[i]) continue;
        if (ans[i] == -linf) puts("EMPTY SET");
        else printf("%lld\n", ans[i]);
    }
    return 0;
}