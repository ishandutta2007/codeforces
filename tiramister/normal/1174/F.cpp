#include <iostream>
#include <vector>
#include <queue>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

template <class Cost = int>
struct Centroid {
    Graph<Cost> graph;
    int size;
    std::vector<int> sz;

    std::vector<int> center;

    int dfs(int v, int r) {
        sz[v] = 1;
        for (auto e : graph[v]) {
            if (e.dst == r) continue;
            sz[v] += dfs(e.dst, v);
        }
        return sz[v];
    }

    void judge(int v, int r) {
        bool valid = (size - sz[v]) * 2 <= size;

        for (auto e : graph[v]) {
            if (e.dst == r) continue;

            if (sz[e.dst] * 2 > graph.size()) {
                valid = false;
            }
            judge(e.dst, v);
        }
        if (valid) center.push_back(v);
    }

    Centroid(const Graph<Cost>& graph, int root)
        : graph(graph), sz(graph.size()) {
        dfs(root, -1);
        size = sz[root];
        judge(root, -1);
    }
};


using namespace std;

int N;
Graph<> tree;

int query(int t, int v) {
    static vector<vector<int>> res(2, vector<int>(N, -1));
    int& ret = res[t][v];

    if (ret >= 0) return ret;
    cout << "ds"[t] << " " << v + 1 << endl;

    cin >> ret;
    if (t == 1) --ret;
    return ret;
}

void answer(int v) {
    cout << "! " << v + 1 << endl;
    exit(0);
}

// treepr
void decomp(int r, int p) {
    Graph<> ntree(N);

    queue<int> que;
    que.push(r);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : tree[v]) {
            if (!ntree[e.dst].empty() || e.dst == p) continue;
            ntree[v].emplace_back(v, e.dst);
            que.push(e.dst);
        }
    }

    tree = ntree;
}

int dist(int s, int t) {
    vector<int> d(N, -1);
    d[s] = 0;
    queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : tree[v]) {
            if (d[e.dst] >= 0) continue;
            d[e.dst] = d[v] + 1;
            que.push(e.dst);
        }
    }
    return d[t];
}

int main() {
    cin >> N;

    tree = Graph<>(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].emplace_back(u, v);
        tree[v].emplace_back(v, u);
    }
    decomp(0, -1);

    int v = 0;
    while (true) {
        int dv = query(0, v);
        if (dv == 0) answer(v);

        Centroid<> C(tree, v);
        int c = C.center.front();

        int dc = query(0, c);
        if (dc == 0) answer(c);

        if (v == c) {
            int s = query(1, v);
            decomp(s, -1);
            v = s;
            continue;
        }

        int l = dist(v, c);
        if (dv - dc == l) {
            // xc
            decomp(c, -1);
            v = c;
        } else {
            // xc
            decomp(v, c);
        }
    }
    return 0;
}