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
const long long mod = (long long)1e9 + 7;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(i);
        g[y].emplace_back(i);
        edges[i] = {x, y};
    }
    vector<int> d(n, 1e9);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(d[0], 0);
    while (!pq.empty()) {
        int v = pq.top().second;
        if (pq.top().first != d[v]) {
            pq.pop();
            continue;
        }
        pq.pop();
        for (int id : g[v]) {
            int to = v ^ edges[id].first ^ edges[id].second;
            int cost = 0;
            int tmp = id + 1;
            while (tmp) {
                cost++;
                tmp /= 10;
            }
            if (d[v] + cost < d[to]) {
                d[to] = d[v] + cost;
                pq.emplace(d[to], to);
            }
        }
    }
    vector<vector<int>> ng(n);
    vector<pair<int, int>> nedges;
    vector<int> cost;
    for (int i = 0; i < m; i++) {
        int x, y;
        tie(x, y) = edges[i];
        if (d[x] > d[y]) {
            swap(x, y);
        }
        int c = 0;
        int tmp = i + 1;
        while (tmp) {
            c++;
            tmp /= 10;
        }
        if (d[y] - d[x] != c) {
            continue;
        }
        string s = to_string(i + 1);
        int from = x;
        int to = ng.size();
        for (int j = 0; j < s.size(); j++) {
            if (j == s.size() - 1) {
                to = y;
            } else {
                ng.emplace_back();
            }
            ng[from].emplace_back(nedges.size());
            nedges.emplace_back(from, to);
            cost.emplace_back(s[j] - '0');
            from = to;
            to++;
        }
    }
    swap(g, ng);
    swap(edges, nedges);
    debug(g, edges, cost);
    m = g.size();
    vector<mint> ans(m);
    vector<bool> was(m);
    function<void(vector<int>, mint)> dfs = [&](vector<int> vs, mint val) {
        for (int i : vs) {
            ans[i] = val;
        }
        mint tmp = val;
        vector<vector<int>> nxt(10);
        for (int c = 0; c < 10; c++) {
            for (int v : vs) {
                for (int id : g[v]) {
                    int to = edges[id].second;
                    if (!was[to] && cost[id] == c) {
                        was[to] = true;
                        nxt[c].emplace_back(to);
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            if (nxt[i].empty()) {
                continue;
            }
            dfs(nxt[i], val * 10 + i);
        }
    };
    was[0] = true;
    dfs(vector<int>(1, 0), 0);
    for (int i = 1; i < n; i++) {
        cout << ans[i] << '\n';
    }
    debug(ans);
    return 0;
}