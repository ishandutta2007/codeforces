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

int main()
{ _
    constexpr ll mod = 998244353;
    using mint = Mint<mod>;

    int n;
    cin >> n;

    vector<int> l(n), r(n), pts;

    for (int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
        pts.insert(end(pts), { l[i], r[i], r[i] + 1 });
    }

    reverse(all(l)), reverse(all(r));

    sort(all(pts)), pts.erase(unique(all(pts)), end(pts));
    int m = size(pts);
    pts.push_back(pts.back() + 1);

    debug(m);

    vector<mint> inv(n + 1, 1);
    for (int x = 1; x <= n; ++x) inv[x] = inv[x - 1] / x;

    // combinations with repetition
    auto Cr = [&inv](int n, int k)
    {
        mint res = inv[k];
        for (int x = 0; x < k; ++x) res *= n + x;
        return res;
    };
    // probability that sequence is sorted
    auto Pr = [&Cr](int n, int k)
    {
        mint res = Cr(n, k) / mint(n).power(k);
        return res;
    };

    constexpr int nmax = 50, mmax = 3 * nmax;
    // dp[i][j] = probability that:
    //              * problem i falls on an interval from [0, ..., j]
    //              * prefix [0, ..., i] is sorted
    mint dp[nmax][mmax], p[nmax][mmax];

    for (int i = 0; i < n; ++i)
    {
        mint inv_len = 1 / mint(r[i] - l[i] + 1);
        for (int j = 0; j < m; ++j) if (clamp(pts[j], l[i], r[i]) == pts[j])
        {
            int cap = max(0, min(pts[j + 1], r[i] + 1) - max(pts[j], l[i]));

            p[i][j] = cap * inv_len;
        }
    }

    mint prefix = 1;
    for (int i = 0; i < n; ++i)
    {
        prefix *= p[i][0];
        dp[i][0] = prefix * Pr(pts[1] - pts[0], i + 1);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            int len = pts[j + 1] - pts[j];
            mint q = 1;
            for (int k = i; k >= 0; --k)
            {
                q *= p[k][j];
                dp[i][j] += q * Pr(len, i - k + 1) * (k ? dp[k - 1][j - 1] : 1);
            }
            dp[i][j] += dp[i][j - 1];
        }
    }

    mint ans = dp[n - 1][m - 1];

    cout << ans << endl;

    exit(0);
}