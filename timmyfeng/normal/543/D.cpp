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

using matrix = vector<vector<mint>>;

const int N = 200000 + 1;

vector<matrix> matrices[N];
vector<mint> ways[N];
vector<int> adj[N];
mint ans[N];

matrix mul(const matrix &a, const matrix &b) {
    matrix c = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return c;
}

vector<mint> mul(const matrix &a, const vector<mint> &b) {
    vector<mint> c = {0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c[i] += a[i][j] * b[j];
        }
    }
    return c;
}

matrix get(int c) {
    return {
        {ways[c][0], 0},
        {ways[c][0] + ways[c][1], 2 * ways[c][0] + ways[c][1]}
    };
}

void dfs_pull(int u) {
    ways[u] = {1, 0};
    for (auto c : adj[u]) {
        dfs_pull(c);
        matrices[u].push_back(get(c));
        ways[u] = mul(get(c), ways[u]);
    }
}

void dfs_push(int u) {
    ans[u] = ways[u][0] + ways[u][1];
    int m = adj[u].size();
    if (m == 0) {
        return;
    }

    vector<matrix> prefix(m), suffix(m);

    prefix[0] = {{1, 0}, {0, 1}};
    for (int i = 1; i < m; ++i) {
        prefix[i] = mul(prefix[i - 1], matrices[u][i - 1]);
    }

    suffix[m - 1] = matrices[u][m];
    for (int i = m - 2; i >= 0; --i) {
        suffix[i] = mul(suffix[i + 1], matrices[u][i + 1]);
    }

    for (int i = 0; i < m; ++i) {
        int c = adj[u][i];
        ways[u] = mul(mul(prefix[i], suffix[i]), {1, 0});
        matrices[c].push_back(get(u));
        ways[c] = mul(get(u), ways[c]);
        dfs_push(c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int par;
        cin >> par;
        adj[par].push_back(i);
    }

    dfs_pull(1);

    matrices[1].push_back({{1, 0}, {0, 1}});
    dfs_push(1);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}