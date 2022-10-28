#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 401, MOD = 998244353;

struct mint {
    int x;

    mint() : x(0) {}

    template <class T> mint(T value) : x(value % MOD) { if (x < 0) x += MOD; }

    mint & operator+=(const mint &oth) { x += oth.x; if (x >= MOD) x -= MOD; return *this; }

    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += MOD; return *this; }

    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % MOD; return *this; }

    friend mint operator+(mint l, const mint &r) { return l += r; }

    friend mint operator-(mint l, const mint &r) { return l -= r; }

    friend mint operator*(mint l, const mint &r) { return l *= r; }

    mint & operator--() { if (--x == -1) x = MOD - 1; return *this; }

    mint & operator++() { if (++x == MOD) x = 0; return *this; }

    mint operator--(int) { mint temp = *this; --*this; return temp; }

    mint operator++(int) { mint temp = *this; ++*this; return temp; }

    mint operator-() const { return 0 - *this; }

    mint operator+() const { return *this; }

    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }

    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }

    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }

    mint pow(long long e = MOD - 2) const {
        mint ans = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                ans *= b;
            }
            b *= b;
            e /= 2;
        }
        return ans;
    }
};

int dist[MAX_N][MAX_N], depth[MAX_N], root[MAX_N];
vector<int> adj[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = i == j ? 0 : MAX_N;
        }
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dist[u][v] = dist[v][u] = 1;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                root[k] = dist[i][k] - dist[j][k] + dist[i][j];
                depth[k] = dist[i][k] + dist[j][k] - dist[i][j];
            }

            if (count(depth + 1, depth + n + 1, 0) > dist[i][j] + 1) {
                cout << 0 << " ";
                continue;
            }

            mint ways = 1;
            for (int k = 1; k <= n; ++k) {
                if (depth[k] != 0) {
                    mint par = 0;
                    for (auto l : adj[k]) {
                        par += root[l] == root[k] && depth[l] + 2 == depth[k];
                    }
                    ways *= par;
                }
            }

            cout << ways << " ";
        }
        cout << "\n";
    }
}