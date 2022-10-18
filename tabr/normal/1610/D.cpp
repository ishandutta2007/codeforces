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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mint ans = 0;
    vector<int> b;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            odd++;
        } else {
            b.emplace_back(a[i] / 2);
        }
    }
    ans += (power(2, odd) - 1) * power(2, n - odd);
    while (!b.empty()) {
        n = (int) b.size();
        odd = 0;
        vector<int> c;
        for (int i : b) {
            if (i % 2) {
                odd++;
            } else {
                c.emplace_back(i / 2);
            }
        }
        mint t = 0;
        for (int i = 2; i <= odd; i += 2) {
            t += C(odd, i);
        }
        ans += t * power(2, n - odd);
        swap(b, c);
        debug(b, ans);
    }
    /*
    map<pair<long long, long long>, mint> mp;
    mp[make_pair(0, 0)] = 1;
    for (int i = 0; i < n; i++) {
        map<pair<long long, long long>, mint> new_mp;
        for (auto [x, y] : mp) {
            auto nx = x;
            nx.first = gcd(nx.first, 2 * b[i]);
            nx.second += b[i];
            nx.second %= nx.first;
            new_mp[nx] += y;
            new_mp[x] += y;
        }
        swap(mp, new_mp);
    }
    debug(mp);
    for (auto [x, y] : mp) {
        if (x.first != 0 && x.second == 0) {
            ans += y;
        }
    }
    */
    /*
    {
        for (int mask = 1; mask < (1 << n); mask++) {
            long long c = 0;
            long long d = 0;
            vector<long long> e;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    d += b[i];
                    c = gcd(c, b[i]);
                    e.emplace_back(b[i]);
                }
            }
            d %= 2 * c;
            debug(c, d);
            if (d != 0) {
                debug(e);
            }
        }
    }
    */
    cout << ans << '\n';
    return 0;
}