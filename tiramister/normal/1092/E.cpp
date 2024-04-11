#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int N) : V_NUM(N) {
        par.resize(V_NUM);
        rank.resize(V_NUM);
        num.resize(V_NUM);

        for (int i = 0; i < V_NUM; ++i) {
            par[i] = i;
        }
        fill(rank.begin(), rank.end(), 0);
        fill(num.begin(), num.end(), 1);
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (rank[x] < rank[y]) swap(x, y);

        num[x] += num[y];
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool ispar(int x) {
        return x == find(x);
    }

    int size(int x) {
        return num[find(x)];
    }

    const int INF = 1 << 25;
    int V_NUM;
    vector<int> par, rank, num;
};


vector<int> path[1010];

pair<int, int> farest_node(int r) {
    int d[1010];
    fill(d, d + 1000, -1);

    int ret = r;
    queue<int> que;
    que.push(r);
    d[r] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : path[v]) {
            if (d[sv] >= 0) continue;
            d[sv] = d[v] + 1;
            ret = sv;
            que.push(sv);
        }
    }

    return make_pair(d[ret], ret);
}

set<int> spec_dist(int r, int D) {
    int d[1010];
    fill(d, d + 1000, -1);

    set<int> ret;
    queue<int> que;
    que.push(r);
    d[r] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        if (d[v] == D) ret.insert(v);

        for (int sv : path[v]) {
            if (d[sv] >= 0) continue;
            d[sv] = d[v] + 1;
            que.push(sv);
        }
    }

    return ret;
}

pair<int, int> find_center(int r) {
    r = farest_node(r).second;
    int d, s;
    tie(d, s) = farest_node(r);

    auto S = spec_dist(r, d / 2);
    auto T = spec_dist(s, d - d / 2);

    for (int v : S) {
        if (T.find(v) == T.end()) continue;
        return make_pair(d - d / 2, v);
    }

    terminate();
}

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
        uf.unite(u, v);
    }

    vector<pair<int, int>> center;

    for (int v = 0; v < N; ++v) {
        if (uf.find(v) != v) continue;
        center.push_back(find_center(v));
    }

    vector<pair<int, int>> addedges;

    sort(center.rbegin(), center.rend());
    int u = center[0].second;
    while (center.size() > 1) {
        int v = center.back().second;
        center.pop_back();

        path[u].push_back(v);
        path[v].push_back(u);
        addedges.push_back(make_pair(u + 1, v + 1));
    }

    u = farest_node(u).second;
    int d = farest_node(u).first;

    cout << d << "\n";
    for (auto p : addedges) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}