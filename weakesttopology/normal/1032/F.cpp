#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint
{
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) {  }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    friend Mint operator+(const Mint& lhs, const Mint& rhs) { return Mint(lhs) += rhs; }
    friend Mint operator-(const Mint& lhs, const Mint& rhs) { return Mint(lhs) -= rhs; }
    friend Mint operator*(const Mint& lhs, const Mint& rhs) { return Mint(lhs) *= rhs; }
    friend Mint operator/(const Mint& lhs, const Mint& rhs) { return Mint(lhs) /= rhs; }
    friend ostream& operator<<(ostream& out, const Mint& a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

int main()
{ _
    constexpr ll mod = 998244353;
    using mint = Mint<mod>;

    int n; cin >> n;

    vector<vector<int>> E(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
        deg[u] += 1, deg[v] += 1;
    }

    vector<array<mint, 3>> dp(n);

    for (int u = 0; u < n; ++u) dp[u][0] = 1, dp[u][2] = 1;

    function<void(int, int)> solve = [&](int u, int p)
    {
        for (auto v : E[u]) if (v != p)
        {
            solve(v, u);
            dp[u][0] *= dp[v][0] + dp[v][1];
            dp[u][2] *= dp[v][0] + 2 * dp[v][1];
        }

        vector<mint> prefix(deg[u], 1), suffix(deg[u], 1);

        for (int j = 0; j + 1 < deg[u]; ++j)
        {
            int v = E[u][j];
            prefix[j + 1] = prefix[j] * (v != p ? dp[v][0] + 2 * dp[v][1] : 1);
        }
        for (int j = deg[u] - 1; j > 0; --j)
        {
            int v = E[u][j];
            suffix[j - 1] = suffix[j] * (v != p ? dp[v][0] + 2 * dp[v][1] : 1);
        }
        for (int j = 0; j < deg[u]; ++j)
        {
            int v = E[u][j];
            if (v == p) continue;
            dp[u][1] += dp[v][2] * prefix[j] * suffix[j];
        }
    };
    solve(0, -1);

    mint ans = dp[0][0] + dp[0][1];

    cout << ans << endl;

    exit(0);
}