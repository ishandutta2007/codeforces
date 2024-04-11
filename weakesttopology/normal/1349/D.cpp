#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
using mint = Mint<998244353>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int T = accumulate(begin(a), end(a), 0);
    if (T == 1) {
        cout << "0\n";
        exit(0);
    }
    vector<array<mint, 2>> dp(T + 1);
    dp[0] = {n - 1, 1};
    dp[1] = {0, 1};
    for (int x = 1; x < T; ++x) {
        mint coef[2] = {mint(x) / T, (1 - mint(x) / T) * mint(n - 2) / (n - 1) - 1};
        for (int t : {0, 1}) {
            for (int s : {0, 1}) {
                dp[x + 1][s] += coef[t] * dp[x - 1 + t][s];
            }
        }
        dp[x + 1][0] += 1;
        if (x < T) {
            for (int t : {0, 1}) {
                dp[x + 1][t] *= -(n - 1) / (1 - coef[0]);
            }
        }
    }
    vector<mint> E(T + 1);
    E[1] = -dp[T][0] / dp[T][1];
    E[0] = E[1] + n - 1;
    for (int x = 1; x < T; ++x) {
        mint coef[2] = {mint(x) / T, (1 - mint(x) / T) * mint(n - 2) / mint(n - 1) - 1};
        E[x + 1] = 1;
        for (int t : {0, 1}) {
            E[x + 1] += coef[t] * E[x - 1 + t];
        }
        E[x + 1] *= -(n - 1) / (1 - coef[0]);
    }
    mint S = 0;
    for (int i = 0; i < n; ++i) {
        S += E[a[i]];
    }
    mint ans = (n * S - mint(n) * (n - 1) * E[0]) / n / n;
    cout << ans << endl;
    exit(0);
}