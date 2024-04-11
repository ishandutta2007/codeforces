#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int c[maxn], t[maxn];
long long f[maxn], dp[maxn];
vector<pair<int, int>> g[maxn];
long long st[maxn * 4], sz[maxn * 4];

void modify(int l, int r, int p, int v, int o = 0) {
    if (r - l == 1) {
        sz[o] += v;
        st[o] += p * 1ll * v;
        return;
    }
    if (p < (l + r) >> 1) modify(l, (l + r) >> 1, p, v, o * 2 + 1);
    else modify((l + r) >> 1, r, p, v, o * 2 + 2);
    sz[o] = sz[o * 2 + 1] + sz[o * 2 + 2];
    st[o] = st[o * 2 + 1] + st[o * 2 + 2];
}

long long query(int l, int r, long long v, int o = 0) {
    if (r - l == 1) return l ? min(sz[o], v / l) : sz[o];
    if (st[o * 2 + 1] <= v) return query((l + r) >> 1, r, v - st[o * 2 + 1], o * 2 + 2) + sz[o * 2 + 1];
    else return query(l, (l + r) >> 1, v, o * 2 + 1);
}

void dfs(int x, long long s, long long z) {
    modify(0, maxn, t[x], c[x]);
    if (z - s - s >= 0) f[x] = query(0, maxn, z - s - s);
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first;
        int w = g[x][i].second;
        dfs(u, s + w, z);
    }
    modify(0, maxn, t[x], -c[x]);
}

void dfs2(int x) {
    vector<long long> v;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first;
        dfs2(u);
        v.push_back(dp[u]);
    }
    sort(v.begin(), v.end());
    if (v.size() > 1) dp[x] = v[(int)v.size() - 2];
    if (x == 0 && (int)v.size() > 0) dp[x] = max(dp[x], v.back());
    dp[x] = max(dp[x], f[x]);
}

int main() {
    int n; long long z;
    scanf("%d%lld", &n, &z);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    for (int i = 1; i < n; ++i) {
        int p, l; scanf("%d%d", &p, &l);
        --p;
        g[p].emplace_back(i, l);
    }
    dfs(0, 0, z);
    dfs2(0);
    printf("%lld\n", dp[0]);
    return 0;
}