#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

struct query {
    int k;
    vector<pair<int, int>> vec;
};

struct Dsu {
    int p[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) p[i] = i;
    }
    int find(int now) {
        if (now == p[now]) return now;
        return p[now] = find(p[now]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        p[x] = y;
    }
} dsu;

vector<int> G[maxn];
bool root[maxn];
int cur, tin[maxn], tout[maxn], forest[maxn], size[maxn], t;

void dfs(int now, int fa) {
    forest[now] = cur;
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
    }
    tout[now] = t;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    int val, tag;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = tag = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        val = lc->val + rc->val;
    }
    void push(int L, int R) {
        if (L == R || tag == 0) return;
        lc->val = add(lc->val, mul(M - L + 1, tag)); lc->tag = add(lc->tag, tag);
        rc->val = add(rc->val, mul(R - M, tag)); rc->tag = add(rc->tag, tag);
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val = add(val, mul(R - L + 1,  v)); tag = add(tag, v);
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return val;
        return add(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<query> q(n + 1);
    dsu.init();
    memset(root, true, sizeof(root));
    for (int i = 1; i <= n; ++i) {
        cin >> q[i].k; q[i].vec.assign(q[i].k, pair<int, int>());
        for (int j = 0; j < q[i].k; ++j) {
            cin >> q[i].vec[j].first >> q[i].vec[j].second;
            if (q[i].vec[j].second < 0) q[i].vec[j].second += mod;
            int now = dsu.find(q[i].vec[j].first);
            G[i].emplace_back(now); G[now].emplace_back(i);
            root[now] = false;
            dsu.merge(now, i);
        }
    }
    for (int i = 1; i <= n; ++i) if (root[i]) {
        t = 0; ++cur; dfs(i, 0);
        st[cur] = new SegmentTree(1, t);
        size[cur] = t;
    }
    dsu.init();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < q[i].k; ++j) {
            int now = q[i].vec[j].first, rt = dsu.find(now);
            int dep = st[forest[now]]->query(1, size[forest[now]], tin[now], tin[now]);
            st[forest[i]]->modify(1, size[forest[i]], tin[rt], tout[rt], add(dep, q[i].vec[j].second));
            ans = add(ans, add(dep, q[i].vec[j].second));
            dsu.merge(rt, i);
        }
    }
    cout << ans << endl;
    return 0;
}