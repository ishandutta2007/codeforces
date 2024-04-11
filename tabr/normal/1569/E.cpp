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
    int k;
    mint a, h;
    cin >> k >> a >> h;
    vector<int> p, r;
    vector<mint> q;
    p.emplace_back(1);
    q.emplace_back(a);
    r.emplace_back(1);
    for (int i = 0; i < k; i++) {
        p.emplace_back((1 << i) + 1);
        q.emplace_back(power(a, (1 << i) + 1));
        r.emplace_back(1 << i);
    }
    int n = 1 << k;
    if (k <= 4) {
        for (int mask = 0; mask < (1 << (n - 1)); mask++) {
            vector<int> s(n);
            int id = 0;
            vector<int> b(n);
            iota(b.begin(), b.end(), 0);
            for (int i = k - 1; i >= 0; i--) {
                vector<int> new_b;
                for (int j = 0; j < (1 << (i + 1)); j += 2) {
                    if (mask & (1 << id)) {
                        new_b.emplace_back(b[j + 1]);
                        s[b[j + 1]]++;
                    } else {
                        new_b.emplace_back(b[j]);
                        s[b[j]]++;
                    }
                    id++;
                }
                swap(b, new_b);
            }
            mint x = 0;
            for (int i = 0; i < n; i++) {
                x += q[k - s[i]] * (i + 1);
            }
            if (x == h) {
                for (int i = 0; i < n; i++) {
                    cout << p[k - s[i]] << " ";
                }
                cout << '\n';
                return 0;
            }
        }
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<mint, vector<int>>> l0, l1;
    vector<pair<mint, vector<int>>> r0, r1;
    for (int mask = 0; mask < (1 << 15); mask++) {
        vector<int> s(16);
        int id = 0;
        vector<int> b(16);
        iota(b.begin(), b.end(), 0);
        for (int i = 3; i >= 0; i--) {
            vector<int> new_b;
            for (int j = 0; j < (1 << (i + 1)); j += 2) {
                if (mask & (1 << id)) {
                    new_b.emplace_back(b[j + 1]);
                    s[b[j + 1]]++;
                } else {
                    new_b.emplace_back(b[j]);
                    s[b[j]]++;
                }
                id++;
            }
            swap(b, new_b);
        }
        mint x = 0, y = 0;
        for (int i = 0; i < 16; i++) {
            x += q[k - s[i]] * (i + 1);
            y += q[k - s[i]] * (i + 17);
        }
        l0.emplace_back(x, s);
        r0.emplace_back(y, s);
        for (int i = 0; i < 16; i++) {
            if (s[i] == k - 1) {
                s[i]++;
            }
        }
        x = 0, y = 0;
        for (int i = 0; i < 16; i++) {
            x += q[k - s[i]] * (i + 1);
            y += q[k - s[i]] * (i + 17);
        }
        l1.emplace_back(x, s);
        r1.emplace_back(y, s);
    }
    sort(l0.begin(), l0.end());
    sort(l1.begin(), l1.end());
    sort(r0.begin(), r0.end());
    sort(r1.begin(), r1.end());
    for (int i = 0; i < (int) l0.size(); i++) {
        pair<mint, vector<int>> c;
        c.first = h - l0[i].first;
        int id = (int) (lower_bound(r1.begin(), r1.end(), c) - r1.begin());
        if (id < (int) r1.size() && r1[id].first + l0[i].first == h) {
            for (int j : l0[i].second) {
                cout << p[k - j] << " ";
            }
            for (int j : r1[id].second) {
                cout << p[k - j] << " ";
            }
            cout << '\n';
            return 0;
        }
    }
    for (int i = 0; i < (int) l1.size(); i++) {
        pair<mint, vector<int>> c;
        c.first = h - l1[i].first;
        int id = (int) (lower_bound(r0.begin(), r0.end(), c) - r0.begin());
        if (id < (int) r0.size() && l1[i].first + r0[id].first == h) {
            for (int j : l1[i].second) {
                cout << p[k - j] << " ";
            }
            for (int j : r0[id].second) {
                cout << p[k - j] << " ";
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}