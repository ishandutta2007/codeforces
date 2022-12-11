#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e3 + 10;

int w[2][N];
vector<int> adj[N];
pair<int, int> f[N][N];
pair<int, int> tmpf[N];
int n, m;


template<class T> 
bool maximize(T &x, T y) {
    if (x < y) return x = y, 1;
    return 0;
}
int DFS(int u, int par) {
    int subU = 1;
    f[u][0] = {0, w[1][u] - w[0][u]};
    f[u][1] = {-1, 0};

    for(auto v : adj[u]) if (v != par) {
        int subV = DFS(v, u);

        for(int i = 0; i <= subV + subU + 1; i++)
            tmpf[i] = {-1, 0};

        for(int useU = 0; useU <= subU; useU++)
            for(int useV = 0; useV <= subV; useV++) {
                //don't merge
                pair<int, int> notMerge = {f[u][useU].first + f[v][useV].first + (f[v][useV].second > 0), f[u][useU].second};
                maximize(tmpf[useU + useV + 1], notMerge);
                pair<int, int> doMerge = {f[u][useU].first + f[v][useV].first, f[u][useU].second + f[v][useV].second};
                maximize(tmpf[useU + useV], doMerge);
            }
        for(int i = 0; i <= subV + subU + 1; i++) 
            f[u][i] = tmpf[i];
        subU += subV;
    }
    return subU;
}
int solve() {
    DFS(1, -1);
    return f[1][m - 1].first + (f[1][m - 1].second > 0);
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--) { 
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> w[0][i]; 
        for(int i = 1; i <= n; i++) cin >> w[1][i]; 
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << solve() << '\n';
        for(int i = 1; i <= n; i++) adj[i].clear();
    }
}