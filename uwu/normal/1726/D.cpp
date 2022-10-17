#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        struct Edge{ int to, id; };
        vector<vector<Edge>> adj(N+1);
        for (int i = 0; i < M; ++i){
            int a, b; cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        
        int again = -1;
        vector<int> ans(M);
        vector<int> vis(N+1);
        vector<vector<int>> up(N+1);
        auto solve = [&](auto self, int v, int p) -> void{
            vis[v] = 1;
            for (auto [to, id] : adj[v]){
                if (to == p) continue;
                if (vis[to] == 1){
                    up[v].push_back(to);
                    ans[id] = 1;
                    continue;
                }
            }
            for (auto [to, id] : adj[v]){
                if (to == p) continue;
                if (vis[to] == 0) self(self, to, v);
            }
            if (up[v].size() == 2){
                if (!up[up[v][0]].empty() && up[up[v][0]][0] == up[v][1]) again = up[v][0];
                if (!up[up[v][1]].empty() && up[up[v][1]][0] == up[v][0]) again = up[v][1];
            }
            vis[v] = 2;
        };
        solve(solve, 1, 1);
        // cout << again << '\n';
        if (again != -1){
            vis = vector<int>(N+1, 0);
            ans = vector<int>(M, 0);
            solve(solve, again, again);
        }
        for (int x : ans) cout << x;
        cout << '\n';
    }
}