#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
        return *this;
    }
    modular operator-() { return modular(-value); }
    modular operator+(modular rhs) { return modular(*this) += rhs; }
    modular operator-(modular rhs) { return modular(*this) -= rhs; }
    modular operator*(modular rhs) { return modular(*this) *= rhs; }
    modular operator/(modular rhs) { return modular(*this) /= rhs; }
    bool operator==(modular rhs) { return value == rhs.value; }
    bool operator!=(modular rhs) { return value != rhs.value; }
    bool operator<(modular rhs) { return value < rhs.value; }
};
template <long long mod>
string to_string(modular<mod> x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, modular<mod> x) {
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
const long long mod = 998244353LL;
using mint = modular<mod>;

inline mint pw(mint a, long long n) {
    mint res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}
vector<mint> fact(1, 1), finv(1, 1);
inline mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int) fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int) fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector dp(n + 1, vector<mint>(4));
    vector s(n + 1, vector<mint>(4));
    dp[0][0] = 1;
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        mint x = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = x;
        if (i > 1) {
            dp[i][2] = x * (s[i - 2][0] + s[i - 2][1] + s[i - 2][2]);
        }
        dp[i][2] += x * (x + 1) / 2;
        for (int j = 0; j < 4; j++) {
            s[i][j] = s[i - 1][j] + dp[i][j];
        }
    }
    mint x = dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2];
    mint ans = x * (x - 1) * (x - 2) / 6 + x * (x - 1) + x;
    mint t = 0;
    if (n >= 2) {
        t = s[n - 2][0] + s[n - 2][1] + s[n - 2][2];
    }
    ans += x * (x + 1) / 2 * t;
    ans += x * t * (t + 1) / 2;
    ans *= 2;
    ans += dp[n][1];
    ans += dp[n][2] * 2;
    for (int k = 1; k < n; k++) {
        ans += dp[k][1] * dp[n - k][2];
    }
    cout << ans << '\n';
    return 0;
}