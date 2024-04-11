#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    constexpr int nmax = 5000;
    vector<array<mint, nmax>> dp(n);
    vector<int> h(n);

    array<mint, nmax> aux, dpnxt;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        dp[u][h[u]] = 1;
        for (auto v : E[u]) if (v != p) {
            h[v] = h[u] + 1;
            self(self, v, u);
            dp[v][h[u]] = accumulate(all(dp[v]), mint(0));

            fill(all(dpnxt), 0);
            partial_sum(all(dp[u]), begin(aux));
            for (int x = h[u]; x <= min(n - 1, h[u] + k); ++x) {
                dpnxt[x] += aux[min(x, 2 * h[u] + k - x)] * dp[v][x];
            }
            partial_sum(all(dp[v]), begin(aux));
            for (int x = h[u]; x <= min(n - 1, h[u] + k); ++x) {
                dpnxt[x] += aux[min(x, 2 * h[u] + k - x)] * dp[u][x];
            }
            for (int x = h[u]; x <= min(n - 1, h[u] + k / 2); ++x) {
                dpnxt[x] -= dp[u][x] * dp[v][x];
            }
            swap(dp[u], dpnxt);
        }
    };
    dfs(dfs, 0, -1);

    mint res = accumulate(begin(dp[0]), begin(dp[0]) + k + 1, mint(0));
    cout << res << endl;

    exit(0);
}