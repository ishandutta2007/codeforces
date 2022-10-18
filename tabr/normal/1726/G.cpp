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

namespace st0 {
struct segtree {
    using T = pair<int, int>;
    using F = int;

    T e() {
        return make_pair((int) 1e9, -1);
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return min(a, b);
    }

    T mapping(F f, T x) {
        x.first += f;
        return x;
    }

    F composition(F f, F g) {
        return f + g;
    }

    int n;
    int size;
    int log_size;
    vector<T> node;
    vector<F> lazy;

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
            log_size = 0;
        } else {
            log_size = 32 - __builtin_clz(n - 1);
        }
        size = 1 << log_size;
        node.resize(2 * size, e());
        lazy.resize(size, id());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            pull(i);
        }
    }

    void push(int x) {
        node[2 * x] = mapping(lazy[x], node[2 * x]);
        node[2 * x + 1] = mapping(lazy[x], node[2 * x + 1]);
        if (2 * x < size) {
            lazy[2 * x] = composition(lazy[x], lazy[2 * x]);
            lazy[2 * x + 1] = composition(lazy[x], lazy[2 * x + 1]);
        }
        lazy[x] = id();
    }

    void pull(int x) {
        node[x] = op(node[2 * x], node[2 * x + 1]);
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = v;
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    T get(int p) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        return node[p];
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        T vl = e();
        T vr = e();
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

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = mapping(f, node[p]);
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        int ll = l;
        int rr = r;
        while (l < r) {
            if (l & 1) {
                node[l] = mapping(f, node[l]);
                if (l < size) {
                    lazy[l] = composition(f, lazy[l]);
                }
                l++;
            }
            if (r & 1) {
                r--;
                node[r] = mapping(f, node[r]);
                if (l < size) {
                    lazy[r] = composition(f, lazy[r]);
                }
            }
            l >>= 1;
            r >>= 1;
        }
        l = ll;
        r = rr;
        for (int i = 1; i <= log_size; i++) {
            if (((l >> i) << i) != l) {
                pull(l >> i);
            }
            if (((r >> i) << i) != r) {
                pull((r - 1) >> i);
            }
        }
    }
};
}  // namespace st0

namespace st1 {
struct segtree {
    using T = pair<int, int>;
    using F = int;

    T e() {
        return make_pair((int) -1e9, -1);
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return max(a, b);
    }

    T mapping(F f, T x) {
        x.first += f;
        return x;
    }

    F composition(F f, F g) {
        return f + g;
    }

    int n;
    int size;
    int log_size;
    vector<T> node;
    vector<F> lazy;

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
            log_size = 0;
        } else {
            log_size = 32 - __builtin_clz(n - 1);
        }
        size = 1 << log_size;
        node.resize(2 * size, e());
        lazy.resize(size, id());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            pull(i);
        }
    }

    void push(int x) {
        node[2 * x] = mapping(lazy[x], node[2 * x]);
        node[2 * x + 1] = mapping(lazy[x], node[2 * x + 1]);
        if (2 * x < size) {
            lazy[2 * x] = composition(lazy[x], lazy[2 * x]);
            lazy[2 * x + 1] = composition(lazy[x], lazy[2 * x + 1]);
        }
        lazy[x] = id();
    }

    void pull(int x) {
        node[x] = op(node[2 * x], node[2 * x + 1]);
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = v;
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    T get(int p) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        return node[p];
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        T vl = e();
        T vr = e();
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

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = mapping(f, node[p]);
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        int ll = l;
        int rr = r;
        while (l < r) {
            if (l & 1) {
                node[l] = mapping(f, node[l]);
                if (l < size) {
                    lazy[l] = composition(f, lazy[l]);
                }
                l++;
            }
            if (r & 1) {
                r--;
                node[r] = mapping(f, node[r]);
                if (l < size) {
                    lazy[r] = composition(f, lazy[r]);
                }
            }
            l >>= 1;
            r >>= 1;
        }
        l = ll;
        r = rr;
        for (int i = 1; i <= log_size; i++) {
            if (((l >> i) << i) != l) {
                pull(l >> i);
            }
            if (((r >> i) << i) != r) {
                pull((r - 1) >> i);
            }
        }
    }
};
}  // namespace st1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i].second;
    }
    sort(c.begin(), c.end());
    int k = c[0].first;
    if (c[0].second == 1) {
        k += (int) (c.end() - upper_bound(c.begin(), c.end(), c[0]));
    }
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        if (c[i].first > k) {
            cout << 0 << '\n';
            return 0;
        }
        cnt[c[i]]++;
    }
    C(n, 0);
    mint ans = 1;
    for (auto [x, y] : cnt) {
        if (x.second == 1 && x.first != k && y > 1) {
            cout << 0 << '\n';
            return 0;
        } else {
            ans *= fact[y];
        }
    }
    ans *= C(n, cnt[make_pair(k, 1)]);
    vector<vector<int>> d(2);
    vector<int> e(n);
    vector<pair<int, int>> s0, s1;
    int tt = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == make_pair(k, 1)) {
            break;
        }
        tt++;
        if (c[i].second == 0) {
            e[i] = (int) d[0].size();
            d[0].emplace_back(c[i].first);
            int t = (int) (lower_bound(c.begin(), c.end(), make_pair(c[i].first, -1)) - c.begin());
            t += c[i].first;
            s0.emplace_back(t, i);
        } else {
            e[i] = (int) d[1].size();
            d[1].emplace_back(c[i].first);
            int t = (int) (c.end() - lower_bound(c.begin(), c.end(), make_pair(c[i].first + 1, -1)));
            t += c[i].first;
            s1.emplace_back(t, i);
        }
    }
    st0::segtree seg0(s0);
    st1::segtree seg1(s1);
    while (tt--) {
        auto t0 = seg0.node[1];
        auto t1 = seg1.node[1];
        debug(t0, t1);
        if (t0.first != k && t1.first != k) {
            cout << 0 << '\n';
            return 0;
        }
        int id = -1;
        if (t0.first != k) {
            id = t1.second;
        } else if (t1.first != k) {
            id = t0.second;
        } else {
            id = max(t0.second, t1.second);
        }
        if (id == -1) {
            cout << 0 << '\n';
            return 0;
        }
        if (c[id].second == 0) {
            seg0.set(e[id], seg0.e());
        } else {
            seg1.set(e[id], seg1.e());
        }
        int x = (int) (upper_bound(d[0].begin(), d[0].end(), c[id].first) - d[0].begin());
        seg0.apply(x, (int) d[0].size(), -1);
        int y = (int) (upper_bound(d[1].begin(), d[1].end(), c[id].first) - d[1].begin());
        seg1.apply(y, (int) d[1].size(), 1);
    }
    cout << ans << '\n';
    return 0;
}