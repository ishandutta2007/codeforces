#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<ll mod>
struct Mint {
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { return (x += rhs.x) >= mod ? x -= mod : 0, *this; }
    Mint& operator-=(Mint rhs) { return (x -= rhs.x) < 0 ? x += mod : 0, *this; }
    Mint& operator*=(Mint rhs) { return (x *= rhs.x) %= mod, *this; }
    Mint& operator/=(Mint rhs) { return *this *= rhs.power(-1); }
    Mint power(ll p) const {
        p %= mod - 1;
        if (p < 0) p += mod - 1;
        Mint res = 1;
        for (Mint y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
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
constexpr ll mod = 998244353;
using mint = Mint<mod>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(begin(a), end(a));
    if (2 * a[n - 2] > a[n - 1]) {
        cout << 0 << endl;
        exit(0);
    }
    vector<mint> f(n + 1), inv(n + 1);
    f[0] = inv[0] = 1;
    for (int k = 1; k <= n; ++k) {
        f[k] = k * f[k - 1];
        inv[k] = 1 / f[k];
    }
    auto C = [&](int n, int k){ return k > n ? 0 : f[n] * inv[k] * inv[n - k]; };
    vector<mint> dp(n);
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = (int)(upper_bound(begin(a), begin(a) + i, a[i] / 2) - begin(a));
        for (int j = 0; j < s[i]; ++j) {
            dp[i] += dp[j] * C(n - 1 - (s[j] + 1), s[i] - (s[j] + 1)) * f[s[i] - (s[j] + 1)];
        }
        dp[i] += C(n - 1, s[i]) * f[s[i]];
    }
    cout << dp[n - 1] << endl;
    exit(0);
}