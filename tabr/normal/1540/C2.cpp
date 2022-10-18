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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            d[i] += b[j];
        }
    }
    int q;
    cin >> q;
    map<int, mint> mp;
    mp[(int) 2e9] = 0;
    mp[(int) -2e9] = 1;
    for (int i = 0; i < n; i++) {
        mp[(int) -2e9] *= c[i] + 1;
    }
    while (q--) {
        int x;
        cin >> x;
        if (mp.count(x)) {
            cout << mp[x] << '\n';
            continue;
        }
        auto nxt = mp.lower_bound(x);
        auto pre = prev(nxt);
        if ((*pre).second == (*nxt).second) {
            cout << (*pre).second << '\n';
            continue;
        }
        int m = 10100;
        vector<mint> dp(m);
        dp[0] = 1;
        int t = 0;
        for (int i = 0; i < n; i++) {
            vector<mint> new_dp(m);
            new_dp[0] = dp[0];
            for (int j = 1; j < m; j++) {
                new_dp[j] = new_dp[j - 1] + dp[j];
                if (j - c[i] - 1 >= 0) {
                    new_dp[j] -= dp[j - c[i] - 1];
                }
            }
            swap(dp, new_dp);
            t += x + d[i];
            for (int j = 0; j < min(m, t); j++) {
                dp[j] = 0;
            }
        }
        mp[x] = accumulate(dp.begin(), dp.end(), mint(0));
        cout << mp[x] << '\n';
    }
    return 0;
}