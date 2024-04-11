#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int deg[maxn], ec[maxn], eid[maxn], vc[maxn], dep[maxn], nch, sz[maxn];
vector<pair<int, int>> G[maxn];

void dfs(int now, int fa, int d) {
    dep[now] = d; 
    vc[now] = nch;
    ++sz[nch];
    for (auto u : G[now]) if (u.first != fa) {
        eid[u.second] = d + 1;
        ec[u.second] = nch;
        dfs(u.first, now, d + 1);
    }
}

struct fenwick {
    vector<int> arr;
    int n;
    void init(int _n) {
        n = _n;
        arr.assign(n, 0);
    }
    inline int lowbit(int now) {
        return now & -now;
    }
    void add(int now, int v) {
        for (int i = now; i < n; i += lowbit(i)) arr[i] += v;
    }
    int qry(int now) {
        int ret = 0;
        for (int i = now; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        ++deg[a]; ++deg[b];
        G[a].emplace_back(b, i); G[b].emplace_back(a, i);
    }
    int root = 1;
    for (int i = 1; i <= n; ++i) if (deg[i] > 2) root = i;
    if (root == 1 && deg[1] == 1) {
        root = 0;
        G[0].emplace_back(1, 0);
    }
    for (auto i : G[root]) {
        ++nch;
        eid[i.second] = 1; ec[i.second] = nch;
        dfs(i.first, root, 1);
    }
    for (int i = 1; i <= nch; ++i) bit[i].init(sz[i] + 1);
    int m; cin >> m; while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int e; cin >> e;
            bit[ec[e]].add(eid[e], -1);
        }
        if (t == 2) {
            int e; cin >> e;
            bit[ec[e]].add(eid[e], 1);
        }
        if (t == 3) {
            int a, b, len, dis; cin >> a >> b;
            if (vc[a] != vc[b]) len = bit[vc[a]].qry(dep[a]) + bit[vc[b]].qry(dep[b]), dis = dep[a] + dep[b];
            else len = bit[vc[a]].qry(max(dep[a], dep[b])) - bit[vc[b]].qry(min(dep[a], dep[b])), dis = abs(dep[a] - dep[b]);
            if (len == 0) cout << dis << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}