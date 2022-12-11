#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")

using namespace std;

const int K = 20, N = 1 << K;
set <int> g[N];
vector <int> euler;
vector <int> res;
bool vis[N];
pair <int, int> dom[N];
vector <pair <int, int>> edges;

void dfs(int v, int depth = 0, int prv = 0) {
    while (!g[v].empty()) {
        int pos = (*g[v].begin());
        g[v].erase(g[v].begin());
        pair <int, int> edge = edges[pos];
        g[edge.first].erase(pos ^ 1);
        dfs(edge.first, depth + 1, edge.second);
        //if (--(*g[v].begin()).second == 0) g[v].erase(edge.first);
        //if (--g[edge.first][v] == 0) g[edge.first].erase(v);juk
    }
    //cout << v << ' ' ;
    euler.push_back(prv);
}

int dfs0(int v) {
    vis[v] = 1;
    int summ = g[v].size();
    for (auto u : g[v]) {
        if (!vis[edges[u].first]) summ += dfs0(edges[u].first);
    }
    return summ;
}

bool find_euler(int n, int k, bool rest = 0) {
    edges.clear();
    for (int i = 0; i < N; i++) g[i].clear();
    memset(vis, 0, sizeof(vis));
    int mask = 0;
    for (int i = 0; i < k; i++) mask |= (1 << i);
    for (int i = 1; i <= n; i++) {
        int a = dom[i].first & mask, b = dom[i].second & mask;
        g[a].insert(edges.size());
        edges.push_back({b, i});
        g[b].insert(edges.size());
        edges.push_back({a, -i});
        //g[a].insert({b, i});
        //g[b].insert({a, -i});
    }
    int pos = -1;
    for (int i = 0; i < N; i++) {
        if (!g[i].empty()) pos = i;
        if ((int) g[i].size() % 2 == 1) return 0;
    }
    if (dfs0(pos) != 2 * n) return 0;
    if (!rest) return 1;
    dfs(pos);
    for (int elem : euler) {
        //cout << elem << ' ';
        if (elem == 0) continue;
        if (elem < 0) {
            elem *= -1;
            res.push_back(2 * elem - 1);
            res.push_back(2 * elem);
        } else {
            res.push_back(2 * elem);
            res.push_back(2 * elem - 1);
        }
    }
    //cout << endl;
    return 1;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> dom[i].first >> dom[i].second;
    int l = 0, r = K + 1, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (find_euler(n, mid)) l = mid;
        else r = mid;
    }
    find_euler(n, l, 1);
    cout << l << endl;
    for (int elem : res) cout << elem << ' ';
    cout << endl;
    return 0;
}