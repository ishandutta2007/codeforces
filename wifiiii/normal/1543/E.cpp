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
        int m = n * (1 << (n - 1));
        vector<vector<int>> g(1 << n);
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 0; i < 1 << n; ++i) {
            sort(g[i].begin(), g[i].end());
        }
        vector<int> id(1 << n, -1), vis(1 << n);
        id[0] = 0;
        for(int i = 0; i < n; ++i) {
            id[g[0][i]] = 1 << i;
        }
        vector<int> pp1(1 << n), pp2(1 << n);
        for(int i = 0; i < 1 << n; ++i) {
            pp1[i] = 31 - __builtin_clz(i);
            pp2[i] = 31 - __builtin_clz(i & -i);
        }
        function<void(int)> dfs = [&](int x) {
            vis[x] = 1;
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    int u = g[x][i], v = g[x][j];
                    int p = id[u] ^ id[v];
                    int p1 = pp1[p], p2 = pp2[p];
                    int y = 0;
                    if(id[x] == (id[u] ^ (1 << p1))) y = id[u] ^ (1 << p2);
                    else y = id[u] ^ (1 << p1);
                    for(int r : g[u]) {
                        if(r == x) continue;
                        if(binary_search(g[v].begin(), g[v].end(), r)) {
                            id[r] = y;
                        }
                    }
                }
            }
            for(int u : g[x]) {
                if(!vis[u]) dfs(u);
            }
        };
        dfs(0);
        vector<int> ans(1 << n), color(1 << n);
        for(int i = 0; i < 1 << n; ++i) {
            ans[id[i]] = i;
            int c = 0;
            for(int j = 0; j < n; ++j) {
                if(id[i] >> j & 1) {
                    c ^= j;
                }
            }
            color[i] = c;
        }
        for(int i = 0; i < 1 << n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
        if((1 << n) % n != 0) {
            cout << -1 << '\n';
        } else {
            for(int i = 0; i < 1 << n; ++i) {
                cout << color[i] << " ";
            }
            cout << '\n';
        }
    }
}