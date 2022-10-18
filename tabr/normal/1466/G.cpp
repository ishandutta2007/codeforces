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
vector<mint> fact(1, 1), finv(1, 1);
inline mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int)fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int)fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

vector<int> z_algo(const string& s) {
    int n = (int)s.size();
    vector<int> res(n, n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        res[i] = (r < i ? 0 : min(r - i + 1, res[i - l]));
        while (i + res[i] < n && s[res[i]] == s[i + res[i]]) {
            res[i]++;
        }
        if (r < i + res[i] - 1) {
            l = i;
            r = i + res[i] - 1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s0, t;
    cin >> s0 >> t;
    vector<string> s(n + 1);
    s[0] = s0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + t[i - 1] + s[i - 1];
        if ((int)s[i].size() > (int)1e6) {
            break;
        }
    }
    int MAX = (int)2.1e6;
    vector<mint> p2(MAX, 1);
    for (int i = 1; i < MAX; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    vector<vector<mint>> b(n + 1, vector<mint>(26));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            b[i][j] = b[i - 1][j];
        }
        b[i][t[i - 1] - 'a'] += mint(1) / p2[i];
    }
    while (q--) {
        int k;
        string w;
        cin >> k >> w;
        int id = 0;
        while (s[id].size() < w.size()) {
            id++;
        }
        if (id > k) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> f = z_algo(w + "#" + s[id]);
        vector<int> g = z_algo(string(w.rbegin(), w.rend()) + "#" + string(s[id].rbegin(), s[id].rend()));
        int m = (int)w.size();
        int l = (int)f.size();
        mint ans = 0;
        for (int i = m + 1; i < l; i++) {
            if (f[i] == m) {
                ans += p2[k - id];
            }
        }
        vector<int> a(26);
        for (int i = 0; i < m; i++) {
            bool ok = true;
            if (i != 0) {
                if (f[l - i] != i) {
                    ok = false;
                }
            }
            if (i != m - 1) {
                if (g[l - (m - 1 - i)] != m - 1 - i) {
                    ok = false;
                }
            }
            if (ok) {
                a[w[i] - 'a']++;
            }
        }
        mint tmp = 0;
        for (int i = 0; i < 26; i++) {
            tmp += (b[k][i] - b[id][i]) * a[i];
        }
        ans += tmp * p2[k];
        cout << ans << '\n';
    }
    return 0;
}