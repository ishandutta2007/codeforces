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

constexpr long long mod = (long long) 1e9 + 7;
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

void slow(int n, int m, int k) {
#ifndef tabr
    return;
#endif
    vector<vector<mint>> dp(m + 1, vector<mint>(n - m + 1));
    mint inv2 = 1 / mint(2);
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n - m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv2;
        }
    }
    cout << "ans: " << dp[m][n - m] * k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int MAX = (int) 2e6 + 20;
    fact.resize(MAX);
    finv.resize(MAX);
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[MAX - 1] = 1 / fact[MAX - 1];
    for (int i = MAX - 2; i >= 1; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
    vector<mint> p2(MAX);
    p2[0] = 1;
    for (int i = 1; i < MAX; i++) {
        p2[i] = p2[i - 1] + p2[i - 1];
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == m) {
            cout << mint(m) * k << '\n';
            continue;
        }
        mint ans = 0;
        for (int i = 1; i <= m; i++) {
            int h = m - i + 1;
            int w = n - m;
            ans += i * C(h + w - 2, h - 1) / p2[h + w - 1];
        }
        cout << ans * k << '\n';
        slow(n, m, k);
    }
    return 0;
}