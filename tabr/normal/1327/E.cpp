#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <ll mod>
struct modular {
    ll value;
    modular(ll x = 0) {
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
        ll a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            ll t = m / c;
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
    modular& operator^=(modular other) {
        ll r = 1, x = value, n = other.value;
        while (n > 0) {
            if (n & 1) r = r * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        value = r;
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
    modular operator^(modular rhs) {
        return modular(*this) ^= rhs;
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
template <ll mod>
string to_string(modular<mod> x) {
    return to_string(x.value);
}
template <ll mod>
ostream& operator<<(ostream& stream, modular<mod> x) {
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream << x.value;
}
template <ll mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
const ll mod = 998244353;
using mint = modular<mod>;

vector<mint> fac, finv;
inline void cinit(int n) {
    fac.resize(n, 1);
    finv.resize(n, 1);
    for (int i = 2; i < n; i++) {
        fac[i] = fac[i - 1] * i;
        finv[i] = finv[i - 1] / i;
    }
}
inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}
inline mint H(int n, int k) {
    return C(n + k - 1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<mint> ans;
    ans.emplace_back(10);
    mint t = 1;
    for (int i = n - 1; i > 0; i--) {
        mint res = t * (mint)180;
        res += t * (mint)81 * (mint)(n - i - 1);
        ans.emplace_back(res);
        t *= 10;
    }
    for (mint i : vector<mint>(ans.rbegin(), ans.rend())) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}