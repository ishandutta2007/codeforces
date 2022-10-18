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
/*
mint solve(vector<long long> a, long long l, int mask) {
    int n = (int)a.size();
    mint res = 0;
    for (int k = 0; k < 2; k++) {
        long long s = l;
        for (int i = 0; i < n; i++) {
            if (i % 2 == k) {  // P
                s += a[i];
            } else {  // C
                s -= a[i];
            }
        }
        vector<long long> b;
        b.emplace_back(0);
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 != k) {
                b.emplace_back(b.back() + a[i] * 2);
            }
        }
        if (k == 1) {
            b.pop_back();
        }
        if (mask % 2 == 0) {
            res += b.end() - upper_bound(b.begin(), b.end(), -s);
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == k) {
                b.pop_back();
                if (b.empty()) {
                    break;
                }
                s -= a[i] * 2;
                res += b.end() - upper_bound(b.begin(), b.end(), -s);
                if (mask < 2 && -s < 0) {
                    res -= 1;
                }
            }
        }
        // debug(res);
    }
    return res;
}
*/

mint solve(vector<long long> a, long long l) {
    int n = (int)a.size();
    mint res = 0;
    if (a.empty()) {
        if (l > 0) {
            res = 1;
        }
        return res;
    }
    for (int k = 0; k < 2; k++) {
        long long s = l;
        for (int i = 0; i < n; i++) {
            if (i % 2 == k) {  // P
                s += a[i];
            } else {  // C
                s -= a[i];
            }
        }
        vector<long long> b;
        b.emplace_back(0);
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 != k) {
                b.emplace_back(b.back() + a[i] * 2);
            }
        }
        if (k == 1) {
            b.pop_back();
        }
        res += b.end() - upper_bound(b.begin(), b.end(), -s);
        for (int i = 0; i < n; i++) {
            if (i % 2 == k) {
                b.pop_back();
                if (b.empty()) {
                    break;
                }
                s -= a[i] * 2;
                res += b.end() - upper_bound(b.begin(), b.end(), -s);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        mint ans;
        long long sall = accumulate(a.begin(), a.end(), 0LL);
        long long ssub = a[0];
        for (int i = 1; i < n - 2; i++) {
            ssub += a[i];
            if (ssub > sall - ssub) {
                ans += 1;
            }
        }
        debug(ans);
        for (int mask = 0; mask < 4; mask++) {
            long long l = 0;
            vector<long long> b = a;
            if (mask == 3 && n < 6) {
                continue;
            } else if (mask != 0 && n < 3) {
                continue;
            }
            if (mask & 1) {
                l += a[0];
                l -= a[1];
                l -= a[2];
                b.erase(b.begin());
                b.erase(b.begin());
                b.erase(b.begin());
            }
            if (mask & 2) {
                l -= a[n - 1];
                l += a[n - 2];
                l += a[n - 3];
                b.pop_back();
                b.pop_back();
                b.pop_back();
            }
            ans += solve(b, l);
            debug(ans);
        }
        cout << ans << '\n';
    }
    return 0;
}