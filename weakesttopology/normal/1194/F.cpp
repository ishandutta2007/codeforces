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
    const int mod = 1e9 + 7;
    using Mi = Mint<mod>;

    int n; cin >> n;
    ll T; cin >> T;

    vector<Mi> f(n + 1, 1), inv(n + 1, 1);

    for (int k = 1; k <= n; ++k) f[k] = f[k - 1] * k, inv[k] = inv[k - 1] / k;

    auto C = [&f, &inv](ll n, ll k) { return n < k ? Mi(0) : f[n] * inv[k] * inv[n - k]; };

    vector<ll> t(n + 1); t[n] = LINF;

    for (int i = 0; i < n; ++i) cin >> t[i];

    Mi pow = 1, p = Mi(1) / 2, ans = 0;

    ll sum = 0LL;

    for (ll i = 0; i < n; ++i)
    {
        sum += t[i], pow *= p;

        ll sum_nxt = sum + t[i + 1];

        for (ll k = max(0LL, T - sum_nxt); k <= min(i + 1, T - sum); ++k)
            ans += pow * Mi(i + 1) * C(i + 1, k) * (sum_nxt + k == T ? p : Mi(1));
    }

    cout << ans << endl;

    exit(0);
}