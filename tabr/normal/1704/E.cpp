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

vector<int> topsort(const vector<vector<int>>& g) {
    int n = (int) g.size();
    vector<int> deg(n);
    for (int v = 0; v < n; v++) {
        for (int to : g[v]) {
            deg[to]++;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            res.emplace_back(i);
        }
    }
    for (int i = 0; i < (int) res.size(); i++) {
        int v = res[i];
        for (int to : g[v]) {
            if (--deg[to] == 0) {
                res.emplace_back(to);
            }
        }
    }
    if ((int) res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> f(n), g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            f[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        if (*max_element(a.begin(), a.end()) == 0) {
            cout << 0 << '\n';
            continue;
        }
        auto c = topsort(f);
        const int inf = (int) 1e7;
        vector<vector<tuple<int, mint, int>>> dp(n);
        for (int v : c) {
            if (a[v] > 0) {
                dp[v].emplace_back(-1, a[v], min(inf, a[v]));
            }
            vector<tuple<int, mint, int>> nxt;
            sort(dp[v].begin(), dp[v].end());
            for (auto [time, mcnt, cnt] : dp[v]) {
                if (nxt.empty()) {
                    nxt.emplace_back(time + 1, mcnt, cnt);
                    continue;
                }
                auto& [ptime, pmcnt, pcnt] = nxt.back();
                if (ptime + pcnt > time) {
                    pmcnt += mcnt;
                    pcnt += cnt;
                    pcnt = min(pcnt, inf);
                } else {
                    nxt.emplace_back(time + 1, mcnt, cnt);
                }
            }
            debug(v, nxt);
            if (v == c.back()) {
                auto [time, cnt, _] = nxt.back();
                cout << cnt + time << '\n';
                break;
            }
            for (int to : f[v]) {
                for (auto t : nxt) {
                    dp[to].emplace_back(t);
                }
            }
        }
    }
    return 0;
}