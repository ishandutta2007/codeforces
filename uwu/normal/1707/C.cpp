#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DisjointSet{
    vector<int> p, sz;
    DisjointSet(int N){
        p.resize(N);
        iota(p.begin(), p.end(), 0);
        sz.resize(N, 1);
    }
    int root(int x){
        return p[x] == x ? x : p[x] = root(p[x]);
    }
    bool unite(int a, int b){
        a = root(a), b = root(b);
        if (a == b) return 0;
        if (sz[b] > sz[a]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return 1;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;

    struct Edge{ int to, id; };
    vector<vector<Edge>> adj(N);
    DisjointSet dsu(N);
    vector<int> mst(M);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        mst[i] = dsu.unite(a, b);
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    vector<int> dot(N);
    vector<int> val(N);
    vector<int> vis(M);
    vector<int> path(N);
    vector<int> nxt(N);
    function<int(int, int)> dfs = [&](int v, int p) -> int{
        path[v] = 1;
        for (auto [to, id] : adj[v]){
            if (mst[id]){
                if (to == p) continue;
                nxt[v] = to;
                dfs(to, v);
            }
            else{
                if (vis[id]) continue;
                vis[id] = 1;
                dot[v]++;
                if (path[to]) dot[0]++, dot[nxt[to]]--;
                else dot[to]++;
            }
        }
        path[v] = 0;
        return val[v];
    }; dfs(0, 0);

    function<void(int, int, int)> collect = [&](int v, int p, int d){
        d += dot[v];
        val[v] += d;
        for (auto [to, id] : adj[v]){
            if (mst[id]){
                if (to == p) continue;
                collect(to, v, d);
            }
        }
    }; collect(0, 0, 0);

    for (int i = 0; i < N; ++i){
        // cout << dot[i] << " ";
        // cout << val[i] << " ";
        cout << (val[i] == (M - N + 1));
    }
    cout << '\n';
}