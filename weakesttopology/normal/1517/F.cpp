#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll modpow(ll x, ll p, ll mod) {
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint {
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(Mint rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(Mint rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(Mint rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
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

    constexpr int hmax = 600;
    vector<array<mint, hmax + 2>> dp(n);
    vector<int> h(n);
    h[0] = n + 1;

    array<mint, hmax + 2> dpnxt, aux;
    auto dfs = [&](auto&& self, int u, int p, int r) -> void {
        fill(all(dp[u]), 0);
        dp[u][h[u]] = dp[u][h[u] - (r + 1)] = 1;
        for (auto v : E[u]) if (v != p) {
            h[v] = h[u] + 1;
            self(self, v, u, r);

            fill(all(dpnxt), 0);
            for (int t = 0; t < 2; ++t, swap(dp[u], dp[v])) {
                partial_sum(rall(dp[u]), rbegin(aux));
                for (int x = 0; x < h[u]; ++x) {
                    int d = min(hmax + 1, 2 * h[u] - x);
                    dpnxt[x] += dp[v][x] * (aux[x + 1] - aux[d]);
                }
                for (int x = h[u] + 1, d = h[u] - 1; x <= hmax; ++x, --d) {
                    dpnxt[x] += dp[v][x] * (aux[d] - aux[x]);
                }
            }
            for (int x = 0; x <= hmax; ++x) {
                dpnxt[x] += dp[u][x] * dp[v][x];
            }
            swap(dp[u], dpnxt);
        }
    };

    mint res = -1, T = mint(2).power(n);
    for (int r = 0; r <= n; ++r) {
        dfs(dfs, 0, -1, r);
        mint S = accumulate(begin(dp[0]), begin(dp[0]) + n + 1, mint(0));
        res += 1 - S / T;
    }
    cout << res << endl;

    exit(0);
}