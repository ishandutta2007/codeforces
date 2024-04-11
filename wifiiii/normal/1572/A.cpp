#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<pair<int,int>>> g(n);
        vector<int> deg(n);
        for(int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            for(int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                --x;
                if(x < i) g[x].push_back({i, 0});
                else g[x].push_back({i, 1});
            }
            deg[i] = k;
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(!deg[i]) q.push(i);
        }
        vector<int> dp(n, 0);
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop(); ++cnt;
            for(auto [v, w] : g[u]) {
                if(--deg[v] == 0) {
                    q.push(v);
                }
                dp[v] = max(dp[v], dp[u] + w);
            }
        }
        if(cnt < n) cout << -1 << '\n';
        else cout << 1 + *max_element(dp.begin(), dp.end()) << '\n';
    }
}