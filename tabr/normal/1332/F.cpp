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
inline mint H(int n, int k) {
    return C(n + k - 1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    // vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(3, vector<mint>(2, 1)));
    vector<vector<mint>> dp(n, vector<mint>(3, 1));
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) continue;
            dfs(to, v);
            /*
            dp[v][0][0] *= dp[to][0][0] * (mint)2 + dp[to][0][1] + dp[to][1][0] * (mint)2 + dp[to][1][1] + dp[to][2][0];
            dp[v][1][0] *= dp[to][0][0] * (mint)2 + dp[to][0][1] + dp[to][2][0] + dp[to][1][0];
            dp[v][2][0] *= dp[to][0][0] + dp[to][1][0] + dp[to][2][0];
            dp[v][0][1] *= dp[to][2][0] + dp[to][0][0] + dp[to][1][0];
            dp[v][1][1] *= dp[to][2][0] + dp[to][0][0] + dp[to][1][0];
            */
            dp[v][0] *= dp[to][0] * 2 + dp[to][1] * 2 + dp[to][2] * 3;
            dp[v][1] *= dp[to][0] * 2 + dp[to][1] + dp[to][2] * 2;
            dp[v][2] *= dp[to][0] + dp[to][1] + dp[to][2];
        }
        dp[v][0] -= dp[v][2];
        dp[v][1] -= dp[v][2];
        /*
        dp[v][0][0] -= dp[v][0][1];
        dp[v][1][0] -= dp[v][1][1];
        */
    };
    dfs(0, -1);
    debug(dp);
    // mint ans = dp[0][0][0] + dp[0][1][0] + dp[0][2][0] - 1;
    mint ans = dp[0][0] + dp[0][1] + dp[0][2] - 1;
    cout << ans << '\n';
    return 0;
}