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

template <typename T>
struct fenwick {
    int n;
    vector<T> node;

    fenwick(int _n) : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
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
    int n, k;
    cin >> n >> k;
    vector<mint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        g[x].emplace_back(y, t);
        g[y].emplace_back(x, t);
    }
    vector<int> used(n);
    mint ans = 0;
    vector<int> sz(n);
    vector<int> pv(n, -1);
    while (accumulate(used.begin(), used.end(), 0) < n) {
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            int c = -1;
            vector<int> s;
            auto find_centroid = [&](auto&& self, int v) -> void {
                s.emplace_back(v);
                sz[v] = 1;
                for (auto [to, t] : g[v]) {
                    if (to == pv[v] || used[to]) {
                        continue;
                    }
                    pv[to] = v;
                    self(self, to);
                    sz[v] += sz[to];
                }
            };
            pv[i] = -1;
            find_centroid(find_centroid, i);
            for (int v : s) {
                if (sz[i] - sz[v] <= sz[i] / 2) {
                    int mx = 0;
                    for (auto [to, t] : g[v]) {
                        if (to == pv[v] || used[to]) {
                            continue;
                        }
                        mx = max(mx, sz[to]);
                    }
                    if (mx <= sz[i] / 2) {
                        c = v;
                    }
                }
            }
            assert(c != -1);
            vector<vector<vector<pair<int, mint>>>> b(2);
            int bx = -1, by = -1;
            auto dfs = [&](auto&& self, int v, int p, int pre, int sw, mint sa) -> void {
                sa += a[v];
                if (v != c) {
                    b[bx][by].emplace_back(sw, sa);
                }
                if (sw <= k) {
                    ans += sa;
                }
                for (auto [to, t] : g[v]) {
                    if (to == p || used[to]) {
                        continue;
                    }
                    if (v == c) {
                        bx = t;
                        by = (int) b[bx].size();
                        b[bx].emplace_back(vector<pair<int, mint>>());
                        self(self, to, v, t, 0, sa);
                    } else {
                        self(self, to, v, t, sw + (pre != t), sa);
                    }
                }
            };
            dfs(dfs, c, -1, -1, 0, mint(0));
            debug(ans);
            used[c] = 1;
            for (int _ = 0; _ < 2; _++) {
                fenwick<mint> ft(sz[i]);
                fenwick<int> gt(sz[i]);
                for (auto v : b[_]) {
                    for (auto [x, y] : v) {
                        if (x <= k) {
                            ans += ft.get(min(sz[i] - 1, k - x));
                            ans += (y - a[c]) * gt.get(min(sz[i] - 1, k - x));
                        }
                    }
                    for (auto [x, y] : v) {
                        ft.add(x, y);
                        gt.add(x, 1);
                    }
                }
                if (!_) {
                    for (auto v : b[1]) {
                        for (auto [x, y] : v) {
                            if (x <= k - 1) {
                                ans += ft.get(min(sz[i] - 1, k - 1 - x));
                                ans += (y - a[c]) * gt.get(min(sz[i] - 1, k - 1 - x));
                            }
                        }
                    }
                }
            }
            debug(c, b, ans);
        }
    }
    cout << ans << '\n';
    return 0;
}