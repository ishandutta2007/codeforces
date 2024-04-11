#include <bits/stdc++.h>
using namespace std;

struct union_find {
    union_find(int n = 0) : parent(n), edges(n), size(n, 1) {
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
        ++edges[u];
        if (u != v) {
            if (size[u] > size[v]) swap(u, v);
            parent[u] = v;
            size[v] += size[u];
            edges[v] += edges[u];
            return true;
        }
        return false;
    }

    vector<int> parent, edges, size;
};

template <int M>
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = (int) ((long long) n * r.n % M); return *this; }

    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }

    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = 1, p = *this;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint<998244353>;

mint fact(int n) {
    mint result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

mint choose(int n, int k) {
    return fact(n) * (fact(n - k) * fact(k)).pow();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<array<int, 3>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({abs(x[i] - x[j]) + abs(y[i] - y[j]), i, j});
        }
    }
    sort(edges.begin(), edges.end());

    union_find dsu(n);
    vector<int> dist(n, INT_MAX);
    for (auto [w, u, v] : edges) {
        if (dist[u] > dist[v]) swap(u, v);
        if (w <= min(dist[u], dist[v])) {
            dist[u] = dist[v] = w;
            dsu.unite(u, v);
        } else if (w <= dist[v]) --dsu.edges[v];
    }

    vector<mint> ways(n + 1);
    ways[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i) {
            int s = dsu.size[i];
            vector<mint> new_ways(n + 1);
            for (int j = 0; j <= n; ++j) {
                if (j + 1 <= n && dsu.edges[i] == s * (s - 1) / 2) new_ways[j + 1] += ways[j] * choose(j + 1, 1);
                if (j + s <= n) new_ways[j + s] += ways[j] * choose(j + s, s) * fact(s);
            }
            swap(ways, new_ways);
        }
    }

    mint answer = 0;
    for (int i = 0; i <= n; ++i) {
        answer += choose(n, i) * ways[i];
    }

    cout << answer << "\n";
}