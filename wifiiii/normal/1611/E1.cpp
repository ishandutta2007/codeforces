#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        vector<vector<int>> g(n);
        for(int i = 0; i < k; ++i) cin >> a[i], --a[i];
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        vector<int> dis(n), vis(n);
        for(int i : a) q.push(i), vis[i] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(vis[v]) continue;
                vis[v] = 1, dis[v] = dis[u] + 1, q.push(v);
            }
        }
        q.push(0); vis[0] = 1;
        vector<int> dep(n);
        fill(vis.begin(), vis.end(), 0);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(vis[v]) continue;
                vis[v] = 1, dep[v] = dep[u] + 1, q.push(v);
            }
        }
        int ok = 0;
        for(int i = 1; i < n; ++i) {
            if(g[i].size() == 1 && dep[i] < dis[i]) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}