#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

class UnionFind {
public:
    int V_NUM;
    vector<int> par, num;

    explicit UnionFind(int N) : V_NUM(N) {
        par.resize(N);
        iota(par.begin(), par.end(), 0);
        num.assign(N, 1);
    }

    int find(int x) {
        return (par[x] == x) ? x : (par[x] = find(par[x]));
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (num[x] < num[y]) swap(x, y);
        num[x] += num[y];
        par[y] = x;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    bool ispar(int x) { return x == find(x); }
    int size(int x) { return num[find(x)]; }
};

template <class WType>
class WeightedGraph {
public:
    explicit WeightedGraph(int size) : size(size) { path.resize(size); }

    void span(int u, int v, WType w) {path[u].push_back(make_pair(v, w));}
    vector<pair<int, WType>> adjnodes(int v) const {return path[v]; }

    int size;
    vector<vector<pair<int, WType>>> path;
};

template <class WType>
class LCA {
public:
    explicit LCA(const WeightedGraph<WType>& tree, int root) : size(tree.size), tree(tree) {
        par.assign(20, vector<int>(size));
        depth.resize(size);
        wdepth.resize(size);

        initdfs(root, -1, 0, WType(0));

        for (int k = 0; k < 19; ++k) {
            for (int v = 0; v < size; ++v) {
                if (par[k][v] < 0) {
                    par[k + 1][v] = -1;
                } else {
                    par[k + 1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    // initialize par[0], depth, wdepth
    void initdfs(int v, int r, int d, WType wd) {
        par[0][v] = r;
        depth[v] = d;
        wdepth[v] = wd;

        for (auto p : tree.adjnodes(v)) {
            int sv;
            WType w;
            tie(sv, w) = p;
            if (sv == r) continue;
            initdfs(sv, v, d + 1, wd + w);
        }
    }

    // the lowest common ancestor
    int lca(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v);

        // arrange the depth of u and v.
        int diff = depth[v] - depth[u];
        for (int k = 0; k < 20; ++k) {
            if ((diff >> k) & 1) v = par[k][v];
        }
        if (u == v) return u;

        // climb the tree
        for (int k = 19; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }

    // weighted distance between two nodes
    WType dist(int u, int v) const {
        int r = lca(u, v);
        return wdepth[u] + wdepth[v] - wdepth[r] * 2;
    }

    int size;
    WeightedGraph<WType> tree;
    vector<vector<int>> par;
    vector<int> depth;
    vector<WType> wdepth;  // weighted distance from the root
};

template <class WType>
vector<WType> dijkstra(const WeightedGraph<WType>& graph, int r) {
    vector<WType> dist(graph.size, INF);
    dist[r] = 0;

    priority_queue<pair<WType, int>, vector<pair<WType, int>>, greater<pair<WType, int>>> que;
    que.push(make_pair(0, r));
    while (!que.empty()) {
        WType d;
        int v;
        tie(d, v) = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (auto p : graph.adjnodes(v)) {
            int sv;
            WType w;
            tie(sv, w) = p;
            if (dist[sv] <= dist[v] + w) continue;

            dist[sv] = dist[v] + w;
            que.push(make_pair(dist[sv], sv));
        }
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> unused;
    WeightedGraph<ll> whole(N), tree(N);
    UnionFind uf(N);
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        whole.span(u, v, w);
        whole.span(v, u, w);

        if (uf.same(u, v)) {
            unused.push_back(u);
            continue;
        }
        uf.unite(u, v);
        tree.span(u, v, w);
        tree.span(v, u, w);
    }

    LCA<ll> lca(tree, 0);

    vector<vector<ll>> dist(unused.size());
    for (int i = 0; i < unused.size(); ++i) {
        dist[i] = dijkstra<ll>(whole, unused[i]);
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        ll ans = lca.dist(u, v);
        for (const auto& d : dist) {
            ans = min(ans, d[u] + d[v]);
        }
        cout << ans << "\n";
    }
    return 0;
}