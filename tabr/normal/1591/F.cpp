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
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
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

struct segtree {
    using T = pair<int, mint>;
    using F = pair<int, mint>;

    T e() {
        return make_pair(0, 0);
    }

    F id() {
        return make_pair(0, 0);
    }

    T op(T a, T b) {
        a.first += b.first;
        a.second += b.second;
        return a;
    }

    T mapping(F f, T x) {
        if (f.first) {
            x.second = 0;
        }
        x.second += x.first * f.second;
        return x;
    }

    F composition(F f, F g) {
        if (f.first) {
            g.first = 1;
            g.second = 0;
        }
        g.second += f.second;
        return g;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;
    b.emplace_back(0);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    vector<pair<int, mint>> ss;
    for (int i = 1; i < (int) b.size(); i++) {
        ss.emplace_back(b[i] - b[i - 1], 0);
    }
    segtree seg(ss);
    for (int i = 0; i < n; i++) {
        int c = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        if (i == 0) {
            seg.update(0, c, make_pair(0, mint(1)));
        } else if (a[i - 1] <= a[i]) {
            seg.update(0, c, make_pair(0, -seg.node[1].second));
        } else {
            seg.update(0, c, make_pair(0, -seg.node[1].second));
            seg.update(c, (int) ss.size(), make_pair(1, mint(0)));
        }
    }
    mint ans = seg.node[1].second;
    if (n % 2 == 0) {
        ans = -ans;
    }
    cout << ans << '\n';
    return 0;
}