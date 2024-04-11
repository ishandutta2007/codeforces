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

auto sieve(int N)
{
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

constexpr int pmax = 10;
int sgn[1 << pmax], factors[pmax], prod[1 << pmax];

int main()
{ _
    constexpr int mod = 1e9 + 7;
    using mint = Mint<mod>;

    sgn[0] = -1;
    for (int mask = 1; mask < (1 << pmax); ++mask)
        sgn[mask] = -sgn[mask & (mask - 1)];

    int n; cin >> n;

    auto [lp, pr] = sieve(n);

    vector<mint> dp(n + 1);

    mint ans = 0;

    for (int x = 1; x <= n; ++x)
    {
        if (x > 1) dp[x] += n / mint(n - n / x);

        for (int k = 2; k * x <= n; ++k)
        {
            int ct = 0;

            for (int z = k; z > 1;)
            {
                int p = lp[z];
                factors[ct++] = p;
                while (z % p == 0) z /= p;
            }

            prod[0] = 1;
            for (int j = 0; j < ct; ++j) prod[1 << j] = factors[j];
            for (int mask = 1; mask < (1 << ct); ++mask)
            {
                int msb = mask & (mask - 1);
                prod[mask] = prod[msb] * prod[mask ^ msb];
            }

            int bad = 0;

            for (int mask = 1; mask < (1 << ct); ++mask)
                bad += sgn[mask] * (n / x) / prod[mask];

            dp[k * x] += dp[x] * mint(n / x - bad) / (n - n / (k * x));
        }

        ans += (1 + dp[x]) / n;
    }

    cout << ans << endl;

    exit(0);
}