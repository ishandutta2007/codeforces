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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long s = accumulate(a.begin(), a.end(), 0LL);
    if (s % n != 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<long long> b;
    vector<long long> c;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > s / n) {
            b.emplace_back(a[i]);
        } else if (a[i] < s / n) {
            c.emplace_back(a[i]);
        } else {
            d++;
        }
    }
    mint ans = C(n, d);
    if (1 == (int)min(b.size(), c.size())) {
        b.insert(b.end(), c.begin(), c.end());
        c.clear();
        ans /= 2;
    } else if (b.empty() && c.empty()) {
        cout << 1 << '\n';
        return 0;
    }
    for (auto v : {b, c}) {
        map<long long, int> mp;
        for (auto i : v) {
            mp[i]++;
        }
        d = 0;
        for (auto [k, u] : mp) {
            d += u;
            ans *= C(d, u);
        }
    }
    cout << ans * 2 << '\n';
    return 0;
}