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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y] = 1;
    }
    vector<int> x(h), y(w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            x[i] += a[i][j];
            y[j] += a[i][j];
        }
    }
    vector<int> p, q;
    for (int i = 0; i < h; i++) {
        if (x[i]) {
            continue;
        }
        for (int j = i; j <= h; j++) {
            if (j == h || x[j]) {
                p.emplace_back(j - i);
                i = j;
                break;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        if (y[i]) {
            continue;
        }
        for (int j = i; j <= w; j++) {
            if (j == w || y[j]) {
                q.emplace_back(j - i);
                i = j;
                break;
            }
        }
    }
    debug(p, q);
    int s = accumulate(p.begin(), p.end(), 0);
    int t = accumulate(q.begin(), q.end(), 0);
    vector<vector<mint>> f(s + 1, vector<mint>(s));
    vector<vector<mint>> g(t + 1, vector<mint>(t));
    if (s == 0 || t == 0) {
        cout << 1 << '\n';
        return 0;
    }
    for (int lp = 0; lp < 2; lp++) {
        vector<mint> d(s);
        vector<int> pp = p;
        for (int i = 0; i < (int)pp.size() - 1; i++) {
            pp[i + 1] += pp[i];
        }
        for (int i = 0; i < s; i++) {
            if (i >= 2) {
                for (int j = 0; j < s; j++) {
                    d[j] += f[i - 1][j];
                }
            } else if (i == 1) {
                d[0] = 1;
            }
            if (binary_search(pp.begin(), pp.end(), i)) {
                continue;
            }
            for (int j = 0; j < s - 1; j++) {
                f[i + 1][j + 1] += d[j];
            }
        }
        d[0] = 1;
        for (int i = s - 1; i <= s; i++) {
            for (int j = 0; j < s; j++) {
                d[j] += f[i][j];
            }
        }
        swap(f[s], d);
        swap(p, q);
        swap(s, t);
        swap(f, g);
    }
    mint ans = 0;
    C(s + t, 0);
    debug(f[s]);
    debug(g[t]);
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < t; j++) {
            ans += f[s][i] * g[t][j] * C(t - 2 * j, i) * C(s - 2 * i, j) * fact[i] * fact[j];
        }
    }
    cout << ans << '\n';
    return 0;
}