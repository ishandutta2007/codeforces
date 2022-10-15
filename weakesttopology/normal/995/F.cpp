#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T, int N>
struct Combinatorics {
    Combinatorics() = delete;
    inline static T f[N], inv[N];
    static void build() {
        f[0] = inv[0] = 1;
        for (int x = 1; x < N; ++x) f[x] = x * f[x - 1], inv[x] = 1 / f[x];
    }
    static T interpolate(const vector<T>& y, T x) {
        static T pref[N], suff[N];
        int n = (int)size(y);
        pref[0] = suff[n - 1] = 1;
        for (int i = 0; i + 1 < n; ++i) pref[i + 1] = pref[i] * (x - i);
        for (int i = n - 1; i > 0; --i) suff[i - 1] = suff[i] * (x - i);
        T res = 0;
        for (int i = 0, sgn = (n % 2 ? +1 : -1); i < n; ++i, sgn *= -1) {
            res += y[i] * sgn * pref[i] * suff[i] * inv[i] * inv[n - 1 - i];
        }
        return res;
    }
    static T C(int n, int k) {
        return k < 0 || n < k ? 0 : f[n] * inv[k] * inv[n - k];
    }
    static T S(int n, int k) {
        return k == 0 ? n == 0 : C(n + k - 1, k - 1);
    }
};
template<ll mod>
struct Mint {
    ll x;
    Mint() : x(0) {}
    Mint(ll x_) {
        x = x_ % mod;
        if (x < 0) x += mod;
    }
    Mint& operator+=(Mint rhs) {
        x += rhs.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    Mint& operator-=(Mint rhs) {
        x -= rhs.x;
        if (x < 0) x += mod;
        return *this;
    }
    Mint& operator*=(Mint rhs) {
        x = x * rhs.x % mod;
        return *this;
    }
    Mint& operator/=(Mint rhs) {
        return *this *= rhs.power(-1);
    }
    Mint power(ll p) const {
        p %= mod - 1;
        if (p < 0) p += mod - 1;
        Mint res = 1;
        for (Mint y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    Mint operator-() const {
        return Mint() - *this;
    }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator!=(Mint rhs) const { return x != rhs.x; }
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
    inline static const Mint X = [](){
        uniform_int_distribution<ll> unif(1, mod - 1);
        mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using mint = Mint<1'000'000'007>;
using C = Combinatorics<mint, 100'000>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    C::build();
    int n, D;
    cin >> n >> D;
    vector<int> p(n);
    for (int u = 1; u < n; ++u) {
        cin >> p[u];
        --p[u];
    }
    int deg = n;
    vector<vector<mint>> dp(n, vector<mint>(deg + 1, 1));
    for (int v = n - 1; v >= 0; --v) {
        partial_sum(begin(dp[v]), end(dp[v]), begin(dp[v]));
        if (v) {
            for (int x = 0; x <= deg; ++x) {
                dp[p[v]][x] *= dp[v][x];
            }
        }
    }
    --D;
    mint ans = C::interpolate(dp[0], D);
    cout << ans << '\n';
    exit(0);
}