#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> rev;
vector<bool> used;
vector<int> order, component;
vector<int> ans;
vector<bool> reach;

vector<int> roots;
vector<vector<int>> adj_scc;

void add(int &x, int y) {
    if(y == -1 || x == -1) {
        x = -1;
        return;
    }
    x += y;
    x = min(x, 2);
}

void dfs1(int v) {

    used[v] = true;
    for(int next : adj[v]) {
        if(!used[next])
            dfs1(next);
    }
    order.push_back(v);
}
void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for(int next : rev[v]) {
        if(next == v)
            component.push_back(next);
        if(!used[next])
            dfs2(next);
    }
}

void dfs3(int v) {
    reach[v] = true;
    for(int next : adj[v])
        if(!reach[next])
            dfs3(next);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        adj.clear(), adj.resize(n);
        rev.clear(), rev.resize(n);
        roots.clear(), roots.resize(n);
        adj_scc.clear(), adj_scc.resize(n);
        ans.clear(), ans.resize(n);
        reach.clear(), reach.resize(n, false);
        ans[0] = 1;
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            rev[b].push_back(a);
            if(a == b) ans[a] = -1;
        }

        dfs3(0);
        rev.clear(), rev.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j : adj[i]) {
                if(reach[i] && reach[j])
                    rev[j].push_back(i);
            }
        }
        adj.clear(), adj.resize(n);
        for(int i = 0; i < n; i++)
            for (int j : rev[i])
                adj[j].push_back(i);
        used.clear();
        used.assign(n, false);
        order.clear(), component.clear();
        for(int i = 0; i < n; i++)
            if(!used[i])
                dfs1(i);
        used.assign(n, false);
        reverse(order.begin(), order.end());
        for(int next : order) {
            if(!used[next]) {
                dfs2(next);

                int root = component.front();
                bool neg = false;
                for(int u : component) roots[u] = root, neg |= (ans[u] == -1);
                

                if(component.size() > 1 || neg) {
                    ans[root] = -1;
                }
                component.clear();
            }
        }

        vector<int> in(n);
        for(int v = 0; v < n; v++) {
            for(int u : adj[v]) {
                int root_v = roots[v], root_u = roots[u];
                if(root_u != root_v)
                    adj_scc[root_v].push_back(root_u), ++in[root_u];
            }
        }

        queue<int> q;
        vector<bool> seen(n);
        q.push(roots[0]);
        seen[roots[0]] = true;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(int next : adj_scc[curr]) {
                add(ans[next], ans[curr]);
                --in[next];
                if(in[next] == 0)
                    seen[next] = true, q.push(next);
            }
        }
        for(int i = 0; i < n; i++) {
            ans[i] = ans[roots[i]];
            if(!reach[i]) cout << 0 << " ";
            else cout << ans[i] << " ";
        }
        cout << "\n";
    }
}