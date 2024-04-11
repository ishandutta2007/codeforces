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
const ll mod = 1e9 + 7;
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
    int n, m;
    cin >> n >> m;
    vector<int> s(n), all(n), sum(n);
    vector<vector<int>> c(n);
    vector<mint> res(n + 1);
    vector<bool> ok(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
        all[s[i]]++;
    }
    res[0] = 1;
    ok[0] = true;
    for (int i = 0; i < m; i++) {
        int f, h;
        cin >> f >> h;
        f--;
        c[f].emplace_back(h);
    }
    for (int i = 0; i < n; i++) {
        sort(c[i].begin(), c[i].end());
    }
    for (int i = 0; i < n; i++) {
        int cnt = 1, f = s[i];
        mint tmp = 1;
        sum[f]++;
        if (!binary_search(c[f].begin(), c[f].end(), sum[f])) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (f == j) {
                int r = all[j] - sum[j];
                int t = upper_bound(c[j].begin(), c[j].end(), r) - c[j].begin();
                if (sum[j] <= r) {
                    t--;
                }
                if (t) {
                    tmp *= t;
                    cnt++;
                }
            } else {
                int l = sum[j], r = all[j] - sum[j];
                int t = upper_bound(c[j].begin(), c[j].end(), l) - c[j].begin();
                int u = upper_bound(c[j].begin(), c[j].end(), r) - c[j].begin();
                if (t > u && u) {
                    t--;
                } else if (u > t && t) {
                    u--;
                } else if (t == u) {
                    if (t > 1) {
                        t--;
                    } else if (t == 1) {
                        t = 2, u = 0;
                    }
                }
                if (t > 0) {
                    tmp *= t;
                    cnt++;
                }
                if (u > 0) {
                    tmp *= u;
                    cnt++;
                }
            }
        }
        ok[cnt] = true;
        res[cnt] += tmp;
    }
    int cnt = 0;
    mint tmp = 1;
    for (int j = 0; j < n; j++) {
        if (c[j].size()) {
            int t = upper_bound(c[j].begin(), c[j].end(), all[j]) - c[j].begin();
            if (t) {
                tmp *= t;
                cnt++;
            }
        }
    }
    ok[cnt] = true;
    res[cnt] += tmp;
    res[0] = 1;
    for (int i = n; i >= 0; i--) {
        if (ok[i]) {
            cout << i << " " << res[i] << endl;
            break;
        }
    }
    return 0;
}