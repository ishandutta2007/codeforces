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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

long long rand_int(long long a, long long b) {  // [a, b]
    return uniform_int_distribution<long long>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> order;
    {
        function<void(int)> Dfs = [&](int x) {
            order.emplace_back(x - 1);
            if (x >= (1 << (n - 1))) {
                return;
            }
            Dfs(2 * x);
            Dfs(2 * x + 1);
        };
        Dfs(1);
    }
    vector<int> a((1 << n) - 1);
    {
        string s;
        cin >> s;
        for (int i = 0; i < (int) a.size(); i++) {
            a[i] = s[order[i]] - 'A';
        }
    }
    int t = 2;
    map<tuple<long long, long long, int>, long long> mp;
    auto Hs = [&](long long x, long long y, int z) {
        if (x > y) {
            swap(x, y);
        }
        if (mp.count(make_tuple(x, y, z))) {
            return mp[make_tuple(x, y, z)];
        }
        return mp[make_tuple(x, y, z)] = t++;
    };
    function<pair<mint, long long>(int, int)> Solve = [&](int x, int level) -> pair<mint, long long> {
        debug(x, level);
        if (level == 1) {
            return make_pair<mint, long long>(1, a[x]);
        }
        auto l = Solve(x + 1, level - 1);
        auto r = Solve(x + (1 << (level - 1)), level - 1);
        pair<mint, long long> res;
        res.second = Hs(l.second, r.second, a[x]);
        res.first = l.first * r.first;
        if (l != r) {
            res.first *= 2;
        }
        return res;
    };
    cout << Solve(0, n).first << '\n';
    return 0;
}