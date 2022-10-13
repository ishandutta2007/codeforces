#include <bits/stdc++.h>
//include ordered set...?
using namespace std;

vector<int> v, t, d;
vector<vector<int>> adj;
vector<int> col;
long long f, s, tot;
bool bipartite;

void dfs(int curr) {
    for(int next : adj[curr]) {
        if(col[next] == 0) {
            col[next] = 3 - col[curr];
            d[next] = d[curr] + 1;
            dfs(next);
        }
        else if(col[next] == col[curr]) 
            bipartite = false;
    }
    tot += t[curr] - v[curr];
    if(d[curr] % 2) f += (t[curr] - v[curr]);
    else s += (t[curr] - v[curr]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        v.clear(), v.resize(n);
        t.clear(), t.resize(n);
        d.clear(), d.resize(n);
        col.clear(), col.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> t[i];
        }
        bool work = true;
        adj.clear(), adj.resize(n);
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            --x, --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        bipartite = true;
        f = 0, s = 0, tot = 0;
        col[0] = 1;
        dfs(0);
        if(tot % 2) {
            cout << "NO" << "\n";
        }
        else {
            if(bipartite && f != s)
                cout << "NO" << "\n";
            else
                cout << "YES" << "\n";
        }
        
    }
}