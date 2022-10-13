#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
vector<int> roots, root_nodes;
vector<vector<int>> adj_scc;

int id(int i, int j) { //{col, row}
    return j * m + i;
}

void add(int x, int y) {
    adj[x].push_back(y);
    adj_rev[y].push_back(x);
}

void dfs1(int v) {
    used[v] = true;
    for(auto u : adj[v]) {
        if(!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for(auto u : adj_rev[v])
        if(!used[u])
            dfs2(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    string grid[n];
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    adj.resize(n * m);
    adj_rev.resize(n * m);
    used.assign(n * m, false);

    for(int i = 0; i < m; i++) {
        int lst = -1;
        for(int j = n - 1; j >= 0; j--) {
            if(lst != -1 && grid[j][i] == '#') {
                add(id(i, j), id(i, lst));
            }
            if(j > 0 && grid[j][i] == '#' && grid[j - 1][i] == '#')
                add(id(i, j), id(i, j - 1));
            if(i < m - 1 && grid[j][i] == '#' && grid[j][i + 1] == '#')
                add(id(i, j), id(i + 1, j));
            if(i > 0 && grid[j][i] == '#' && grid[j][i - 1] == '#')
                add(id(i, j), id(i - 1, j));
            if(grid[j][i] == '#') lst = j;
                
        }
    }
    vector<int> lst(m, -1);
    for(int j = n - 1; j >= 0; j--) {
        for(int i = 0; i < m; i++) {
            //cout << i << " " << j << "\n";
            if(i > 0 && grid[j][i] == '#' && lst[i - 1] != -1)
                add(id(i, j), id(i - 1, lst[i - 1]));
            if(i < m - 1 && grid[j][i] == '#' && lst[i + 1] != -1)
                add(id(i, j), id(i + 1, lst[i + 1]));
        }
        for(int i = 0; i < m; i++) {
		    if(grid[j][i] == '#')
                lst[i] = j;
        }
    }
    for(int i = 0; i < n * m; i++) {
        if(!used[i] && grid[i/m][i%m] == '#') {
            dfs1(i);
        }
    }
    used.assign(n * m, false);
    reverse(order.begin(), order.end());
    root_nodes.resize(n * m), roots.resize(n * m);
    adj_scc.resize(n * m);
    int ans = 0;
    for(auto v : order) {
        if(!used[v]) {
            dfs2(v);
            
            int root = component.front();
            for(auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
            //++ans;
        }
    }
    vector<int> in(n * m);
    for(int v = 0; v < n * m; v++) {
        for(auto u : adj[v]) {
            int root_v = roots[v], root_u = roots[u];
            if(root_u != root_v)
                adj_scc[root_v].push_back(root_u), ++in[root_u];
        }
    }
    for(int i =0; i < n * m; i++) {
        if(in[i] == 0 && grid[i / m][i % m] == '#' && i == roots[i])
            ++ans;
    }
    cout << ans;
}