#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

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


int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int x[K];
    for (int i = 0; i < K; ++i) {
        cin >> x[i];
        --x[i];
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> path;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        path.push(make_tuple(w, u - 1, v - 1));
    }

    UnionFind uf(N);
    int itr = 1;
    // x[0]x[itr]

    while (!path.empty()) {
        int w, u, v;
        tie(w, u, v) = path.top();
        path.pop();

        uf.unite(u, v);

        for (; itr < K; ++itr) {
            if (!uf.same(x[0], x[itr])) break;
        }

        if (itr == K) {
            for (int i = 0; i < K; ++i) {
                cout << w << " ";
            }
            cout << endl;
            break;
        }
    }
    return 0;
}