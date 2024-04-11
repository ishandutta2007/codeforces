#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

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

    int V_NUM;
    vector<int> par, rank, num;
};


int main() {
    int N, M;
    cin >> N >> M;

    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int r = min_element(a, a + N) - a;

    GPQ<tuple<ll, int, int>> que;
    for (int i = 0; i < N; ++i) {
        if (i == r) continue;
        que.push(make_tuple(a[r] + a[i], r, i));
    }

    for (int i = 0; i < M; ++i) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        --x, --y;
        que.push(make_tuple(w, x, y));
    }

    UnionFind uf(N);
    ll ans = 0;
    while (!que.empty()) {
        int x, y;
        ll w;
        tie(w, x, y) = que.top();
        que.pop();

        if (uf.same(x, y)) continue;
        ans += w;
        uf.unite(x, y);
    }

    cout << ans << endl;
    return 0;
}