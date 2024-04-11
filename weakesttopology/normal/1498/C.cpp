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
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};

constexpr ll mod = 1e9 + 7;
using mint = Mint<mod>;

constexpr int nmax = 1e3, kmax = 1e3;
mint dp[nmax][kmax];

mint solve()
{
    int n, k;
    cin >> n >> k;

    if (n == 1) return 1 + (k > 1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j) dp[i][j] = 0;

    for (int i = 0; i < n; ++i) dp[i][0] = 1;

    for (int j = 1; j < k; ++j)
    {
        dp[n - 1][j] = dp[1][j - 1] + 1;

        for (int i = n - 2; i > 0; --i)
            dp[i][j] = dp[i + 1][j] + dp[n - i][j - 1];

        dp[0][j] = dp[1][j] + 1;
    }

    return dp[0][k - 1];
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}