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
constexpr ll mod = 1e9 + 7, nmax = 200;
using mint = Mint<mod>;
mint dp[nmax + 1][nmax + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    for (int x = 1; x <= n; ++x) {
        dp[x][0] = 1;
        for (int y = 1; y <= n; ++y) {
            dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) / 2;
        }
    }
    mint ans = 0;
    for (int rt = 0; rt < n; ++rt) {
        vector<int> sz(n);
        auto dfs1 = [&](auto& self, int u, int p) -> void {
            sz[u] = 1;
            for (auto v : E[u]) {
                if (v == p) continue;
                self(self, v, u);
                sz[u] += sz[v];
            }
        };
        dfs1(dfs1, rt, -1);
        vector<int> w;
        auto dfs2 = [&](auto& self, int u, int p) -> void {
            for (auto v : E[u]) {
                if (v == p) continue;
                w.push_back(sz[u] - sz[v]);
                if (rt < v) {
                    w.push_back(sz[v]);
                    int k = (int)size(w);
                    mint tot = accumulate(begin(w), end(w), 0);
                    for (int j = 0; j < k; ++j) {
                        ans += (w[j] / tot) * dp[j][k - 1 - j];
                    }
                    w.pop_back();
                }
                self(self, v, u);
                w.pop_back();
            }
        };
        dfs2(dfs2, rt, -1);
    }
    cout << ans << endl;
    exit(0);
}