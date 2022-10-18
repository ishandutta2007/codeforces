#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e5 + 5;

int n, m, ans;

vector <int> adj[N];

bool ck[N], col[N];

int h[N], maxh[N];

void dfs1(int u){
    ck[u] = 1;
    for (auto &v: adj[u]){
        if (!ck[v]){
            col[v] = !col[u];
            dfs1(v);
        }
    }
}

void dfs2(int u, int i){
    maxh[i] = max(maxh[i], maxh[u]);
    ck[u] = 1;
    for (auto &v: adj[u]){
        if (!ck[v]){
            col[v] = !col[u];
            dfs2(v, i);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!ck[i]){
            dfs1(i);
        }
    }
    for (int i = 1; i <= n; i++){
        for (auto &j: adj[i]){
            if (col[j] == col[i]){
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        memset(ck, 0, sizeof(ck));
        queue <pair <int, int>> qu;
        qu.push({i, 0});
        ck[i] = 1;
        while (!qu.empty()){
            pair <int, int> t = qu.front(); qu.pop();
            for (auto &v: adj[t.first]){
                if (!ck[v]){
                    ck[v] = 1;
                    qu.push({v, t.second + 1});
                    maxh[i] = t.second + 1;
                }
            }
        }
    }
    memset(ck, 0, sizeof(ck));
    for (int i = 1; i <= n; i++){
        if (!ck[i]){
            dfs2(i, i);
            ans += maxh[i];
        }
    }
    cout << ans;
}