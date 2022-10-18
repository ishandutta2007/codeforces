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
    mint operator+(const mint& rhs) const { return mint(*this) += rhs; }
    mint operator-(const mint& rhs) const { return mint(*this) -= rhs; }
    mint operator*(const mint& rhs) const { return mint(*this) *= rhs; }
    mint operator/(const mint& rhs) const { return mint(*this) /= rhs; }
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
    mint operator-() const { return mint(-value); }
    bool operator==(const mint& rhs) const { return value == rhs.value; }
    bool operator!=(const mint& rhs) const { return value != rhs.value; }
    bool operator<(const mint& rhs) const { return value < rhs.value; }
};
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    if (mod == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<mint>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<mint> f(i * (i - 1) / 2 + 1);
        f[0] = 1;
        for (int j = 1; j < i; j++) {
            vector<mint> new_f(i * (i - 1) / 2 + 1);
            mint s = 0;
            for (int k = 0; k < (int) new_f.size(); k++) {
                s += f[k];
                new_f[k] = s;
                if (k - j >= 0) {
                    s -= f[k - j];
                }
            }
            swap(f, new_f);
        }
        dp[i] = f;
    }
    debug(dp);
    vector<vector<mint>> aux = dp;
    for (int i = 0; i <= n; i++) {
        for (int j = (int) dp[i].size() - 1; j > 0; j--) {
            aux[i][j - 1] += aux[i][j];
        }
    }
    vector<mint> b(n + 1);
    for (int i = 2; i <= n; i++) {
        for (int x = 1; x < i; x++) {
            for (int y = 0; y < x; y++) {
                for (int j = 0; j + (x - y) + 1 < (int) dp[i - 1].size(); j++) {
                    b[i] += dp[i - 1][j] * aux[i - 1][j + (x - y) + 1];
                }
            }
        }
    }
    debug(b);
    mint ans = 0;
    vector<mint> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    vector<vector<mint>> C(n + 1, vector<mint>(n + 1));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= n; i++) {
        ans += C[n][i] * fact[i] * b[n - i];
    }
    cout << ans << '\n';
    return 0;
}