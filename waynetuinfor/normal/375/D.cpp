#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int c[maxn], tin[maxn], tout[maxn], t, co[maxn], ans[maxn], cnt[maxn];

void dfs(int now, int fa) {
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
    }
    tout[now] = t;
}

struct Query {
    int l, r, block, i, k;
    bool operator<(const Query& rhs) const {
        return block == rhs.block ? r < rhs.r : block < rhs.block;
    }
} qry[maxn];

struct Fenwick {
    int arr[maxn];
    inline int lowbit(int x) {
        return x & -x;
    }
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit;

void add(int x) {
    if (cnt[co[x]]) bit.add(cnt[co[x]], -1);
    ++cnt[co[x]];
    if (cnt[co[x]]) bit.add(cnt[co[x]], 1);
}

void sub(int x) {
    if (cnt[co[x]]) bit.add(cnt[co[x]], -1);
    --cnt[co[x]];
    if (cnt[co[x]]) bit.add(cnt[co[x]], 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    bit.init();
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) co[tin[i]] = c[i];
    int lim = (int)sqrt(n) + 1;
    for (int i = 0; i < m; ++i) {
        int v, k; cin >> v >> k;
        qry[i].l = tin[v]; qry[i].r = tout[v]; qry[i].k = k;
        qry[i].block = qry[i].l / lim;
        qry[i].i = i;
    }
    sort(qry, qry + m);
    for (int i = 0, L = 1, R = 0; i < m; ++i) {
        while (R < qry[i].r) add(++R);
        while (R > qry[i].r) sub(R--);
        while (L > qry[i].l) add(--L);
        while (L < qry[i].l) sub(L++);
        ans[qry[i].i] = bit.qry(n) - bit.qry(qry[i].k - 1);
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << endl;
    return 0;
}