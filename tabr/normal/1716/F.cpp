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
    modular& operator+=(const modular& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(const modular& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(const modular& other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(const modular& other) {
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
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) {
        modular res(*this);
        *this += 1;
        return res;
    }
    modular operator--(int) {
        modular res(*this);
        *this -= 1;
        return res;
    }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

constexpr long long mod = 998244353;
using mint = modular<mod>;

mint power(mint a, long long n) {
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

vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
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
    vector<vector<mint>> dp(2022, vector<mint>(2022));
    dp[0][0] = 1;
    for (int i = 1; i < 2022; i++) {
        for (int j = 1; j < 2022; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
        }
    }
    C(2022, 0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        mint p = mint((m + 1) / 2) / m;
        mint ans = 0;
        mint t = 1;
        for (int i = 1; i <= min(n, k); i++) {
            t *= n + 1 - i;
            t /= i;
            ans += dp[k][i] * fact[i] * t * power(p, i);
        }
        ans *= power(m, n);
        cout << ans << '\n';
    }
    return 0;
}