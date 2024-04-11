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
const long long mod = 998244353;
using mint = modular<mod>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<mint> p(n + 1), ml(n + 1, 1), s(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] *= 828542813;  // inv(100)
        ml[i] = ml[i - 1] * p[i];
        s[i] = s[i - 1] + ml[i];
    }
    set<int> st;
    st.emplace(0);
    st.emplace(n);
    auto eval = [&](int l, int r) {
        mint res = s[r - 1] - (l ? s[l - 1] : 0);
        res /= ml[r];
        return res;
    };
    mint ans = eval(0, n);
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        u--;
        int r = *st.upper_bound(u);
        int l = *(--st.lower_bound(u));
        mint t = eval(l, u) + eval(u, r) - eval(l, r);
        if (st.count(u)) {
            ans -= t;
            st.erase(u);
        } else {
            ans += t;
            st.emplace(u);
        }
        cout << ans << '\n';
    }
    return 0;
}