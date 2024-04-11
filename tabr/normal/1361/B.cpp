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
};
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

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, p;
        scanf("%d%d", &n, &p);
        int k[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &k[i]);
        }
        if (p == 1) {
            cout << n % 2 << '\n';
            continue;
        }
        sort(k, k + n, greater<int>());
        mint ans = 0;
        ll cur = 0;
        mint cp = pw(p, k[0]);
        mint rp = mint(1) / mint(p);
        int ck = k[0];
        bool inf = false;
        for (int i = 0; i < n; i++) {
            cp *= pw(rp, ck - k[i]);
            ck = k[i];
            if (inf) {
                ans -= cp;
            } else {
                if (cur == 0) {
                    cur++;
                    ans += cp;
                } else {
                    if (k[i - 1] - k[i] > 20) {
                        inf = true;
                    } else if (k[i] != k[i - 1]) {
                        for (int j = k[i]; j < k[i - 1]; j++) {
                            if (cur * p > n) {
                                inf = true;
                                break;
                            }
                            cur *= p;
                        }
                    }
                    cur--;
                    ans -= cp;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}