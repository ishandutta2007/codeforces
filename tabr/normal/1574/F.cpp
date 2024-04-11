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
    modular& operator+=(const modular& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(const modular& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(const modular& other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(const modular& other) {
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
    modular operator+(const modular& rhs) const { return modular(*this) += rhs; }
    modular operator-(const modular& rhs) const { return modular(*this) -= rhs; }
    modular operator*(const modular& rhs) const { return modular(*this) *= rhs; }
    modular operator/(const modular& rhs) const { return modular(*this) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) {
        modular res(*this);
        *this += 1;
        return res;
    }
    modular operator--(int) {
        modular res(*this);
        *this -= 1;
        return res;
    }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

constexpr long long mod = 998244353;
using mint = modular<mod>;

mint power(mint a, long long n) {
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

vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int) fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int) fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
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
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

mint root;
int base;
int max_base;
vector<mint> roots;
vector<int> rev;

void ensure_base(int nbase) {
    if (roots.empty()) {
        auto tmp = mod - 1;
        max_base = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            max_base++;
        }
        root = 2;
        while (power(root, (mod - 1) >> 1) == 1) {
            root += 1;
        }
        root = power(root, (mod - 1) >> max_base);
        base = 1;
        rev = {0, 1};
        roots = {0, 1};
    }
    if (nbase <= base) {
        return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
        mint z = power(root, 1 << (max_base - 1 - base));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            roots[i << 1] = roots[i];
            roots[(i << 1) + 1] = roots[i] * z;
        }
        base++;
    }
}

void ntt(vector<mint>& a) {
    int n = (int) a.size();
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                mint x = a[i + j];
                mint y = a[i + j + k] * roots[j + k];
                a[i + j] = x + y;
                a[i + j + k] = x - y;
            }
        }
    }
}

vector<mint> multiply(vector<mint> a, vector<mint> b) {
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) {
        nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    ntt(a);
    ntt(b);
    mint inv = mint(1) / mint(sz);
    for (int i = 0; i < sz; i++) {
        a[i] *= b[i] * inv;
    }
    reverse(a.begin() + 1, a.end());
    ntt(a);
    a.resize(need);
    return a;
}

vector<mint>& operator*=(vector<mint>& a, const vector<mint>& b) {
    if (min(a.size(), b.size()) < 150) {
        vector<mint> c = a;
        a.assign(a.size() + b.size() - 1, 0);
        for (int i = 0; i < (int) c.size(); i++) {
            for (int j = 0; j < (int) b.size(); j++) {
                a[i + j] += c[i] * b[j];
            }
        }
    } else {
        a = multiply(a, b);
    }
    return a;
}

template <typename T>
vector<T> operator*(const vector<T>& a, const vector<T>& b) {
    vector<T> c = a;
    return c *= b;
}

template <typename T>
vector<T> inverse(const vector<T>& a) {
    vector<T> h(a);
    int n = (int) h.size();
    T invh0 = T(1) / h[0];
    vector<T> u(1, invh0);
    while ((int) u.size() < n) {
        int t = (int) u.size();
        vector<T> h0;
        for (int i = 0; i < t; i++) {
            h0.emplace_back(i < (int) h.size() ? h[i] : 0);
        }
        vector<T> c = h0 * u;
        vector<T> h1;
        for (int i = t; i < 2 * t; i++) {
            h1.emplace_back(i < (int) h.size() ? h[i] : 0);
        }
        vector<T> aux = u * h1;
        aux.resize(t);
        for (int i = 0; i < t; i++) {
            aux[i] += (i + t < (int) c.size() ? c[i + t] : 0);
        }
        vector<T> v = aux * u;
        v.resize(t);
        for (int i = 0; i < t; i++) {
            u.emplace_back(-v[i]);
        }
    }
    u.resize(n);
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        vector<int> b(c);
        for (int j = 0; j < c; j++) {
            cin >> b[j];
            b[j]--;
        }
        a.emplace_back(b);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = (int) a.size();
    vector<int> nxt(k, -1), pre(k, 0);
    dsu uf(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int) a[i].size() - 1; j++) {
            uf.unite(a[i][j], a[i][j + 1]);
            if (nxt[a[i][j]] != a[i][j + 1]) {
                if (nxt[a[i][j]] == -1) {
                    nxt[a[i][j]] = a[i][j + 1];
                    pre[a[i][j + 1]]++;
                } else {
                    uf.unite(a[i][j], k);
                }
            }
        }
    }
    vector<mint> b(m + 1);
    for (int i = 0; i < k; i++) {
        if (uf.same(i, k) || pre[i]) {
            continue;
        }
        vector<int> c;
        c.emplace_back(i);
        int now = i;
        while (nxt[now] != -1) {
            c.emplace_back(nxt[now]);
            now = nxt[now];
            if (pre[now] != 1) {
                c.clear();
                break;
            }
        }
        if ((int) c.size() == uf.sz[uf.get(i)] && (int) c.size() <= m) {
            b[c.size()]++;
        } else {
            uf.unite(i, k);
        }
    }
    debug(b);
    vector<mint> c(m + 1);
    c[0] = 1;
    for (int i = 1; i <= m; i++) {
        c[i] = -b[i];
    }
    c = inverse(c);
    b *= c;
    cout << b[m] << '\n';
    return 0;
}