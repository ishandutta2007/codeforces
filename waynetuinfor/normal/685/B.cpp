#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, inf = 1e9 + 1;
vector<int> G[maxn];
int tin[maxn], tout[maxn], t, sz[maxn], id[maxn];

void dfs(int now, int fa) {
    tin[now] = ++t;
    sz[now] = 1;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        sz[now] += sz[u];
    }
    tout[now] = t;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    set<pair<int, int>> s;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        s.clear();
        if (L == R) {
            s.insert(make_pair(sz[id[L]], id[L]));
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        s.clear();
        for (auto i : lc->s) s.insert(i);
        for (auto i : rc->s) s.insert(i);
    }
    pair<int, int> query(int L, int R, int l, int r, int n) {
        if (L > r || l > R) return make_pair(inf, 0);
        if (L >= l && R <= r) {
            auto it = s.lower_bound(make_pair(n, -1));
            if (it != s.end()) return *it;
            return make_pair(inf, 0);
        }
        return min(lc->query(L, M, l, r, n), rc->query(M + 1, R, l, r, n));
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[i].emplace_back(p); G[p].emplace_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) id[tin[i]] = i;
    st = new SegmentTree(1, t);
    while (q--) {
        int v; cin >> v;
        auto res = st->query(1, t, tin[v], tout[v], (sz[v] & 1 ? sz[v] / 2 + 1 : sz[v] / 2));
        cout << res.second << endl;
    }
    return 0;
}