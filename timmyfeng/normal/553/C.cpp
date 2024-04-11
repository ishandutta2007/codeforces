#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

    int value;

    mint() : value(0) {}

    template <class T>
    mint(T x) {
        value = x % M;
        if (value < 0) {
            value += M;
        }
    }

    mint & operator++() {
        if (++value == M) {
            value = 0;
        }
        return *this;
    }

    mint & operator--() {
        if (--value == -1) {
            value = M - 1;
        }
        return *this;
    }

    mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }

    mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }

    mint & operator+=(mint oth) {
        value += oth.value;
        if (value >= M) {
            value -= M;
        }
        return *this;
    }

    mint & operator-=(mint oth) {
        value -= oth.value;
        if (value < 0) {
            value += M;
        }
        return *this;
    }

    mint & operator*=(mint oth) {
        value = (long long) value * oth.value % M;
        return *this;
    }

    mint operator+() const {
        return *this;
    }

    mint operator-() const {
        return mint() - *this;
    }

    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }

    friend mint operator+(mint a, mint b) {
        return a += b;
    }

    friend mint operator-(mint a, mint b) {
        return a -= b;
    }

    friend mint operator*(mint a, mint b) {
        return mint(a) *= b;
    }

    friend bool operator==(mint a, mint b) {
        return a.value == b.value;
    }

    friend bool operator!=(mint a, mint b) {
        return a.value != b.value;
    }

    friend ostream & operator<<(ostream &out, mint a) {
        out << a.value;
        return out;
    }

};

struct union_find {

    vector<int> par, size;

    union_find(int n) {
        par.resize(n);
        size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (par[u] != u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            par[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }

};

const int N = 100000 + 1;

bool visited[N], color[N];
vector<int> adj[N];

void dfs(int u) {
    visited[u] = true;
    for (auto c : adj[u]) {
        if (visited[c]) {
            if (color[u] == color[c]) {
                cout << 0 << "\n";
                exit(0);
            }
        } else {
            color[c] = color[u] ^ true;
            dfs(c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> edges;
    union_find dsu(n + 1);

    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;

        if (t == 1) {
            dsu.unite(u, v);
        } else {
            edges.push_back({u, v});
        }
    }

    for (auto [u, v] : edges) {
        u = dsu.find(u);
        v = dsu.find(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    mint ans = mint(2).pow();
    for (int i = 1; i <= n; ++i) {
        if (dsu.find(i) == i && !visited[i]) {
            ans *= 2;
            dfs(i);
        }
    }

    cout << ans << "\n";
}