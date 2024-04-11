#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    set<int> s;
    for(int i = 0; i < n; ++i) s.insert(i);
    vector<int> vis(n);
    queue<int> q;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        ++cnt;
        q.push(i); s.erase(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = 1;
            auto it = s.begin();
            while(it != s.end()) {
                int v = *it;
                if(!g[u].count(v)) {
                    q.push(v); it = s.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    cout << cnt - 1 << '\n';
}