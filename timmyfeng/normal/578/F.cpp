#include <bits/stdc++.h>
using namespace std;

int M;
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


const int N = 200 + 1;

int label[N * N], k[2], m;
mint laplacian[2][N][N];
string grid[N];

int to_int(int i, int j) {
    return i * (m + 1) + j;
}

void update(mint adj[][N], int u, int v) {
    if (max(u, v) < N) {
        --adj[u][v];
        --adj[v][u];
        ++adj[u][u];
        ++adj[v][v];
    }
}

mint det(mint adj[][N], int n) {
    mint res = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[j][i] != 0) {
                swap_ranges(adj[i], adj[i] + n, adj[j]);
                res *= -1;
                break;
            }
        }

        res *= adj[i][i];
        if (adj[i][i] == 0) {
            break;
        }

        mint inv = adj[i][i].pow();
        for (int j = i; j < n; ++j) {
            adj[i][j] *= inv;
        }

        for (int j = i + 1; j < n; ++j) {
            for (int r = n - 1; r >= i; --r) {
                adj[j][r] -= adj[i][r] * adj[j][i];
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> m >> M;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    union_find dsu((n + 1) * (m + 1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '\\') {
                dsu.unite(to_int(i, j), to_int(i + 1, j + 1));
            } else if (grid[i][j] == '/') {
                dsu.unite(to_int(i + 1, j), to_int(i, j + 1));
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dsu.find(to_int(i, j)) == to_int(i, j)) {
                label[to_int(i, j)] = k[(i + j) % 2]++;
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (grid[i][j] == '*') {
                update(laplacian[(i + j) % 2],
                    label[dsu.find(to_int(i, j))],
                    label[dsu.find(to_int(i + 1, j + 1))]);
                update(laplacian[1 - (i + j) % 2],
                    label[dsu.find(to_int(i + 1, j))],
                    label[dsu.find(to_int(i, j + 1))]);
            }
        }
    }

    mint ans = 0;
    for (int p = 0; p < 2; ++p) {
        if (k[p] > N) {
            continue;
        }
        ans += det(laplacian[p], k[p]);
    }

    cout << ans << "\n";
}