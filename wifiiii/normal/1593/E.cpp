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
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<vector<int>> g(n);
        vector<int> deg(n);
        vector<int> dis(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(deg[i] == 1) {
                q.push(i);
            }
        }
        int res = n;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(dis[u] >= k) break;
            --res;
            for(int v : g[u]) {
                if(--deg[v] == 1) {
                    q.push(v);
                    dis[v] = dis[u] + 1;
                }
            }
        }
        cout << res << '\n';
    }
}