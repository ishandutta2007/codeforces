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
    modular operator+(const modular& rhs) { return modular(*this) += rhs; }
    modular operator-(const modular& rhs) { return modular(*this) -= rhs; }
    modular operator*(const modular& rhs) { return modular(*this) *= rhs; }
    modular operator/(const modular& rhs) { return modular(*this) /= rhs; }
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
    modular operator-() { return modular(-value); }
    bool operator==(const modular& rhs) { return value == rhs.value; }
    bool operator!=(const modular& rhs) { return value != rhs.value; }
    bool operator<(const modular& rhs) { return value < rhs.value; }
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

constexpr long long mod = 998244353LL;
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
    const int MAX = 100010;
    vector<int> primes;
    vector<int> spf(MAX);
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
        primes.emplace_back(i);
        spf[i] = i;
        if (1LL * i * i >= MAX) {
            continue;
        }
        for (int j = i * i; j < MAX; j += i) {
            if (is_prime[j]) {
                is_prime[j] = false;
                spf[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    vector<long long> f(MAX);
    vector<mint> s(MAX);
    vector<mint> t(MAX);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cin >> f[a];
        s[a] = mint(f[a]) * a;
        t[a] = mint(f[a]) * a * a;
    }
    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = (MAX - 1) / i; j >= 1; j--) {
            f[j] += f[j * i];
            s[j] += s[j * i];
            t[j] += t[j * i];
        }
    }
    vector<mint> dp(MAX);
    for (int i = 1; i < MAX; i++) {
        mint p = power(2, f[i] - 3) * f[i];
        mint q = power(2, f[i] - 2) * (f[i] - 1);
        if (f[i] == 2) {
            p = 1;
        }
        s[i] *= s[i];
        s[i] -= t[i];
        dp[i] = p * s[i] + q * t[i];
        if (i == 1) {
            debug(s[i], t[i], p, q);
        }
    }
    debug(dp[1], dp[2], dp[3], dp[6]);
    for (int i = MAX - 1; i >= 2; i--) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = 1; i * j < MAX; j++) {
            dp[j] -= dp[i * j];
        }
    }
    cout << dp[1] << '\n';
    /*
    s *= s;
    s -= t;
    debug(s, t);
    mint p = 0, q = 0;
    long long m = accumulate(f.begin(), f.end(), 0LL);
    q = power(2, m - 2) * (m - 1);
    p = power(2, m - 3) * (m);
    debug(p, q);
    cout << p * s + q * t << '\n';
    */
    return 0;
}