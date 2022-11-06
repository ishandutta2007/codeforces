#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<pair<int, int>> G[maxn];
int sz[maxn], son[maxn], dep[maxn], p[maxn], id[maxn], tin[maxn], cnt, link[maxn];

void dfs(int, int, int);
void build(int, int);
void lca(int, int);

struct Seg {
    Seg *lc, *rc;
    int val, tag;
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr;
        tag = 0; val = 0;
        if (L == R) return;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    void pull() {
        val = lc->val + rc->val;
    }
    void push(int L, int R) {
        if (!lc || tag == 0) return;
        lc->val += (M - L + 1) * tag; lc->tag += tag;
        rc->val += (R - M) * tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        if (L > R) return;
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val += (R - L + 1) * v;
            tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
    }
    int query(int L, int R, int x) {
        push(L, R);
        if (L == R) return val;
        if (x <= M) return lc->query(L, M, x);
        return rc->query(M + 1, R, x);
    }
    void debug(int L, int R) {
        push(L, R);
        if (L == R) { cout << val << ' '; return; }
        lc->debug(L, M); rc->debug(M + 1, R);
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(make_pair(b, i)); G[b].push_back(make_pair(a, i));
    }
    dfs(1, 0, 0); build(1, 1);
    st = new Seg(1, cnt);
    int k; cin >> k; while (k--) {
        int a, b; cin >> a >> b;
        lca(a, b);
    }
    // for (int i = 1; i <= n; ++i) cout << tin[i] << ' '; cout << endl;
    // st->debug(1, cnt); cout << endl;
    for (int i = 0; i < n - 1; ++i) cout << st->query(1, cnt, tin[id[i]]) << ' '; cout << endl;
    return 0;
}

void dfs(int now, int fa, int d) {
    sz[now] = 1; son[now] = -1;
    p[now] = fa; dep[now] = d;
    int mx = 0;
    for (auto e : G[now]) if (e.first != fa) {
        id[e.second] = e.first;
        dfs(e.first, now, d + 1);
        sz[now] += sz[e.first];
        if (sz[e.first] > mx) mx = sz[e.first], son[now] = e.first;
    }
}

void build(int now, int top) {
    tin[now] = ++cnt; link[now] = top;
    if (son[now] == -1) return;
    build(son[now], top);
    for (auto e : G[now]) if (e.first != p[now]) {
        if (e.first == son[now]) continue;
        build(e.first, e.first);
    }
}

void lca(int a, int b) {
    int ta = link[a], tb = link[b];
    while (ta != tb) {
        if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
        st->modify(1, cnt, tin[ta], tin[a], 1);
        ta = link[a = p[ta]];
    }
    // cout << "done loop" << endl;
    if (a != b) st->modify(1, cnt, min(tin[a], tin[b]) + 1, max(tin[a], tin[b]), 1);
    // cout << "done" << endl;
}