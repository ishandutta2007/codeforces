#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<ll mod>
struct Mint {
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { return (x += rhs.x) >= mod ? x -= mod : 0, *this; }
    Mint& operator-=(Mint rhs) { return (x -= rhs.x) < 0 ? x += mod : 0, *this; }
    Mint& operator*=(Mint rhs) { return (x *= rhs.x) %= mod, *this; }
    Mint& operator/=(Mint rhs) { return *this *= rhs.power(-1); }
    Mint power(ll p) const {
        p %= mod - 1;
        if (p < 0) p += mod - 1;
        Mint res = 1;
        for (Mint y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a) {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};
constexpr ll mod = 998244353;
using mint = Mint<mod>;
struct DSU {
    vector<int> p, sz, e;
    vector<vector<mint>> dp;
    DSU(int n) : p(n), sz(n, 1), e(n), dp(n, {0, 1}) {
        iota(begin(p), end(p), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        ++e[u];
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            p[v] = u, sz[u] += sz[v], e[u] += e[v];
            int k = (int)size(dp[u]), l = (int)size(dp[v]);
            vector<mint> ndp(k + l - 1);
            for (int x = 0; x < k; ++x) {
                for (int y = 0; y < l; ++y) {
                    ndp[x + y] += dp[u][x] * dp[v][y];
                }
            }
            swap(dp[u], ndp);
        }
        if (sz[u] * (sz[u] - 1) / 2 == e[u]) {
            dp[u][1] += 1;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> edges;
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            int a;
            cin >> a;
            if (u < v) edges.push_back({a, u, v});
        }
    }
    sort(begin(edges), end(edges));
    DSU dsu(n);
    for (auto [a, u, v] : edges) {
        dsu.unite(u, v);
    }
    int rt = dsu.find(0);
    for (int x = 1; x <= n; ++x) {
        cout << dsu.dp[rt][x] << "\n "[x < n];
    }
    exit(0);
}