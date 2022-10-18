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
    vector<int> a(m);
    vector<int> ls(n, m), rs(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
        ls[a[i]] = min(ls[a[i]], i);
        rs[a[i]] = max(rs[a[i]], i);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = ls[i] + 1; j < rs[i]; j++) {
            if (a[j] < i) {
                cout << 0 << '\n';
                return 0;
            } else if (a[j] > i) {
                j = rs[a[j]];
            }
        }
    }
    vector<int> b;
    for (int i = 0; i < m; i++) {
        if (ls[a[i]] == i) {
            b.emplace_back(a[i]);
        }
        if (rs[a[i]] == i) {
            b.emplace_back(a[i]);
        }
    }
    debug(b);
    vector<vector<mint>> dp(n * 2, vector<mint>(n * 2));
    for (int l = 2 * n - 1; l >= 0; l--) {
        vector<int> c(n);
        c[b[l]]++;
        for (int r = l + 1; r < 2 * n; r++) {
            c[b[r]]++;
            bool ok = true;
            for (int p = 0; p < n; p++) {
                if (c[p] % 2 == 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            int mn = n + 1, pl = -1, pr = -1;
            for (int p = l; p <= r; p++) {
                if (b[p] < mn) {
                    mn = b[p];
                    pl = p;
                } else if (b[p] == mn) {
                    pr = p;
                }
            }
            if (pl + 1 == pr) {
                dp[l][r] = 1;
            } else {
                dp[l][r] = dp[pl + 1][pr - 1];
            }
            if (l < pl) {
                mint x = dp[l][pl - 1];
                ok = true;
                int pre = mn;
                for (int p = pl - 1; p > l; p--) {
                    int q = b[p];
                    if (rs[q] + 1 == ls[pre]) {
                        p--;
                        while (b[p] != q) {
                            p--;
                        }
                        pre = q;
                        if (l > p - 1) {
                            x += dp[p][pl - 1];
                            ok = false;
                        } else {
                            x += dp[p][pl - 1] * dp[l][p - 1];
                        }
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    x += dp[l][pl - 1];
                }
                dp[l][r] *= x;
                // mint x = dp[l][pl - 1] * 2;
                // for (int p = l; p + 1 < pl; p++) {
                //     x += dp[l][p] * dp[p + 1][pl - 1];
                // }
                // dp[l][r] *= x;
            }
            debug(l, r);
            if (pr < r) {
                mint x = dp[pr + 1][r];
                ok = true;
                int pre = mn;
                for (int p = pr + 1; p < r; p++) {
                    int q = b[p];
                    if (ls[q] - 1 == rs[pre]) {
                        p++;
                        while (b[p] != q) {
                            p++;
                        }
                        pre = q;
                        if (p + 1 > r) {
                            x += dp[pr + 1][p];
                            ok = false;
                        } else {
                            x += dp[pr + 1][p] * dp[p + 1][r];
                        }
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    x += dp[pr + 1][r];
                }
                dp[l][r] *= x;
                // mint x = dp[pr + 1][r] * 2;
                // for (int p = r; p - 1 > pr; p--) {
                //     x += dp[pr + 1][p - 1] * dp[p][r];
                // }
                // dp[l][r] *= x;
            }
            debug(l, r, mn, pl, pr, dp[l][r]);
        }
    }
    debug(dp);
    cout << dp[0][2 * n - 1] << '\n';
    return 0;
}