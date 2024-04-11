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
const long long mod = (long long)1e9 + 7;
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
    while ((int)fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int)fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

mint bigC(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    mint res = 1;
    C(k, 0);
    res *= finv[k];
    for (int i = n - k + 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<mint> dp(k + 1);
    dp[0] = 1;
    for (int x = 1; x <= k; x++) {
        for (int y = 1; y <= x; y++) {
            mint t = bigC(n, x + y);
            vector<vector<mint>> f(x + y + 1, vector<mint>(y + 1));
            f[1][1] = 1;
            for (int i = 1; i < x + y; i++) {
                for (int j = 1; j <= y; j++) {
                    if (j < y) {
                        f[i + 1][j + 1] += f[i][j];
                    }
                    f[i + 1][j] += f[i][j] * i;
                }
            }
            for (int i = 0; i <= y; i++) {
                mint s = t * f[x + y - i][y - i] * C(x + y, i);
                if (i % 2) {
                    s *= -1;
                }
                dp[x] += s;
            }
        }
        if (x != 1) {
            dp[x] += dp[x - 2];
        }
        cout << dp[x] << " ";
    }
    cout << '\n';
    return 0;
}