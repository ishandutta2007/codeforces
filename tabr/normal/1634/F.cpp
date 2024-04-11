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
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
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
    int n, q;
    cin >> n >> q >> mod;
    vector<mint> c(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[i] += a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        c[i] -= b;
    }
    vector<mint> f(n + 10);
    f[0] = f[1] = 1;
    for (int i = 2; i < n + 10; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    vector<mint> d(max(0, n - 2));  // d[i] == c[i + 2] - c[i + 1] - c[i]
    int nonzero = 0;
    for (int i = 0; i < n - 2; i++) {
        d[i] = c[i + 2] - c[i + 1] - c[i];
        if (d[i] != 0) {
            nonzero++;
        }
    }
    while (q--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        l--;
        int sgn = 1;
        if (op == 'B') {
            sgn = -1;
        }
        if (l == 0) {
            c[0] += sgn;
        }
        if (n == 1) {
            if (c[0] == 0) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            continue;
        }
        if (l <= 1 && r > 1) {
            c[1] += sgn;
        }
        if (n >= 3) {
            if (l + 1 == r) {
                for (int i = l - 2; i <= l; i++) {
                    if (i < 0 || i >= n - 2) {
                        continue;
                    }
                    if (d[i] != 0) {
                        nonzero--;
                    }
                    if (i == l - 2) {
                        d[i] += sgn;
                    } else {
                        d[i] -= sgn;
                    }
                    if (d[i] != 0) {
                        nonzero++;
                    }
                }
            } else {
                if (l - 2 >= 0) {
                    if (d[l - 2] != 0) {
                        nonzero--;
                    }
                    d[l - 2] += f[0] * sgn;
                    if (d[l - 2] != 0) {
                        nonzero++;
                    }
                }
                if (r - 2 >= 0 && r < n) {
                    if (d[r - 2] != 0) {
                        nonzero--;
                    }
                    d[r - 2] -= f[r - l] * sgn;
                    if (d[r - 2] != 0) {
                        nonzero++;
                    }
                }
                if (r + 1 < n) {
                    if (d[r - 1] != 0) {
                        nonzero--;
                    }
                    d[r - 1] -= f[r - l - 1] * sgn;
                    if (d[r - 1] != 0) {
                        nonzero++;
                    }
                }
            }
        }
        if (c[0] == 0 && c[1] == 0 && nonzero == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}