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
const long long mod = 998244353LL;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int k = 21;
    vector<vector<int>> g(n * k);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        for (int j = 0; j < k; j++) {
            if (j % 2 == 0) {
                g[x + n * j].emplace_back(y + n * j);
            } else {
                g[y + n * j].emplace_back(x + n * j);
            }
        }
    }
    int inf = 1e9;
    vector<int> d(n * k, inf);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        int v = pq.top().second;
        int cc = pq.top().first;
        pq.pop();
        if (cc != d[v]) {
            continue;
        }
        for (int to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                pq.emplace(d[to], to);
            }
        }
        if (v < n * (k - 1) && d[v + n] > d[v] + (1 << (v / n))) {
            d[v + n] = d[v] + (1 << (v / n));
            pq.emplace(d[v + n], v + n);
        }
    }
    int ans = inf;
    for (int i = 0; i < k; i++) {
        ans = min(ans, d[i * n + n - 1]);
    }
    // debug(d);
    if (ans != inf) {
        cout << ans << '\n';
        return 0;
    }
    vector<pair<int, int>> p(n * 2, make_pair(inf, inf));
    p[0] = {0, 0};
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pp;
    pp.emplace(make_pair(0, 0), 0);
    while (!pp.empty()) {
        int v = pp.top().second;
        auto q = pp.top().first;
        pp.pop();
        if (q != p[v]) {
            continue;
        }
        for (int to : g[v]) {
            auto c = p[v];
            c.second++;
            if (c < p[to]) {
                p[to] = c;
                pp.emplace(p[to], to);
            }
        }
        auto c = p[v];
        c.first++;
        int to = v ^ (v % n) ^ (v % n + n);
        if (c < p[to]) {
            p[to] = c;
            pp.emplace(p[to], to);
        }
    }
    auto c = min(p[n - 1], p[2 * n - 1]);
    debug(p);
    mint ns = pw(2, c.first) + c.second - 1;
    cout << ns << '\n';
    return 0;
}