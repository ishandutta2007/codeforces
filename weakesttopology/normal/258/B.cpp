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
    operator int() const { return x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

int main()
{ _
    constexpr int MOD = 1e9 + 7;

    using M = Mint<MOD>;

    string s; cin >> s;

    int n = size(s);

    vector dp(2, vector(2, vector(n + 1, 0)));

    int b = 0; dp[b][0][0] = M(1);

    for (auto c : s)
    {
        for (int k = 0; k <= n; ++k)
            dp[b ^ 1][1][k] += 8 * dp[b][1][k];

        for (int k = 0; k + 1 <= n; ++k)
            dp[b ^ 1][1][k + 1] += 2 * dp[b][1][k];

        for (int k = 0; k < n; ++k)
        {
            for (int x = 0; '0' + x < c; ++x)
                dp[b ^ 1][1][k + (x == 4 || x == 7)] += dp[b][0][k];

            dp[b ^ 1][0][k + (c == '4' || c == '7')] += dp[b][0][k];
        }

        for (int t = 0; t < 2; ++t) fill(all(dp[b][t]), 0);

        b ^= 1;
    }


    vector ct(n + 1, 0);

    for (int k = 0; k <= n; ++k)
        for (int t = 0; t < 2; ++t)
            ct[k] += dp[b][t][k];

    ct[0] -= 1;

    function<M(int, int)> dfs = [&](int sum, int h)
    {
        if (h == 0) return M(1);

        M res = 0;

        for (int k = 0; k <= sum; ++k)
        {
            int w = ct[k];

            ct[k] -= 1;
            res += M(w) * dfs(sum - k, h - 1);
            ct[k] += 1;
        }

        return res;
    };

    M ans = 0LL;

    for (int k = 0; k < n; ++k) ans += M(ct[k + 1]) * dfs(k, 6);

    cout << ans << endl;

    exit(0);
}