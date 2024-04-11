#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    set<int> s;
    for(int i = 0; i < n; ++i) s.insert(i);
    vector<int> vis(n);
    queue<int> q;
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        q.push(i); s.erase(i);
        vector<int> b;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = 1;
            b.push_back(u);
            int j = 0;
            auto it = s.begin();
            while(it != s.end()) {
                int v = *it;
                while(j < g[u].size() && g[u][j] < v) ++j;
                if(j == g[u].size() || g[u][j] != v) {
                    q.push(v); it = s.erase(it);
                } else {
                    ++it;
                }
            }
        }
        ans.push_back(b);
    }
    cout << ans.size() << '\n';
    for(auto b : ans) {
        cout << b.size() << ' ';
        for(int i : b) cout << i + 1 << ' ';
        cout << '\n';
    }
}