#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
vector<int> G[maxn];
int tin[maxn], tout[maxn], t, sz[maxn], maxson[maxn], top[maxn], p[maxn], dep[maxn];

void dfs1(int now, int fa, int d) {
    dep[now] = d; p[now] = fa;
    sz[now] = 1; maxson[now] = -1;
    for (int u : G[now]) if (u != fa) {
        dfs1(u, now, d + 1);
        if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) {
            maxson[now] = u;
        }
        sz[now] += sz[u];
    }
}

void dfs2(int now, int fa, int tp) {
    tin[now] = ++t; top[now] = tp;
    if (~maxson[now]) dfs2(maxson[now], now, tp);
    for (int u : G[now]) if (u != fa) {
        if (u != maxson[now]) dfs2(u, now, u);
    }
    tout[now] = t;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int sum, tag;
    SegmentTree(int L, int R) {
        sum = 0; tag = -1;
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push(int L, int R) {
        if (!lc || tag == -1) return;
        lc->tag = tag; lc->sum = (M - L + 1) * tag;
        rc->tag = tag; rc->sum = (R - M) * tag;
        tag = -1;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            tag = v; sum = (R - L + 1) * v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
    }
    int query(int L, int R, int x) {
        push(L, R);
        if (L == R) return sum;
        if (x <= M) return lc->query(L, M, x); 
        else return rc->query(M + 1, R, x);
    }
#undef M
} *st;

void solve(int a) {
    int b = 1;
    int ta = top[a], tb = top[b];
    while (ta != tb) {
        if (dep[tb] > dep[ta]) {
            swap(a, b); swap(ta, tb);
        }
        st->modify(1, t, tin[ta], tin[a], 0);
        a = p[ta]; ta = top[a];
    }
    st->modify(1, t, min(tin[a], tin[b]), max(tin[a], tin[b]), 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    dfs1(1, 0, 0); dfs2(1, 0, 1); st = new SegmentTree(1, t);
    int q; cin >> q; while (q--) {
        int c, v; cin >> c >> v;
        if (c == 1) st->modify(1, t, tin[v], tout[v], 1);
        if (c == 2) solve(v);
        if (c == 3) cout << st->query(1, t, tin[v]) << endl;
    }
    return 0;
}