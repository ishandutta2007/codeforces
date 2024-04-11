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
    constexpr ll mod = 1e9 + 7, nmax = 5e3, kmax = 5e3;
    using mint = Mint<mod>;

    mint dp[kmax + 1][nmax], ct[nmax], a[nmax];

    fill(all(dp[0]), 1);

    int n, k, q; cin >> n >> k >> q;

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int j = 0; j < k; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
                dp[j + 1][i - 1] += dp[j][i];
            if (i + 1 < n)
                dp[j + 1][i + 1] += dp[j][i];
        }
    }

    mint ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
            ct[i] += dp[j][i] * dp[k - j][i];
        ans += ct[i] * a[i];
    }

    for (int z = 0; z < q; ++z)
    {
        int i; cin >> i; --i;

        ans -= ct[i] * a[i];

        cin >> a[i];

        ans += ct[i] * a[i];

        cout << ans << endl;
    }

    exit(0);
}