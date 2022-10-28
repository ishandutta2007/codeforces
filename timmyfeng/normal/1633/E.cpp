#include <bits/stdc++.h>
using namespace std;

struct union_find {
    union_find(int n = 0) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) swap(u, v);
            parent[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }

    vector<int> parent, size;
};

struct edge {int u, v; long long w; };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<edge> edges(m);
    for (auto &e : edges) {
        cin >> e.u >> e.v >> e.w;
        --e.u, --e.v;
    }

    vector<long long> points = {0};
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            points.push_back((edges[i].w + edges[j].w + 1) / 2);
        }
    }

    ranges::sort(points);
    points.erase(begin(ranges::unique(points)), end(points));


    int k = (int) ssize(points);

    vector<long long> coeff(k), shift(k);

    for (int i = 0; i < k; ++i) {
        long long x = points[i];

        ranges::sort(edges, [&](edge a, edge b) {
            if (abs(x - a.w) == abs(x - b.w))
                return x - a.w < x - b.w;
            return abs(x - a.w) < abs(x - b.w);
        });

        union_find dsu(n);
        for (auto e : edges) {
            if (dsu.unite(e.u, e.v)) {
                if (e.w <= x) {
                    ++coeff[i], shift[i] -= e.w;
                } else {
                    --coeff[i], shift[i] += e.w;
                }
            }
        }
    }

    int p, q; cin >> p >> q;
    long long a, b, c; cin >> a >> b >> c;

    long long xor_sum = 0;

    vector<long long> x(q);
    for (int i = 0; i < q; ++i) {
        if (i < p) cin >> x[i];
        else x[i] = (x[i - 1] * a + b) % c;

        int range = (int) (ranges::upper_bound(points, x[i]) - begin(points) - 1);

        xor_sum ^= coeff[range] * x[i] + shift[range];
    }

    cout << xor_sum << "\n";
}