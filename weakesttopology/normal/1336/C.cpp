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
    x %= mod, (p %= mod - 1) < 0 ? p += mod - 1 : 0LL;
    ll res = 1LL;
    while (p > 0)
    {
        if (p & 1) res = res * x % mod;
        (x *= x) %= mod, p >>= 1;
    }
    return res;
}

template<int mod>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= mod) < 0 ? x + mod : x)) {  }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % mod); return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= Mint(modpow(rhs.x, mod - 2, mod)); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
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
    constexpr int mod = 998244353;
    using Mi = Mint<mod>;

    string s, t; cin >> s >> t;

    int n = size(s), m = size(t);

    vector<Mi> dp(m, 0), dpnxt(m, 0);

    for (int j = 0; j < m; ++j)
        if (t[j] == s[0]) dp[j] = 2;

    // suffix[j] = # of ways to build t[j, ..., m - 1] from s[0, m - 1 - j]

    vector<Mi> suffix(m, 0);

    suffix[m - 1] = dp[m - 1];

    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j + 1 < m; ++j) if (t[j] == s[i])
            dpnxt[j] += dp[j + 1];

        for (int j = 0; j + i < m; ++j) if (t[j + i] == s[i])
            dpnxt[j] += dp[j];

        swap(dp, dpnxt), fill(all(dpnxt), 0);

        suffix[m - 1 - i] = dp[m - 1 - i];
    }


    // prefix[i][j] = # of ways to build t[0, ..., j] from s[i, ..., n - 1]

    vector prefix(n + 1, vector<Mi>(m + 1));

    for (int i = n - 1; i >= 0; --i)
        prefix[i][0] = Mi((n - i) * (t[0] == s[i])) + prefix[i + 1][0];

    for (int j = 1; j < m; ++j)
    {
        for (int i = 0; i < n; ++i) if (s[i] == t[j])
            prefix[i][j] = prefix[i + 1][j - 1];

        for (int i = n - 1; i >= 0; --i)
            prefix[i][j] += prefix[i + 1][j];
    }

    Mi ans = suffix[0] * (n - m + 1), power = 2;

    for (int i = 1; i < n; ++i)
        ans += (prefix[i][m - 1] - prefix[i + 1][m - 1]) * power, power *= 2;

    for (int j = 1; j < m; ++j)
        ans += suffix[j] * prefix[m - j + 1][j - 1];

    cout << ans << endl;

    exit(0);
}