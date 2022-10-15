#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
T power(T x, ll p)
{
    T res = T(1);
    while (p)
    {
        if (p & 1) res *= x;
        p >>= 1, x *= x;
    }
    return res;
}

template<int MOD>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= MOD) < 0 ? x + MOD : x)) {};
    Mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= MOD) x -= MOD; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += MOD - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % MOD); return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= rhs.inv(); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    friend ostream& operator<<(ostream& out, const Mint& a) { out << a.x; return out; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

int main()
{ _
    int n; cin >> n;

    vector E(n, vector(0, 0));

    for (int u = 1; u < n; ++u)
    {
        int p; cin >> p;
        E[p].push_back(u);
    }

    vector x(n, 0);

    for (int u = 0; u < n; ++u) cin >> x[u];

    constexpr ll MOD = 1e9 + 7;
    using M = Mint<MOD>;

    vector dp(n, array<M, 2>({0, 0}));

    for (int u = n - 1; u >= 0; --u)
    {
        if (x[u])
        {
            dp[u][1] = M(1);
            for (auto v : E[u])
                dp[u][1] *= dp[v][0] + dp[v][1];
        }
        else
        {
            dp[u][0] = M(1);

            for (auto v : E[u])
                dp[u][0] *= dp[v][0] + dp[v][1];

            for (auto v : E[u])
                dp[u][1] += dp[v][1] * (dp[u][0] / (dp[v][0] + dp[v][1]));
        }
    }

    M ans = dp[0][1];

    debug(dp[0][0]);
    debug(dp[0][1]);

    cout << ans << endl;

    exit(0);
}