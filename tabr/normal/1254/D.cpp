#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
};
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
vector<mint> fact, finv;
inline void cinit(int n) {
    fact.resize(n, 1);
    finv.resize(n, 1);
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n - 1] /= fact[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}
inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fact[n] * finv[k] * finv[n - k];
}

template <class T>
struct fenwick {
    vector<T> node;
    int n;
    fenwick(int _n)
        : n(_n) {
        node.resize(n);
    }
    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }
    T get(int x) {
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    T get(int a, int b) {  // [a, b]
        return get(b) - (a ? get(a - 1) : 0);
    }
    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> order, a(n), b(n), sz(n, 1), pv(n, -1), depth(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        pv[v] = p;
        a[v] = order.size();
        order.emplace_back(v);
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            depth[to] = depth[v] + 1;
            dfs(to, v);
            sz[v] += sz[to];
        }
        b[v] = order.size();
    };
    dfs(0, -1);
    int h = 18;
    vector<vector<int>> p(n, vector<int>(h, -1));
    for (int i = 0; i < n; i++) {
        p[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
        for (int i = 0; i < n; i++) {
            if (p[i][j - 1] == -1) {
                continue;
            }
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    int heavy = 300;
    vector<int> hv;
    for (int i = 0; i < n; i++) {
        if (g[i].size() >= heavy) {
            hv.emplace_back(i);
        }
    }
    fenwick<mint> bit(n + 2);
    vector<mint> x(n);
    mint inv_n = mint(1) / n;
    while (q--) {
        int c;
        cin >> c;
        int v;
        cin >> v;
        v--;
        if (c == 1) {
            mint d;
            cin >> d;
            if (g[v].size() < heavy) {
                for (int to : g[v]) {
                    if (to == pv[v]) {
                        continue;
                    }
                    mint val = d * (n - sz[to]) * inv_n;
                    bit.add(a[to], val);
                    bit.add(b[to], -val);
                }
                mint val = d * sz[v] * inv_n;
                bit.add(0, val);
                bit.add(a[v], d - val);
                bit.add(a[v] + 1, -d);
                bit.add(b[v], val);
            } else {
                x[v] += d;
            }
        } else {
            mint res = bit.get(a[v]);
            for (int i : hv) {
                mint val = x[i] * inv_n;
                int u = v;
                if (depth[i] < depth[u]) {
                    for (int j = h - 1; j >= 0; j--) {
                        if (p[u][j] != -1 && depth[u] - depth[i] > (1 << j)) {
                            u = p[u][j];
                        }
                    }
                }
                if (i == u) {
                    val *= n;
                } else if (i != pv[u]) {
                    val *= sz[i];
                } else {
                    val *= n - sz[u];
                }
                res += val;
            }
            cout << res << '\n';
        }
    }
    return 0;
}