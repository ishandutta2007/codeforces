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
    bool operator!=(const Mint& rhs) const { return x != rhs.x; }
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

int main()
{ _
    const int mod = 998244353;
    using Mi = Mint<mod>;

    int n, m; cin >> n >> m;

    vector<int> w(n), a(n);
    int sum = 0, sum_good = 0;

    for (auto& x : a) cin >> x;

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
        sum += w[i];
        if (a[i]) sum_good += w[i];
    }

    constexpr int wmax = 100;
    int sum_max = sum + m, sz = (wmax + 1) * (sum_max + 1);

    for (int i = 0; i < n; ++i)
    {
        vector<Mi> dp__(sz, 0), dpnxt__(sz, 0);
        auto dp = (Mi(*)[wmax + 1])(&dp__[0]);
        auto dpnxt = (Mi(*)[wmax + 1])(&dpnxt__[0]);

        int sum_good_excluded = sum_good - a[i] * w[i];

        dp[sum_good_excluded][w[i]] = 1;

        int dir = a[i] ? +1 : -1;

        for (int j = 0; j < m; ++j)
        {
            for (int s = sum_good_excluded; s <= sum_good_excluded + j; ++s)
            {
                for (int x = 1; x < wmax; ++x)
                {
                    int diff_good = (s + a[i] * x) - sum_good;
                    int total_weight = sum + 2 * diff_good - j;

                    // probability of drawing i
                    Mi p = Mi(x) / total_weight;

                    // probability of drawnig a good one != i
                    Mi q = Mi(s) / total_weight;

                    // probability of drwaing a bad one != i
                    Mi r = 1 - (p + q);

                    dpnxt[s][x + dir] += p * dp[s][x];
                    dpnxt[s + 1][x] += q * dp[s][x];
                    dpnxt[s][x] += r * dp[s][x];
                }
            }
            swap(dp, dpnxt), swap(dp__, dpnxt__);
            fill(all(dpnxt__), Mi(0));
        }

        Mi ans = 0;

        for (int s = 0; s <= sum_max; ++s)
            for (int x = 1; x <= wmax; ++x)
                ans += x * dp[s][x];

        cout << ans << "\n "[i + 1 < n];
    }

    exit(0);
}