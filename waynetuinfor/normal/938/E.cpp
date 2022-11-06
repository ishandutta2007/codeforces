#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
int a[maxn];

struct modint {
    int v;
    modint();
    modint(int);
    modint operator+(const modint &) const;
    modint operator-(const modint &) const;
    modint operator*(const modint &) const;
    modint operator/(const modint &) const;
    modint operator+(const int &) const;
    modint operator-(const int &) const;
    modint operator*(const int &) const;
    modint operator/(const int &) const;
    modint &operator+=(const modint &);
    modint &operator-=(const modint &);
    modint &operator*=(const modint &);
    modint &operator/=(const modint &);
    modint &operator+=(const int &);
    modint &operator-=(const int &);
    modint &operator*=(const int &);
    modint &operator/=(const int &);
    modint &operator=(const modint &);
    modint &operator=(const int &);
};

modint fpow(modint a, int n) {
    modint ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

modint::modint() { v = 0; }
modint::modint(int v) { this->v = v; }
modint modint::operator+(const modint &m) const { return modint(v + m.v >= mod ? v + m.v - mod : v + m.v); }
modint modint::operator+(const int &m) const { return modint(v + m >= mod ? v + m - mod : v + m); }
modint& modint::operator+=(const modint &m) { v += m.v; if (v >= mod) v -= mod; return *this; }
modint& modint::operator+=(const int &m) { v += m; if (v >= mod) v -= mod; return *this; }
modint modint::operator-(const modint &m) const { return modint(v - m.v < 0 ? v - m.v + mod : v - m.v); }
modint modint::operator-(const int &m) const { return modint(v - m < 0 ? v - m + mod : v - m); }
modint& modint::operator-=(const modint &m) { v -= m.v; if (v < 0) v += mod; return *this; }
modint& modint::operator-=(const int &m) { v -= m; if (v < 0) v += mod; return *this; }
modint modint::operator*(const modint &m) const { return modint(v * 1ll * m.v % mod); }
modint modint::operator*(const int &m) const { return modint(v * 1ll * m % mod); }
modint& modint::operator*=(const modint &m) { v = v * 1ll * m.v % mod; return *this; }
modint& modint::operator*=(const int &m) { v = v * 1ll * m % mod; return *this; }
modint modint::operator/(const modint &m) const { return operator*(modint(fpow(m, mod - 2))); }
modint modint::operator/(const int &m) const { return operator*(modint(fpow(modint(m), mod - 2))); }
modint& modint::operator/=(const modint &m) { (v *= 1ll * fpow(m, mod - 2).v) %= mod; return *this; }
modint& modint::operator/=(const int &m) { v = v * 1ll * fpow(modint(m), mod - 2).v % mod; return *this; }
modint& modint::operator=(const modint &m) { v = m.v; }
modint& modint::operator=(const int &m) { v = m; }
ostream &operator<<(ostream &s, const modint &m) { return s << m.v; }
istream &operator>>(istream &s, modint &m) { return s >> m.v; }

modint f[maxn], pf[maxn], invf[maxn];

void init() {
    f[0] = 1; pf[0] = 1; invf[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = f[i - 1] * i, pf[i] = pf[i - 1] * f[i], invf[i] = fpow(f[i], mod - 2);
}

modint C(int n, int k) { return n < k ? 0 : f[n] * invf[k] * invf[n - k]; }

int main() {
    init();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int stop = *max_element(a, a + n);
    modint ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == stop) continue;
        int prv = lower_bound(a, a + n, a[i]) - a;
        // cout << "a[i] = " << a[i] << " prv = " << prv << endl;
        ans += f[n] / (n - prv) * a[i];
        // cout << "ans = " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}