#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> g[maxn];
int tin[maxn], tout[maxn], tk;
int dep[maxn];
long long ans[maxn];
vector<tuple<int, int, int>> qr[maxn];
vector<int> qu[maxn];

void dfs(int x, int p) {
    tin[x] = tk++;
    dep[x] = (~p ? dep[p] + 1 : 0);
    for (const int &u : g[x]) {
        if (u == p) continue;
        dfs(u, x);
    }
    tout[x] = tk;
}

namespace segtree {
    long long st[maxn * 4], tg[maxn * 4];
    void init() {
        memset(st, 0, sizeof(st));
        memset(tg, 0, sizeof(tg));
    }
    void push(int o, int l, int r) {
        if (tg[o] == 0) return;
        st[o * 2 + 1] += 1ll * ((l + r) / 2 - l) * tg[o];
        tg[o * 2 + 1] += tg[o];
        st[o * 2 + 2] += 1ll * (r - (l + r) / 2) * tg[o];
        tg[o * 2 + 2] += tg[o];
        tg[o] = 0;
    }
    void modify(int l, int r, int ql, int qr, int v, int o = 0) {
        if (l >= qr || ql >= r) return;
        if (r - l > 1) push(o, l, r);
        if (l >= ql && r <= qr) {
            st[o] += 1ll * (r - l) * v;
            tg[o] += v;
            return;
        }
        modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
        modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    }
    long long query(int l, int r, int p, int o = 0) {
        if (r - l == 1) return st[o];
        push(o, l, r);
        if (p < (l + r) >> 1) return query(l, (l + r) >> 1, p, o * 2 + 1);
        else return query((l + r) >> 1, r, p, o * 2 + 2);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int v, d, x; scanf("%d%d%d", &v, &d, &x);
        --v;
        int lm = min(n, dep[v] + d);
        qr[lm].emplace_back(tin[v], tout[v], x);
    }
    for (int i = 0; i < n; ++i) qu[dep[i]].push_back(i);
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < (int)qr[i].size(); ++j) {
            int l, r, v; tie(l, r, v) = qr[i][j];
            segtree::modify(0, n, l, r, v);
        }
        for (int j = 0; j < (int)qu[i].size(); ++j) {
            int x = tin[qu[i][j]];
            ans[qu[i][j]] = segtree::query(0, n, x);
        }
    }
    for (int i = 0; i < n; ++i) printf("%lld ", ans[i]);
    puts("");
    return 0;
}