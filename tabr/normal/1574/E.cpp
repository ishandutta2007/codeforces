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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector<map<int, int>> z(h);
    vector<vector<int>> a(h, vector<int>(2));
    vector<vector<int>> b(w, vector<int>(2));
    int nga = 0, ngb = 0;
    int usea = h, useb = w;
    vector<int> cc(2);
    while (q--) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        if (a[x][0] && a[x][1]) {
            nga--;
        } else if (!a[x][0] && !a[x][1]) {
            usea--;
        }
        if (b[y][0] && b[y][1]) {
            ngb--;
        } else if (!b[y][0] && !b[y][1]) {
            useb--;
        }
        if (z[x][y] != 0) {
            z[x][y]--;
            a[x][(y & 1) ^ z[x][y]]--;
            b[y][(x & 1) ^ z[x][y]]--;
            cc[(x ^ y ^ z[x][y]) & 1]--;
        }
        if (c != -1) {
            a[x][(y & 1) ^ c]++;
            b[y][(x & 1) ^ c]++;
            cc[(x ^ y ^ c) & 1]++;
        }
        z[x][y] = c + 1;
        if (a[x][0] && a[x][1]) {
            nga++;
        } else if (!a[x][0] && !a[x][1]) {
            usea++;
        }
        if (b[y][0] && b[y][1]) {
            ngb++;
        } else if (!b[y][0] && !b[y][1]) {
            useb++;
        }
        mint ans = (nga == 0 ? power(2, usea) : 0) + (ngb == 0 ? power(2, useb) : 0);
        if (!nga && !ngb && min(cc[0], cc[1]) == 0) {  // chess
            ans--;
        }
        if (cc[0] + cc[1] == 0) {
            ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}