#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> color(n);
        vector<vector<int>> c(2);
        function<void(int,int)> dfs = [&](int u, int fa) {
            c[color[u]].push_back(u);
            for(int v : g[u]) {
                if(v == fa) continue;
                color[v] = color[u] ^ 1;
                dfs(v, u);
            }
        };
        dfs(0, -1);
        if(c[0].size() > c[1].size()) swap(c[0], c[1]);
        int sz = c[0].size();
        int lg = 32 - __builtin_clz(n);
        priority_queue<pair<int,int>> q;
        vector<vector<int>> a(lg);
        for(int i = 1; i <= n; ++i) {
            int highbit = 31 - __builtin_clz(i);
            a[highbit].push_back(i);
        }
        vector<int> ans(n), vis(n + 1);
        for(int i = lg - 2; i >= 0; --i) {
            if(sz >= a[i].size()) {
                sz -= a[i].size();
                for(int j : a[i]) {
                    ans[c[0].back()] = j;
                    vis[j] = 1;
                    c[0].pop_back();
                }
            }
        }
        assert(sz == 0);
        int cur = 1;
        for(int i = 0; i < n; ++i) {
            if(ans[i]) continue;
            while(cur <= n && vis[cur]) ++cur;
            ans[i] = cur;
            vis[cur] = 1;
        }
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}