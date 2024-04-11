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
    while ((int)fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int)fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> a(h, vector<bool>(w));
    int n = 0;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'o') {
                n++;
                a[i][j] = true;
            }
        }
    }
    if (n <= 1) {
        cout << 0 << '\n';
        return 0;
    }
    mint ans = 0;
    vector<mint> p2(n + 10);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    vector<mint> dp(n + 10);
    dp[1] = p2[n - 2];
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 2];
        if (i % 2 == 0) {
            dp[i] += p2[n - (i + 1)];
        } else {
            dp[i] -= p2[n - (i - 1)];
            dp[i] += p2[n - i];
            dp[i] += p2[n - (i + 1)];
        }
    }
    for (int i = 0; i < h; i++) {
        int x = 0;
        for (int j = 0; j < w; j++) {
            if (a[i][j]) {
                ans += dp[x];
                x++;
            } else {
                x = 0;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        int x = 0;
        for (int i = 0; i < h; i++) {
            if (a[i][j]) {
                ans += dp[x];
                x++;
            } else {
                x = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}