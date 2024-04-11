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
        long long a = 0LL, b = 1LL, c = other.value, m = mod;
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
}
const long long mod = (long long)1e9 + 7;
using mint = modular<mod>;

inline mint pw(mint a, long long n) {
    mint res = 1;
    while (n > 0LL) {
        if (n & 1LL) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}
vector<mint> fact, finv;
inline void cinit(int n) {
    fact.resize(n, mint(1LL));
    finv.resize(n, mint(1LL));
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n - 1] /= fact[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}
inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) {
        return mint(0LL);
    }
    return fact[n] * finv[k] * finv[n - k];
}

struct dsu {
    vector<int> p;
    vector<int> sz;
    vector<int> ok;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        ok.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        ok[x] = ok[y] = ok[x] | ok[y];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline bool eval(int x) {
        return ok[get(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<vector<int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        x[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> x[i][j];
            x[i][j]--;
        }
    }
    dsu uf(m);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (k[i] == 1) {
            if (uf.ok[uf.get(x[i][0])]) {
                continue;
            }
            uf.ok[uf.get(x[i][0])] = 1;
            res.emplace_back(i);
        } else {
            if (uf.same(x[i][0], x[i][1]) || (uf.ok[uf.get(x[i][0])] && uf.ok[uf.get(x[i][1])])) {
                continue;
            }
            uf.unite(x[i][0], x[i][1]);
            res.emplace_back(i);
        }
    }
    mint ans = 1;
    cinit(1000000);
    for (int i = 0; i < m; i++) {
        if (uf.get(i) == i) {
            if (uf.ok[i]) {
                ans *= pw(2, uf.sz[i]);
            } else {
                mint sum = 0;
                for (int j = 0; j <= uf.sz[i]; j += 2) {
                    sum += C(uf.sz[i], j);
                }
                ans *= sum;
            }
        }
    }
    cout << ans << " " << res.size() << '\n';
    for (int i : res) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}