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
    modular(long long x = 0LL) {
        value = x % mod;
        if (value < 0LL) value += mod;
    }
    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0LL) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
        long long a = 0LL, b = 1, c = other.value, m = mod;
        while (c != 0LL) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0LL) a += mod;
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
    if (x.value < 0LL) x.value += mod;
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0LL) x.value += mod;
    return stream;
};
const long long mod = 998244353LL;
using mint = modular<mod>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string sc;
    cin >> sc;
    vector<int> c(n + 1);
    set<int> no;
    no.emplace(-1);
    vector<mint> one(n + 1, 1);
    one[1] = 2;
    for (int i = 2; i <= n; i++) {
        one[i] = one[i - 1] * 2 + one[i - 2] * 8;
    }
    auto get = [&](int l, int d) {
        if (d == 1) {
            return mint(1);
        }
        if (l == 0) {
            return mint(d + 1);
        }
        return one[l] * (d + 1) + one[l - 1] * (9 - d);
    };
    c[n] = 9;
    mint res = 1;
    vector<mint> a(n + 1, 1);
    for (int i = 0, j = -1; i <= n; i++) {
        if (i != n) {
            c[i] = sc[i] - '0';
        }
        if (c[i] != 1) {
            no.emplace(i);
            res /= a[i];
            a[i] = get(i - j - 1, c[i]);
            res *= a[i];
            j = i;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, d;
        cin >> x >> d;
        x--;
        c[x] = d;
        int y = *prev(no.lower_bound(x));
        if (c[x] == 1) {
            no.erase(x);
        } else {
            no.emplace(x);
        }
        res /= a[x];
        a[x] = get(x - y - 1, c[x]);
        res *= a[x];
        x = *no.upper_bound(x);
        y = *prev(no.find(x));
        res /= a[x];
        a[x] = get(x - y - 1, c[x]);
        res *= a[x];
        cout << res / mint(10) << '\n';
    }
    return 0;
}