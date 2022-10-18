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

constexpr long long mod = (long long) 1e9 + 7;
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

struct segtree {
    using T = int;
    using F = int;

    T e() {
        return (1 << 30) - 1;
    }

    F id() {
        return (1 << 30) - 1;
    }

    T op(T a, T b) {
        return a & b;
    }

    T mapping(F f, T x) {
        return f & x;
    }

    F composition(F f, F g) {
        return f & g;
    }

    int n;
    vector<T> node;
    vector<F> lazy;

    segtree() : segtree(0) {}
    segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
        lazy.resize(n, id());
    }
    segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
        node.resize(2 * n, e());
        lazy.resize(n, id());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[i * 2], node[i * 2 + 1]);
        }
    }

    void eval(int k) {
        node[2 * k] = mapping(lazy[k], node[2 * k]);
        node[2 * k + 1] = mapping(lazy[k], node[2 * k + 1]);
        if (2 * k < n) {
            lazy[2 * k] = composition(lazy[k], lazy[2 * k]);
            lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
        }
        lazy[k] = id();
    }

    void update(int x, int y, F v, int k, int l, int r) {
        if (y <= l || r <= x) {
            return;
        }
        if (x <= l && r <= y) {
            node[k] = mapping(v, node[k]);
            if (k < n) {
                lazy[k] = composition(v, lazy[k]);
            }
        } else {
            eval(k);
            update(x, y, v, 2 * k, l, (l + r) / 2);
            update(x, y, v, 2 * k + 1, (l + r) / 2, r);
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (y <= l || r <= x) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        eval(k);
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    void update(int x, int y, F v) {
        update(x, y, v, 1, 0, n);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return get(x, x + 1, 1, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        segtree seg(n);
        for (int i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.update(l - 1, r, x);
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = seg.get(i);
        }
        mint ans = 0;
        for (int j = 0; j < 30; j++) {
            int b = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] & (1 << j)) {
                    b++;
                }
            }
            mint t = 0;
            for (int i = 1; i <= b; i += 2) {
                t += C(b, i);
            }
            t *= power(2, n - b + j);
            ans += t;
        }
        cout << ans << '\n';
    }
    return 0;
}