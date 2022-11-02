#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

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
    int N;
    cin >> N;

    auto group = Vec<int>(N, 1, 0);
    for (int i = 0; i < N; ++i) group[i][0] = i;

    UnionFind uf(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u = uf.find(--u), v = uf.find(--v);
        uf.unite(u, v);

        if (uf.find(u) == v) swap(u, v);
        // v is merged to u.
        copy(group[v].begin(), group[v].end(), back_inserter(group[u]));
        group[v].clear();
    }

    int r = uf.find(0);
    for (int a : group[r]) cout << a + 1 << " ";
    cout << endl;
    return 0;
}