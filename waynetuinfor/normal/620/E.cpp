#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
int c[maxn], tin[maxn], tout[maxn], t, co[maxn << 1];
vector<int> G[maxn];

void dfs(int now, int fa) {
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
    }
    tout[now] = t;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    long long val, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = 0; tag = -1;
        if (L == R) {
            val = (1LL << co[L]);
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        val = lc->val | rc->val;
    }
    void modify(int L, int R, int l, int r, int c) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val = (1LL << c);
            tag = c;
            return;
        }
        lc->modify(L, M, l, r, c); rc->modify(M + 1, R, l, r, c);
        pull();
    }
    void push() {
        if (!lc || tag == -1) return;
        lc->val = (1LL << tag); lc->tag = tag;
        rc->val = (1LL << tag); rc->tag = tag;
        tag = -1;
    }
    long long query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return val;
        return lc->query(L, M, l, r) | rc->query(M + 1, R, l, r);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) co[tin[i]] = c[i];
    st = new SegmentTree(1, t);
    while (m--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int u, c; cin >> u >> c;
            st->modify(1, t, tin[u], tout[u], c);
        } else {
            int u; cin >> u;
            long long ans = st->query(1, t, tin[u], tout[u]);
            int cnt = 0;
            for (int i = 1; i <= 60; ++i) if (ans & (1LL << i)) ++cnt;
            cout << cnt << endl;
        }
    }
    return 0;
}