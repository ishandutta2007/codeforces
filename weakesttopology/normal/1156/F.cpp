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
    friend Mint operator+(ll lhs, const Mint& rhs) { return Mint(lhs) + rhs; }
    friend Mint operator-(ll lhs, const Mint& rhs) { return Mint(lhs) - rhs; }
    friend Mint operator*(ll lhs, const Mint& rhs) { return Mint(lhs) * rhs; }
    friend Mint operator/(ll lhs, const Mint& rhs) { return Mint(lhs) / rhs; }
    friend ostream& operator<<(ostream& out, const Mint& a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

constexpr int mod = 998244353;
using mint = Mint<mod>;

constexpr int nmax = 5000;
mint dp[nmax][nmax];

// dp[x][k] = probability of an increasing sequence of length k + 1 ending with x

int main()
{ _

    int n; cin >> n;
    vector<int> ct(n, 0);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; --x;
        ct[x] += 1;
    }

    vector<mint> inv(n + 1, 1);
    for (int x = 1; x <= n; ++x) inv[x] /= x;

    for (int x = 0; x < n; ++x) dp[x][0] = ct[x] * inv[n];
    for (int k = 1; k < n; ++k)
    {
        mint sum = 0;
        for (int x = 0; x < n; ++x)
        {
            dp[x][k] = ct[x] * inv[n - k] * sum;
            sum += dp[x][k - 1];
        }
    }

    mint ans = 0;

    for (int x = 0; x < n; ++x)
        for (int k = 0; k < n; ++k)
            ans += dp[x][k] * (ct[x] - 1) * inv[n - k - 1];

    cout << ans << endl;

    exit(0);
}