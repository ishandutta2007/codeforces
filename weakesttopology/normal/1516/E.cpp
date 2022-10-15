#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll modpow(ll x, ll p, ll mod) {
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint {
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
    friend istream& operator>>(istream& in, Mint& a) {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};

// N = maximum degree + 1
// T = modular int class
template<typename T, int N>
struct Interpolator {
    T f[N], finv[N];
    Interpolator() {
        f[0] = finv[0] = 1;
        for (int x = 1; x < N; ++x) f[x] = x * f[x - 1], finv[x] = 1 / f[x];
    }
    T interpolate(const vector<T>& y, T x) {
        static T pref[N], suff[N];
        int n = (int)size(y);
        pref[0] = suff[n - 1] = 1;
        for (int i = 0; i + 1 < n; ++i) pref[i + 1] = pref[i] * (x - i);
        for (int i = n - 1; i > 0; --i) suff[i - 1] = suff[i] * (x - i);
        T res = 0;
        for (int i = 0, sgn = (n % 2 ? +1 : -1); i < n; ++i, sgn *= -1) {
            res += sgn * pref[i] * suff[i] * finv[i] * finv[n - 1 - i] * y[i];
        }
        return res;
    }
};

constexpr ll mod = 1e9 + 7;
using mint = Mint<mod>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    constexpr int kmax = 200, degmax = 2 * kmax;
    mint dp[kmax + 1][degmax + 1];

    for (int x = 0; x <= degmax; ++x) dp[0][x] = 1;
    for (int j = 1; j <= k; ++j) {
        mint sum = 0;
        for (int x = 0; x < degmax; ++x) {
            sum += x * dp[j - 1][x];
            dp[j][x + 1] = sum;
        }
    }

    Interpolator<mint, degmax + 1> L;

    vector<mint> W(k + 1, 0);
    for (int j = 0; j <= k; ++j) {
        vector<mint> p;
        for (int x = 0; x <= 2 * j; ++x) p.push_back(dp[j][x]);
        W[j] = L.interpolate(p, n);
        if (j >= 2) W[j] += W[j - 2];
    }

    for (int j = 1; j <= k; ++j) {
        cout << W[j] << "\n "[j < k];
    }

    exit(0);
}