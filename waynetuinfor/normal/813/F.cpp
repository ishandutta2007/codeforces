#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct djset {
    int p[maxn], sz[maxn], ok;
    stack<pair<int*, int>> his;
    stack<int> hz;
    void init() { ok = 1; for (int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1; }
    int find(int u) { return u == p[u] ? u : find(p[u]); }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        if (u / 2 == v / 2) assign(&ok, 0);
        assign(&p[v], u);
        assign(&sz[u], sz[u] + sz[v]);
    }
    void add_edge(int u, int v) {
        if (find(u << 1) == find(v << 1) || find(u << 1 | 1) == find(v << 1 | 1)) assign(&ok, 0);
        merge(u << 1, v << 1 | 1);
        merge(u << 1 | 1, v << 1);
    }
    void assign(int *k, int v) {
        his.push(make_pair(k, *k));
        *k = v;
    }
    void save() { hz.push(his.size()); }
    void undo() {
        int last = hz.top(); hz.pop();
        while (last != his.size()) {
            int *k, v; tie(k, v) = his.top(); his.pop();
            *k = v;
        }
    }
} djs;

map<pair<int, int>, int> ed;
int ans[maxn];

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    vector<pair<int, int>> vec;
    segtree(int l, int r) {
        lc = rc = nullptr; vec.clear();
        if (l == r) return;
        lc = new segtree(l, m); rc = new segtree(m + 1, r);
    }
    void modify(int l, int r, int ql, int qr, pair<int, int> v) {
        // cout << "ql = " << ql << " qr = " << qr << " (" << v.first << ", " << v.second << ")" << endl;
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) return vec.push_back(v), void();
        lc->modify(l, m, ql, qr, v); rc->modify(m + 1, r, ql, qr, v);
    }
    void solve(int l, int r) {
        djs.save();
        for (auto v : vec) djs.add_edge(v.first, v.second);
        if (l == r) ans[l] = djs.ok;
        else lc->solve(l, m), rc->solve(m + 1, r);
        djs.undo();
    }
#undef m
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    st = new segtree(0, q - 1);
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        if (ed.find(make_pair(a, b)) == ed.end()) ed[make_pair(a, b)] = i;
        else st->modify(0, q - 1, ed[make_pair(a, b)], i - 1, make_pair(a, b)), ed.erase(make_pair(a, b));
    }
    for (auto it = ed.begin(); it != ed.end(); ++it) {
        st->modify(0, q - 1, it->second, q - 1, it->first);
    }
    djs.init();
    st->solve(0, q - 1);
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "YES" : "NO") << endl;
    return 0;
}