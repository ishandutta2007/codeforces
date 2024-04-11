#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<pair<int, int>> G[maxn];
int d[maxn];
vector<int> ans;
bool v[maxn];

int dfs(int now, int from) {
    v[now] = true;
    for (auto u : G[now]) if (!v[u.first]) {
        int del = dfs(u.first, u.second);
        if (del == 1) d[now] ^= 1;
    } 
    if (d[now] == 1) {
        assert(~from);
        ans.push_back(from);
        d[now] = 0;
        return 1;
    }
    return 0;
}

vector<int> deg[3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        if (d[i] == -1) d[i] = 2;
        deg[d[i]].push_back(i);
    }
    if (deg[2].size() == 0 && deg[1].size() & 1) return cout << "-1" << endl, 0;
    if (deg[2].size()) d[deg[2][0]] = (deg[1].size() & 1);
    for (int i = 1; i < deg[2].size(); ++i) d[deg[2][i]] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b, i); G[b].emplace_back(a, i);
    }
    dfs(1, -1);
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << endl;
    return 0;
}