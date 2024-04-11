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
    using T = mint;

    T e() {
        return 1;
    }

    T op(T x, T y) {
        return x * y;
    }

    int n;
    int size;
    vector<T> node;

    segtree() : segtree(0) {}
    segtree(int _n) {
        build(vector<T>(_n, e()));
    }
    segtree(const vector<T>& v) {
        build(v);
    }

    void build(const vector<T>& v) {
        n = (int) v.size();
        if (n <= 1) {
            size = n;
        } else {
            size = 1 << (32 - __builtin_clz(n - 1));
        }
        node.resize(2 * size, e());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        node[p] = v;  // update
        // node[p] += v;  // add
        while (p > 1) {
            p >>= 1;
            node[p] = op(node[2 * p], node[2 * p + 1]);
        }
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        T vl = e();
        T vr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) {
                vl = op(vl, node[l++]);
            }
            if (r & 1) {
                vr = op(node[--r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

    T get(int p) {
        assert(0 <= p && p < n);
        return node[p + size];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(l.begin(), l.end());
    sort(p.begin(), p.end());
    vector<vector<long long>> a(m, vector<long long>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = abs(p[i] - l[j]);
        }
    }
    vector<segtree> seg;
    for (int i = 0; i < m; i++) {
        vector<mint> b(a[i].begin(), a[i].end());
        seg.emplace_back(b);
    }
    vector<mint> dp(1 << m);
    dp.back() = power(d + 1, n);
    for (int mask = 0; mask < (1 << m) - 1; mask++) {
        vector<int> c;
        for (int i = 0; i < m; i++) {
            if (~mask & (1 << i)) {
                c.emplace_back(i);
            }
        }
        int sz = (int) c.size();
        vector<int> t;
        t.emplace_back(0);
        for (int i = 0; i < sz - 1; i++) {
            int low = -1;
            int high = n;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (abs(l[mid] - p[c[i]]) >= abs(l[mid] - p[c[i + 1]])) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            t.emplace_back(high);
        }
        t.emplace_back(n);
        debug(t, c);
        dp[mask] = 1;
        for (int i = 0; i < sz; i++) {
            dp[mask] *= seg[c[i]].get(t[i], t[i + 1]);
        }
    }
    for (int bit = 0; bit < m; bit++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (mask & (1 << bit)) {
                dp[mask] -= dp[mask ^ (1 << bit)];
            }
        }
    }
    vector<vector<mint>> c(m, vector<mint>(m));
    for (int i = 0; i < (1 << m) - 1; i++) {
        int x = -1, y = -1;
        for (int j = 0; j < m; j++) {
            if (~i & (1 << j)) {
                if (x == -1) {
                    x = j;
                }
                y = j;
            }
        }
        c[x][y] += dp[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int f;
        cin >> f;
        mint ans = dp.back() * (d + 1);
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                ans += c[i][j] * (d - max(abs(p[i] - f), abs(p[j] - f)) + 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}