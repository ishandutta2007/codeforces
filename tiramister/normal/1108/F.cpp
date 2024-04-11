#include <iostream>
#include <numeric>
#include <map>
#include <vector>

using namespace std;

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

int main() {
    int N, M;
    cin >> N >> M;

    map<int, vector<pair<int, int>>> edges;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[w].push_back(make_pair(u, v));
    }

    int ans = 0;
    UnionFind uf(N);
    for (auto p : edges) {
        vector<pair<int, int>> useful;
        // 2

        for (auto e : p.second) {
            if (!uf.same(e.first, e.second)) useful.push_back(e);
        }

        for (auto e : useful) {
            if (uf.same(e.first, e.second)) {
                // 
                // MST
                ++ans;
            } else {
                uf.unite(e.first, e.second);
            }
        }
    }

    cout << ans << endl;
    return 0;
}