#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int tin[maxn], tout[maxn], t;

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
    int sum, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        tag = 0; sum = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void modify(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            tag ^= 1;
            sum = (R - L + 1) - sum;
            return;
        }
        lc->modify(L, M, l, r); rc->modify(M + 1, R, l, r);
        pull();
    }
    void push(int L, int R) {
        if (L == R || tag == 0) return;
        lc->sum = (M - L + 1) - lc->sum; lc->tag ^= 1;
        rc->sum = (R - M) - rc->sum; rc->tag ^= 1;
        tag = 0;
    }
    int query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].push_back(i); G[i].push_back(p);
    }
    dfs(1, 0);
    st = new SegmentTree(1, n);
    for (int i = 1; i <= n; ++i) {
        int t; cin >> t;
        if (t) st->modify(1, n, tin[i], tin[i]);
    }
    int q; cin >> q; while (q--) {
        string c; int u; cin >> c >> u;
        if (c[0] == 'p') st->modify(1, n, tin[u], tout[u]);
        else cout << st->query(1, n, tin[u], tout[u]) << endl;
    }
    return 0;
}