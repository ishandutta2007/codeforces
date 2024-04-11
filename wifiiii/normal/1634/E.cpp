#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    int v, x, y, rev, vis;
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n), ans(n);
    vector<int> b;
    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        ans[i].resize(m);
        for(auto &x : a[i]) cin >> x, b.push_back(x);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = b.size();
    vector<int> num(m);
    vector<vector<edge>> g(m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < a[i].size(); ++j) {
            a[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
            num[a[i][j]] += 1;
        }
        for(int j = 0; j < a[i].size(); j += 2) {
            int u = a[i][j], v = a[i][j + 1];
            g[u].push_back({v, i, j, (int)g[v].size(), 0});
            g[v].push_back({u, i, j + 1, (int)g[u].size() - 1, 0});
        }
    }
    int ok = 1;
    for(int i = 0; i < m; ++i) if(num[i] & 1) ok = 0;
    if(ok == 0) {
        cout << "NO\n";
        return 0;
    }
    function<void(int)> dfs = [&](int u) {
        while(!g[u].empty()) {
            auto [v, x, y, rev, vis] = g[u].back(); g[u].pop_back();
            if(vis) continue;
            g[v][rev].vis = 1;
            ans[x][y] = 1;
            dfs(v);
        }
    };
    for(int i = 0; i < m; ++i) dfs(i);
    cout << "YES\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < a[i].size(); ++j) {
            cout << (ans[i][j] ? 'L' : 'R');
        }
        cout << '\n';
    }
}