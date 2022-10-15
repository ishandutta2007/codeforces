#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
T power(T x, ll p)
{
    T res = T(1);
    while (p)
    {
        if (p & 1) res *= x;
        p >>= 1, x *= x;
    }
    return res;
}

template<int MOD>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= MOD) < 0 ? x + MOD : x)) {};
    Mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= MOD) x -= MOD; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += MOD - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % MOD); return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= rhs.inv(); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    operator int() const { return x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

int main()
{ _
    int n, x, pos; cin >> n >> x >> pos;

    int small = 0, big = 0;

    int left = 0, right = n;

    while (left < right)
    {
        int middle = (left + right) / 2;

        if (middle <= pos)
        {
            small += 1;
            left = middle + 1;
        }
        else
        {
            big += 1;
            right = middle;
        }
    }

    small -= 1;

    constexpr ll MOD = 1e9 + 7;
    using M = Mint<MOD>;

    vector f(n + 1, M(1));

    for (int x = 1; x <= n; ++x)
        f[x] = M(x) * f[x - 1];

    auto C = [&](int n, int k) { return (k <= n ? f[n] / (f[k] * f[n - k]) : M(0)); };

    ll ans = (C(n - x, big) * f[big] * C(x - 1, small) * f[small]) * f[n - (small + big + 1)];

    cout << ans << endl;

    exit(0);
}