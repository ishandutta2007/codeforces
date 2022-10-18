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
    int n, m;
    cin >> n >> m;
    vector<string> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    map<string, int> mp;
    vector<string> s;
    auto get = [&](string x) {
        if (!mp.count(x)) {
            mp[x] = (int)s.size();
            s.emplace_back(x);
        }
        return mp[x];
    };
    get("");
    vector<vector<int>> e;
    for (int i = 0; i < n; i++) {
        e.push_back({0, 0, (int)w[i].size()});
        for (int j = i + 1; j < n; j++) {
            string x = w[i];
            string y = w[j];
            if (x.size() < y.size()) {
                swap(x, y);
            }
            if (y == x.substr(0, y.size())) {
                string t = x.substr(y.size());
                e.push_back({0, get(t), (int)y.size()});
            }
        }
    }
    for (int i = 1; i < (int)s.size(); i++) {
        for (int j = 0; j < n; j++) {
            string x = s[i];
            string y = w[j];
            if (x.size() < y.size()) {
                swap(x, y);
            }
            if (y == x.substr(0, y.size())) {
                string t = x.substr(y.size());
                e.push_back({i, get(t), (int)y.size()});
            }
        }
    }
    int sz = (int)s.size();
    vector<vector<mint>> z(sz * 5, vector<mint>(sz * 5));
    sort(e.begin(), e.end());
    for (auto v : e) {
        int to = v[1] + sz * v[2];
        int from = v[0];
        while (to < sz * 5) {
            to += sz;
            from += sz;
        }
        z[to - sz][from] += 1 + (v[0] % sz == 0 && v[1] % sz != 0);
    }
    for (int i = 0; i < sz * 4; i++) {
        z[i][i + sz] += 1;
    }
    vector<vector<mint>> c(sz * 5, vector<mint>(sz * 5));
    for (int i = 0; i < sz * 5; i++) {
        c[i][i] = 1;
    }
    auto mul = [&](vector<vector<mint>> p, vector<vector<mint>> q) {
        vector<vector<mint>> r(sz * 5, vector<mint>(sz * 5));
        for (int i = 0; i < sz * 5; i++) {
            for (int j = 0; j < sz * 5; j++) {
                for (int k = 0; k < sz * 5; k++) {
                    r[i][j] += p[i][k] * q[k][j];
                }
            }
        }
        return r;
    };
    vector<mint> u(sz * 5);
    u[sz * 4] = 1;
    for (int i = 0; i < 4; i++) {
        for (auto v : e) {
            int to = v[1] + sz * (v[2] + i);
            if (to < sz * 5) {
                u[to] += u[v[0] + i * sz];
            }
        }
    }
    debug(s);
    debug(u);
    // debug(z);
    vector<mint> v(sz * 5);
    for (int i = 0; i < sz * 5; i++) {
        for (int j = 0; j < sz * 5; j++) {
            v[i] += z[i][j] * u[j];
        }
    }
    debug(v);
    // m++;
    while (m) {
        if (m & 1) {
            c = mul(c, z);
        }
        z = mul(z, z);
        m >>= 1;
    }
    mint ans = 0;
    // for (int i = 0; i < sz * 5; i++) {
    //     ans += c[0][i] * u[i];
    // }
    ans = c[4 * sz][4 * sz];
    cout << ans << '\n';
    return 0;
}