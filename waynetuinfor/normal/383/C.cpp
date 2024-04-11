#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int a[maxn], tin[maxn], tout[maxn], dep[maxn], t, v[maxn << 1], d[maxn << 1], id[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    long long val;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = 0;
        if (L == R) {
            if (d[L] % 2 == 0) val = v[L];
            else val = -v[L];
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void push() {
        if (!lc || val == 0) return;
        lc->val += val; rc->val += val;
        val = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
    }
    long long query(int L, int R, int x) {
        push();
        if (L == R) return val;
        if (x <= M) return lc->query(L, M, x);
        else return rc->query(M + 1, R, x);
    }
#undef M
} *st;

void dfs(int now, int fa, int d) {
    dep[now] = d; tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
    }
    tout[now] = t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) id[tin[i]] = i;
    for (int i = 1; i <= t; ++i) d[i] = dep[id[i]], v[i] = a[id[i]];
    st = new SegmentTree(1, t);
    while (m--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int x, val; cin >> x >> val;
            if (dep[x] & 1) st->modify(1, t, tin[x], tout[x], -val);
            else st->modify(1, t, tin[x], tout[x], val);
        } else {
            int x; cin >> x;
            long long ans = st->query(1, t, tin[x]);
            if (dep[x] & 1) cout << -ans << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}