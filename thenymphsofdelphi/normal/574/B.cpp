#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e3 + 5, inf = 1e18 + 7;

int n, m, ans = inf;
int sz[N];
vector <pair <int, int>> a;
bool adj[N][N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        a.push_back({u, v});
        adj[u][v] = adj[v][u] = 1;
        sz[u]++; sz[v]++;
    }
    for (int i = 0; i < m; i++){
        int u = a[i].first, v = a[i].second;
        for (int j = 1; j <= n; j++){
            if (j == u || j == v) continue;
            if (adj[u][j] && adj[v][j]){
                ans = min(ans, sz[u] + sz[v] + sz[j]);
            }
        }
    }
    cout << (ans >= inf ? -1 : ans - 6);
}