#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

long long mod = 2;

struct mint {
    long long value;
    mint(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    mint& operator+=(const mint& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    mint& operator-=(const mint& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    mint& operator*=(const mint& other) {
        value = value * other.value % mod;
        return *this;
    }
    mint& operator/=(const mint& other) {
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
    mint operator+(const mint& rhs) { return mint(*this) += rhs; }
    mint operator-(const mint& rhs) { return mint(*this) -= rhs; }
    mint operator*(const mint& rhs) { return mint(*this) *= rhs; }
    mint operator/(const mint& rhs) { return mint(*this) /= rhs; }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    mint operator++(int) {
        mint result(*this);
        *this += 1;
        return result;
    }
    mint operator--(int) {
        mint result(*this);
        *this -= 1;
        return result;
    }
    mint operator-() { return mint(-value); }
    bool operator==(const mint& rhs) { return value == rhs.value; }
    bool operator!=(const mint& rhs) { return value != rhs.value; }
    bool operator<(const mint& rhs) { return value < rhs.value; }
};
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
string to_string(const mint& x) {
    return to_string(x.value);
}
ostream& operator<<(ostream& stream, const mint& x) {
    return stream << x.value;
}
istream& operator>>(istream& stream, mint& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
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
    int n;
    cin >> n >> mod;
    vector<mint> p(n + 1);
    p[0] = p[1] = 1;
    C(n, 0);
    for (int i = 2; i <= n; i++) {
        p[i] = p[i - 1] * 2;
    }
    for (int i = 1; i <= n; i++) {
        p[i] /= fact[i];
    }
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
    dp[0][0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= n; k++) {
                if (i + k + 1 < n) {
                    dp[i + k + 1][j + 1] += dp[i][j] * p[k];
                } else if (i + k + 1 == n + 1) {
                    dp[n][j] += dp[i][j] * p[k];
                }
            }
        }
    }
    mint ans = 0;
    for (int j = 0; j <= n; j++) {
        ans += dp[n][j] * fact[n - j];
    }
    cout << ans << '\n';
    return 0;
}