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

constexpr long long mod = (int) 1e9 + 7;
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

struct sieve {
    vector<int> primes;
    vector<bool> is_prime;
    vector<int> min_factor;

    sieve(int MAX = 1 << 20) {
        is_prime = vector<bool>(MAX, true);
        min_factor = vector<int>(MAX);
        is_prime[0] = is_prime[1] = false;
        min_factor[0] = min_factor[1] = 1;
        for (int i = 2; i < MAX; i++) {
            if (!is_prime[i]) {
                continue;
            }
            primes.emplace_back(i);
            min_factor[i] = i;
            if ((long long) i * i >= MAX) {
                continue;
            }
            for (int j = i * i; j < MAX; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    min_factor[j] = i;
                }
            }
        }
    }

    vector<pair<int, int>> factor(int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int p = min_factor[n];
            res.emplace_back(p, 0);
            while (p == min_factor[n]) {
                n /= p;
                res.back().second++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> divisor(int n) {
        vector<int> res(1, 1);
        for (const auto& p : factor(n)) {
            for (int i = (int) res.size() - 1; i >= 0; i--) {
                int c = res[i];
                for (int j = 0; j < p.second; j++) {
                    c *= p.first;
                    res.emplace_back(c);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    vector<int> mu_table() {
        vector<int> res(min_factor.size());
        for (int i = 1; i < (int) min_factor.size(); i++) {
            if (i == 1) {
                res[i] = 1;
            } else if ((i / min_factor[i]) % min_factor[i] == 0) {
                res[i] = 0;
            } else {
                res[i] = -res[i / min_factor[i]];
            }
        }
        return res;
    }

    // zeta: add
    // mobius: subtract
    // zeta <-> mobius
    template <typename T>
    void divisor_zeta(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = 1; p * i < n; i++) {
                a[p * i] += a[i];
            }
        }
    }

    template <typename T>
    void divisor_mobius(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = (n - 1) / p; i >= 1; i--) {
                a[p * i] -= a[i];
            }
        }
    }

    template <typename T>
    void multiple_zeta(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = (n - 1) / p; i >= 1; i--) {
                a[i] += a[p * i];
            }
        }
    }

    template <typename T>
    void multiple_mobius(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = 1; p * i < n; i++) {
                a[i] -= a[p * i];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve z(1 << 20);
    int n;
    cin >> n;
    vector<mint> h(n + 1);
    iota(h.begin(), h.end(), 0);
    z.divisor_mobius(h);
    vector<mint> f(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j : z.divisor(i)) {
            f[i] += h[j] * (i / j - 1);
        }
    }
    vector<mint> dp(n / 3 + 1);
    for (int g = 1; 3 * g <= n; g++) {
        if (n % g) {
            continue;
        }
        for (int c = g; c <= n - 2 * g; c += g) {
            dp[g] += f[(n - c) / g] * c * g;
        }
    }
    z.multiple_mobius(dp);
    mint ans = 0;
    for (int i = 1; i <= n / 3; i++) {
        ans += dp[i] / i;
    }
    cout << ans << '\n';
    return 0;
}