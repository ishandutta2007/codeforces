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
}
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
vector<mint> fact(1, 1), finv(1, 1);
inline mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    if (n >= mod) {
        mint res = 1;
        while (n) {
            res *= C(n % (int)mod, k % (int)mod);
            n /= (int)mod;
            k /= (int)mod;
        }
        return res;
    }
    while ((int)fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int)fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        b[x][y] = b[y][x] = 1;
    }
    int inf = (int)1e9;
    vector<vector<int>> d(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
        queue<int> que;
        que.emplace(i);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int to : g[v]) {
                if (d[i][to] == inf) {
                    d[i][to] = d[i][v] + 1;
                    que.emplace(to);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mint a = 1;
            if (i == j) {
                for (int v = 0; v < n; v++) {
                    if (v == i || v == j) {
                        continue;
                    }
                    mint t = 0;
                    for (int to : g[v]) {
                        if (d[i][to] + 1 == d[i][v] && d[j][to] + 1 == d[j][v]) {
                            t += 1;
                        }
                    }
                    a *= t;
                }
            } else {
                int z = d[i][j];
                vector<int> c(n);
                for (int v = 0; v < n; v++) {
                    if (v == i) {
                        continue;
                    }
                    mint t = 0;
                    if (d[i][v] + d[j][v] == z) {
                        if (c[d[i][v]]) {
                            a = 0;
                        }
                        c[d[i][v]]++;
                    }
                    for (int to : g[v]) {
                        if (d[i][to] == d[i][v] - 1 && d[j][to] == d[j][v] - 1) {
                            t += 1;
                        } else if (d[i][v] + d[j][v] == z && d[i][to] == d[i][v] - 1 && d[j][to] == d[j][v] + 1) {
                            t += 1;
                        }
                    }
                    a *= t;
                    // debug(v, t);
                }
                // debug(d[i], d[j], z);
            }
            cout << a << " ";
        }
        cout << '\n';
    }
    return 0;
}