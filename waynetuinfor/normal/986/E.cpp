#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, maxc = 1e7 + 5;
const int mod = 1e9 + 7;
vector<int> g[maxn];
int dv[maxc], dep[maxn];
int sz[maxn], to[maxn], fa[maxn];
int tin[maxn], fr[maxn], t;
int ans[maxn], buf[maxn], n;

void sieve() {
    vector<int> pr;
    for (int i = 2; i < maxc; ++i) {
        if (dv[i] == 0) dv[i] = i, pr.push_back(i);
        for (int j = 0; i * pr[j] < maxc; ++j) {
            dv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

void dfs1(int x, int p) {
    dep[x] = p == -1 ? 0 : dep[p] + 1;
    sz[x] = 1, to[x] = -1;
    fa[x] = p;
    for (int u : g[x]) if (u != p) {
        dfs1(u, x);
        sz[x] += sz[u];
        if (to[x] == -1 || sz[u] > sz[to[x]]) to[x] = u;
    }
}

void dfs2(int x, int f) {
    fr[x] = f;
    tin[x] = t++;
    if (to[x] == -1) return;
    dfs2(to[x], f);
    for (int u : g[x]) if (u != fa[x]) {
        if (u == to[x]) continue;
        dfs2(u, u);
    }
}

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return r;
}

vector<pair<int, int>> fc[maxc];
vector<tuple<int, int, int, int>> qr[maxc];

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

namespace segtree {
    pair<int, int> st[maxn * 4];
    void modify(int l, int r, int p, pair<int, int> v, int o = 0) {
        if (r - l == 1) return st[o] = st[o] + v, void();
        if (p < (l + r) / 2) modify(l, (l + r) / 2, p, v, o * 2 + 1);
        else modify((l + r) / 2, r, p, v, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    }
    pair<int, int> query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= qr || ql >= r) return make_pair(0, 0);
        if (l >= ql && r <= qr) return st[o];
        return query(l, (l + r) / 2, ql, qr, o * 2 + 1) + query((l + r) / 2, r, ql, qr, o * 2 + 2);
    }
}

pair<int, int> query(int u, int v) {
    int tu = fr[u], tv = fr[v];
    pair<int, int> res = make_pair(0, 0);
    while (tu != tv) {
        if (dep[tu] < dep[tv]) swap(tu, tv), swap(u, v);
        res = res + segtree::query(0, n, tin[tu], tin[u] + 1);
        u = fa[tu], tu = fr[u];
    }
    if (tin[u] > tin[v]) swap(u, v);
    res = res + segtree::query(0, n, tin[u], tin[v] + 1);
    return res;
}

int lca(int u, int v) {
    int tu = fr[u], tv = fr[v];
    while (tu != tv) {
        if (dep[tu] < dep[tv]) swap(tu, tv), swap(u, v);
        u = fa[tu], tu = fr[u];
    }
    return dep[u] < dep[v] ? u : v;
}
 
int main() {
    sieve();
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d %d", &u, &v); --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(0, -1), dfs2(0, 0);
    assert(t == n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        while (x > 1) {
            int d = dv[x], p = 0;
            for (; x % d == 0; x /= d, ++p);
            fc[d].emplace_back(p, i);
        }
    }
    int q; scanf("%d", &q);
    fill(ans, ans + q, 1);
    for (int i = 0; i < q; ++i) {
        int u, v, x; scanf("%d %d %d", &u, &v, &x); --u, --v;
        while (x > 1) {
            int d = dv[x], p = 0;
            for (; x % d == 0; x /= d, ++p);
            qr[d].emplace_back(p, u, v, i);
        }        
    }
    for (int i = 0; i < maxc; ++i) {
        if (qr[i].empty() || fc[i].empty()) continue;
        sort(qr[i].begin(), qr[i].end());
        sort(fc[i].begin(), fc[i].end());
        int z = 0;
        for (int j = 0; j < qr[i].size(); ++j) {
            int p, u, v, qc; tie(p, u, v, qc) = qr[i][j];
            while (z < fc[i].size() && fc[i][z].first <= p) {
                segtree::modify(0, n, tin[fc[i][z].second], make_pair(fc[i][z].first, 1));
                ++z;
            }
            int ps, c; tie(ps, c) = query(u, v);
            buf[qc] = c;
            ans[qc] = ans[qc] * 1ll * fpow(i, ps) % mod;
        }
        while (z < fc[i].size()) {
            segtree::modify(0, n, tin[fc[i][z].second], make_pair(fc[i][z].first, 1));
            ++z;
        }
        for (int j = 0; j < qr[i].size(); ++j) {
            int p, u, v, qc; tie(p, u, v, qc) = qr[i][j];
            int ps, c; tie(ps, c) = query(u, v);
            int e = c - buf[qc];
            ans[qc] = ans[qc] * 1ll * fpow(i, p * e) % mod;
        }
        z = 0;
        while (z < fc[i].size()) {
            segtree::modify(0, n, tin[fc[i][z].second], make_pair(-fc[i][z].first, -1));
            ++z;
        }
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}