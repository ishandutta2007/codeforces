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

const int N = 200000 + 1;

int color[N];
vector<int> adj[N];
mint sub[N][3], v[N], ans;

void dfs_color(int u, int p = 0) {
    for (auto c : adj[u]) {
        if (c != p) {
            color[c] = color[u] ^ 1;
            dfs_color(c, u);
            for (int i = 0; i < 3; ++i) {
                sub[u][i] += sub[c][i];
            }
        }
    }
    ++sub[u][color[u]];
    ++sub[u][2];
}

void dfs_solve(int u, int p = 0) {
    mint coeff = sub[u][2];
    int x = color[u];
    for (auto c : adj[u]) {
        if (c != p) {
            dfs_solve(c, u);
            coeff += sub[c][x] * (sub[u][2] - sub[c][2]);
            coeff -= sub[c][x ^ 1] * (sub[u][2] - sub[c][2]);
        }
    }

    coeff += sub[u][x] * (sub[1][2] - sub[u][2]);
    coeff += (sub[1][x] - sub[u][x]) * sub[u][2];

    coeff -= sub[u][x ^ 1] * (sub[1][2] - sub[u][2]);
    coeff -= (sub[1][x ^ 1] - sub[u][x ^ 1]) * sub[u][2];

    ans += coeff * v[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        v[i] = a;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_color(1);
    dfs_solve(1);

    cout << ans << "\n";
}