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
    int k;
    cin >> k;
    int n;
    cin >> n;
    map<long long, int> a;
    map<char, int> mp;
    mp['w'] = 0;
    mp['y'] = 1;
    mp['g'] = 2;
    mp['b'] = 3;
    mp['r'] = 4;
    mp['o'] = 5;
    for (int i = 0; i < n; i++) {
        long long x;
        string s;
        cin >> x >> s;
        a[x] = mp[s[0]];
    }
    mint now = 1;
    mint prev = 0;
    map<long long, vector<mint>> dp;
    for (int d = k - 1; d >= 0; d--) {
        map<long long, vector<mint>> new_dp;
        vector<long long> ids;
        for (auto [key, val] : dp) {
            ids.emplace_back(key / 2);
        }
        for (auto [key, val] : a) {
            if (key < (1LL << d) || (1LL << (d + 1)) <= key) {
                continue;
            }
            ids.emplace_back(key);
        }
        if (d == 0) {
            ids.emplace_back(1);
        }
        sort(ids.begin(), ids.end());
        ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
        for (auto i : ids) {
            if (d == k - 1) {
                new_dp[i] = vector<mint>(6, now);
            } else {
                if (dp[2 * i].empty()) {
                    dp[2 * i] = vector<mint>(6, prev);
                }
                if (dp[2 * i + 1].empty()) {
                    dp[2 * i + 1] = vector<mint>(6, prev);
                }
                new_dp[i] = vector<mint>(6);
                for (int j = 0; j < 6; j++) {
                    for (int x = 0; x < 6; x++) {
                        if (x == j || (x ^ 1) == j) {
                            continue;
                        }
                        for (int y = 0; y < 6; y++) {
                            if (y == j || (y ^ 1) == j) {
                                continue;
                            }
                            new_dp[i][j] += dp[2 * i][x] * dp[2 * i + 1][y];
                        }
                    }
                }
            }
            if (a.count(i)) {
                for (int j = 0; j < 6; j++) {
                    if (a[i] != j) {
                        new_dp[i][j] = 0;
                    }
                }
            }
        }
        swap(dp, new_dp);
        prev = now;
        now = now * now * 16;
    }
    cout << accumulate(dp[1].begin(), dp[1].end(), mint(0)) << '\n';
    return 0;
}