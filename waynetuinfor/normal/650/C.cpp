#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> G[maxn], R[maxn], topo;
vector<vector<int>> a;
bool v[maxn];
int sccid[maxn], t, val[maxn];

void add_edge(int a, int b) {
    G[a].push_back(b);
    R[b].push_back(a);
}

void rdfs(int now) {
    v[now] = true;
    for (int u : R[now]) if (!v[u]) rdfs(u);
    topo.push_back(now);
}

void dfs(int now) {
    sccid[now] = t;
    for (int u : G[now]) if (!sccid[u]) dfs(u);
}

void dp(int now) {
    if (val[now]) return;
    val[now] = 0;
    for (int u : R[now]) {
        if (u == now) continue;
        dp(u);
        val[now] = max(val[now], val[u]);
    }
    ++val[now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    a.resize(n + 10);
    for (int i = 0; i < n + 10; ++i) a[i].resize(m + 10);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> vec;
        for (int j = 0; j < m; ++j) vec.push_back(make_pair(a[i][j], j));
        sort(vec.begin(), vec.end());
        for (int j = 0; j < m - 1; ++j) {
            add_edge(i * m + vec[j].second, i * m + vec[j + 1].second);
            if (vec[j].first == vec[j + 1].first) add_edge(i * m + vec[j + 1].second, i * m + vec[j].second);
        }
    }
    for (int j = 0; j < m; ++j) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i) vec.push_back(make_pair(a[i][j], i));
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n - 1; ++i) {
            add_edge(vec[i].second * m + j, vec[i + 1].second * m + j);
            if (vec[i].first == vec[i + 1].first) add_edge(vec[i + 1].second * m + j, vec[i].second * m + j);
        }
    }
    for (int i = 0; i < n * m; ++i) if (!v[i]) rdfs(i);
    reverse(topo.begin(), topo.end());
    for (int i : topo) if (!sccid[i]) ++t, dfs(i);
    for (int i = 0; i < maxn; ++i) R[i].clear();
    for (int i = 0; i < n * m; ++i) {
        for (int j : G[i]) R[sccid[j]].push_back(sccid[i]);
    }
    for (int i = 1; i <= t; ++i) dp(i);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << val[sccid[i * m + j]] << ' ';
        cout << endl;
    }
    return 0;
}