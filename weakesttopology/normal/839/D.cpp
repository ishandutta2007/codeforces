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
    bool operator!=(const Mint& rhs) const { return x != rhs.x; }
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
    constexpr ll mod = 1e9 + 7, amax = 1e6;
    using mint = Mint<mod>;

    int n; cin >> n;

    vector<int> cnt(amax + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        cnt[x] += 1;
    }

    vector<mint> f(amax + 1), h(amax + 1);

    for (int d = 1; d <= amax; ++d)
    {
        int num = 0;
        for (int x = d; x <= amax; x += d) num += cnt[x];
        if (num > 0) f[d] = num * mint(2).power(num - 1);
    }

    mint ans = 0;

    for (int g = amax; g > 1; --g)
    {
        h[g] = f[g];
        for (int x = 2 * g; x <= amax; x += g) h[g] -= h[x];
        ans += g * h[g];
    }

    cout << ans << endl;

    exit(0);
}