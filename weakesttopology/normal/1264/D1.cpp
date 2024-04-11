#include <bits/stdc++.h>
using namespace std;
template<long long mod>
struct Mint {
    long long x;
    Mint() : x(0) {}
    Mint(long long x_) {
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
    Mint power(long long p) const {
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
        long long x;
        in >> x;
        a = Mint(x);
        return in;
    }
    inline static const Mint X = [](){
        uniform_int_distribution<long long> unif(1, mod - 1);
        mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using mint = Mint<998244353>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)size(s);
    map<char, array<mint, 2>> coef;
    coef['('] = {1, 0};
    coef[')'] = {0, 1};
    coef['?'] = {1/mint(2), 1/mint(2)};
    vector<vector<mint>> pref(n), suff(n);
    vector<mint> dp(n + 1);
    dp[0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        suff[i].resize(n + 1);
        vector<mint> ndp(n + 1);
        for (int k = 0; k < n; ++k) {
            for (int t : {0, 1}) {
                mint P = coef[s[i]][t] * dp[k];
                ndp[k + t] += P;
                if (t == 1) suff[i][k + t] += P;
            }
        }
        swap(dp, ndp);
    }
    swap(coef['('], coef[')']);
    fill(begin(dp), end(dp), 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        pref[i].resize(n + 1);
        vector<mint> ndp(n + 1);
        for (int k = 0; k < n; ++k) {
            for (int t : {0, 1}) {
                mint P = coef[s[i]][t] * dp[k];
                ndp[k + t] += P;
                if (t == 1) pref[i][k + t] += P;
            }
        }
        swap(dp, ndp);
    }
    vector<mint> sum(n), prob(n);
    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            ans += sum[k] * suff[i][k];
            sum[k] += pref[i][k];
        }
    }
    ans *= mint(2).power(count(begin(s), end(s), '?'));
    cout << ans << '\n';
    exit(0);
}