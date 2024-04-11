#include <bits/stdc++.h>
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
    vector<int> dep(n);
    function<void(int,int)> dfs = [&](int u, int fa) {
        for(int v : g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    int p = max_element(dep.begin(), dep.end()) - dep.begin();
    dep[p] = 0;
    dfs(p, -1);
    int q = max_element(dep.begin(), dep.end()) - dep.begin();
    int d = dep[q];
    // p and q
    vector<int> path;
    function<int(int,int,int)> find = [&](int u, int fa, int target) {
        if(u == target) {
            path.push_back(u);
            return 1;
        }
        for(int v : g[u]) {
            if(v == fa) continue;
            if(find(v, u, target)) {
                path.push_back(u);
                return 1;
            }
        }
        return 0;
    };
    find(p, -1, q);
    vector<int> vis(n);
    queue<int> que;
    for(int i : path) vis[i] = 1, dep[i] = 0, que.push(i);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(int v : g[cur]) {
            if(vis[v]) continue;
            vis[v] = 1;
            dep[v] = dep[cur] + 1;
            que.push(v);
        }
    }
    int mx = 0;
    for(int i = 0; i < n; ++i) {
        if(i == p || i == q) continue;
        if(dep[i] >= dep[mx]) mx = i;
    }
    cout << dep[mx] + d << endl;
    cout << p + 1 << " " << q + 1 << " " << mx + 1 << endl;
}