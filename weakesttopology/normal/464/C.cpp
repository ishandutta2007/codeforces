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
    constexpr int mod = 1e9 + 7;
    using Mi = Mint<mod>;

    string s; cin >> s;

    int n; cin >> n;

    vector<pair<int, string>> queries(n);

    for (auto& [d, t] : queries)
    {
        string q; cin >> q;
        d = q[0] - '0', t = q.substr(3, size(q) - 3);
    }

    const int D = 10;

    vector<pair<Mi, Mi>> equiv(D);

    for (int d = 0; d < D; ++d) equiv[d] = { Mi(10), Mi(d) };

    reverse(all(queries));

    for (const auto& [d, t] : queries)
    {
        Mi res = 0, shift = 1;

        for (auto ch : t)
        {
            int e = ch - '0';
            res = equiv[e].first * res + equiv[e].second;
            shift *= equiv[e].first;
        }

        equiv[d] = { shift, res };
    }

    Mi res = 0;

    for (auto ch : s)
    {
        int d = ch - '0';
        res = equiv[d].first * res + equiv[d].second;
    }

    cout << res << endl;

    exit(0);
}