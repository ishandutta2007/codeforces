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

constexpr ll mod = 998244353;
using mint = Mint<mod>;

void advance(vector<mint>& dp, int n, int sum, int ub)
{
    for (int i = 0; i < n; ++i)
    {
        for (int y = sum - ub; y >= 0; --y)
        {
            dp[y + ub] -= dp[y];
        }
        for (int y = 1; y <= sum; ++y)
        {
            dp[y] += dp[y - 1];
        }
    }
}

int main()
{ _
    int p, s, r;
    cin >> p >> s >> r;

    if (p == 1)
    {
        cout << 1 << endl;
        exit(0);
    }
    if (r == 0)
    {
        cout << 1 / mint(p) << endl;
        exit(0);
    }

    const int maxfact = s + p;

    vector<mint> f(maxfact + 1, 1), inv(maxfact + 1, 1);
    for (int x = 1; x <= maxfact; ++x)
    {
        f[x] = x * f[x - 1], inv[x] = 1 / f[x];
    }

    auto C = [&f, &inv](int n, int k)
    {
        if (k == 0) return mint(1);
        return k > n ? 0 : f[n] * inv[k] * inv[n - k];
    };

    auto solve = [&C](int n, int sum, int ub)
    {
        mint res = C(n - 1 + sum, sum);

        for (int k = 1, sgn = -1; k <= min(n, sum / ub); ++k, sgn *= -1)
        {
            mint cur = 0;
            int remaining = sum - k * ub;
            for (int x = 0; x <= remaining; ++x)
            {
                cur += C(x + k - 1, x) * C(remaining - x + (n - k - 1), remaining - x);
            }
            res += sgn * C(n, k) * cur;
        }

        return res;
    };

    mint total = 0;
    for (int x = r; x <= s; ++x)
    {
        total += C(p - 2 + s - x, p - 2);
    }

    vector<mint> coef(p);
    for (int k = 0; k < p; ++k) coef[k] = 1 / total / (k + 1);

    mint res = 0;

    constexpr int magic = 200;

    for (int k = 0; k < p; ++k)
    {
        for (int x = max(r, magic); x * (k + 1) <= s; ++x)
        {
            res += C(p - 1, k) * solve(p - 1 - k, s - (k + 1) * x, x) * coef[k];
        }
    }

    for (int x = r; x < magic && x <= s; ++x)
    {
        int max_big = min(p, s / x);

        vector<mint> dp(s + 1, 0);
        dp[0] = 1;
        advance(dp, p - max_big, s, x);

        for (int k = max_big - 1; k >= 0; --k)
        {
            res += C(p - 1, k) * dp[s - (k + 1) * x] * coef[k];
            advance(dp, 1, s, x);
        }
    }

    cout << res << endl;

    exit(0);
}