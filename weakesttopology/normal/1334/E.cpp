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

int main()
{ _
    ll D;
    cin >> D;

    vector<ll> pr;

    for (ll p = 2; p * p <= D; ++p)
    {
        if (D % p == 0)
        {
            pr.push_back(p);
            while (D % p == 0) D /= p;
        }
    }
    if (D > 1) pr.push_back(D);

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        ll u, v;
        cin >> u >> v;

        ll g = gcd(u, v);

        mint ways = 1;

        for (auto x : { u / g, v / g })
        {
            mint f = 1;
            int cnt = 0;
            for (auto p : pr)
            {
                int cur = 0;
                mint d = 1;
                while (x % p == 0) f *= ++cnt, d *= ++cur, x /= p;
                f /= d;
            }
            ways *= f;
        }

        cout << ways << endl;
    }

    exit(0);
}