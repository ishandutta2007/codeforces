#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    vector<int> sg(n), vis(n), par(n);
    vis[0] = 1;
    function<void(int,int)> dfs = [&](int u, int fa) {
        par[u] = fa;
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            sg[u] ^= sg[v] + 1;
        }
    };
    dfs(0, -1);
    int x = sg[0];
    cout << (x ? "1" : "2");
    for(int i = 1; i < n; ++i) {
        int p = i;
        while(!vis[p]) {
            vis[p] = 1;
             x ^= 1 ^ sg[p] ^ (sg[p] + 1);
            p = par[p];
        }
        cout << (x ? "1" : "2");
    }
}