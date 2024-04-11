#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n), out(n);
    vector<pair<int,int>> es(m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        es[i] = make_pair(u, v);
        in[v] += 1;
        out[u] += 1;
    }
    vector<int> deg(n);
    for(auto [u, v] : es) {
        if(out[u] == 1 || in[v] == 1) continue;
        g[u].push_back(v);
        deg[v] += 1;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i) if(!deg[i]) q.push(i);
    vector<int> dp(n, 1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(--deg[v] == 0) {
                q.push(v);
                dp[v] = max(dp[v], dp[u] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}