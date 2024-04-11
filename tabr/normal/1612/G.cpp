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

void test(vector<int> a) {
    sort(a.begin(), a.end());
    int mx = -1;
    do {
        map<int, vector<int>> mp;
        for (int i = 0; i < (int) a.size(); i++) {
            mp[a[i]].emplace_back(i);
        }
        int s = 0;
        for (auto [k, v] : mp) {
            for (int i = 0; i < (int) v.size(); i++) {
                for (int j = i + 1; j < (int) v.size(); j++) {
                    s += v[j] - v[i];
                }
            }
        }
        if (mx <= s) {
            debug(s, a);
            mx = s;
        }
    } while (next_permutation(a.begin(), a.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // test({1, 1, 1, 1, 1, 1, 1, 2, 2, 2});
    test({1, 1, 2, 2, 1, 1, 2, 2});
    int n;
    cin >> n;
    vector<int> c(n);
    int m = 1e6 + 10;
    vector<int> d(m);
    long long e = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        e += c[i];
        d[c[i]]++;
    }
    mint x = 0;
    mint y = 1;
    C(m, 0);
    for (int i = m - 1; i >= 2; i--) {
        if (d[i] == 0) {
            continue;
        }
        debug(i, d[i]);
        mint t = mint(e - d[i]) * d[i];
        x += t * (i - 1);
        e -= d[i] * 2;
        d[i - 2] += d[i];
        y *= fact[d[i]] * fact[d[i]];
    }
    y *= fact[d[1]];
    cout << x << " " << y << '\n';
    return 0;
}