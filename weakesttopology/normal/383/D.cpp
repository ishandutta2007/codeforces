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
    friend ostream& operator<<(ostream& out, const Mint& a) { out << a.x; return out; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

int main()
{ _
    constexpr int MOD = 1e9 + 7;
    using M = Mint<MOD>;

    int n; cin >> n;

    const int K = 1e4;

    auto id = [&K](int x) { return K + x; };

    vector dp(2, vector(2 * K + 1, M(0)));

    int b = 0;

    dp[b][id(0)] = M(1);

    M ans = M(0);

    for (int i = 0; i < n; ++i, b ^= 1)
    {
        int a; cin >> a;

        ans += dp[b][id(a)] + dp[b][id(-a)];

        for (int x = -K; x <= K; ++x) if (dp[b][id(x)].x != 0)
        {
             dp[b ^ 1][id(x + a)] += dp[b][id(x)];
             dp[b ^ 1][id(x - a)] += dp[b][id(x)];
        }

        dp[b ^ 1][id(0)] += M(1);

        fill(all(dp[b]), M(0));
    }

    debug(dp[b][id(0)]);

    cout << ans << endl;

    exit(0);
}