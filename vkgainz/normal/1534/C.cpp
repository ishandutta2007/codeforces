#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            --b[i];
            adj[a[i]].push_back(b[i]);
        }
        long long ans = 1LL;
        long long MOD = 1e9 + 7;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()) {
                auto curr = q.front();
                q.pop();
                for(int next : adj[curr]) {
                    if(!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
            ans *= 2;
            ans %= MOD;
        }
        if(ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}