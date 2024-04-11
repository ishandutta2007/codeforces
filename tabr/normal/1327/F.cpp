#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    modular operator+(modular rhs) {
        return modular(*this) += rhs;
    }
    modular operator-(modular rhs) {
        return modular(*this) -= rhs;
    }
    modular operator*(modular rhs) {
        return modular(*this) *= rhs;
    }
    modular operator/(modular rhs) {
        return modular(*this) /= rhs;
    }
    bool operator==(modular rhs) {
        return value == rhs.value;
    };
    bool operator!=(modular rhs) {
        return value != rhs.value;
    };
    bool operator<(modular rhs) {
        return value < rhs.value;
    }
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
const long long mod = 998244353;
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
vector<mint> fact, finv;
inline void cinit(int n) {
    fact.resize(n, 1);
    finv.resize(n, 1);
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n - 1] /= fact[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}
inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fact[n] * finv[k] * finv[n - k];
}
inline mint H(int n, int k) {
    return C(n + k - 1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> l(m), r(m), x(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> x[i];
        l[i]--, r[i]--;
    }
    mint ans = 1;
    for (int c = 0; c < k; c++) {
        vector<int> b(n + 1), pos(n + 1, -1);
        vector<mint> sum(n + 1);
        for (int i = 0; i < m; i++) {
            if (x[i] & (1 << c)) {
                b[l[i]]++;
                b[r[i] + 1]--;
            } else {
                pos[r[i]] = max(pos[r[i]], l[i]);
            }
        }
        int j = -1;
        for (int i = 0; i < n; i++) {
            mint t;
            if (!b[i]) {
                t = sum[i];
                if (j == -1) {
                    t += 1;
                } else {
                    t -= sum[j];
                }
            }
            b[i + 1] += b[i];
            sum[i + 1] = sum[i] + t;
            j = max(j, pos[i]);
        }
        if (j == -1) {
            sum[n] += 1;
        } else {
            sum[n] -= sum[j];
        }
        ans *= sum[n];
    }
    cout << ans << endl;
    return 0;
}