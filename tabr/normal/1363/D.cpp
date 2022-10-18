#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
};
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
vector<mint> fact, finv;
inline void cinit(int n) {
    fact.resize(n, 1);
    finv.resize(n, 1);
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n - 1] /= fact[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}
inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> s(k);
        for (int i = 0; i < k; i++) {
            int c;
            cin >> c;
            for (int j = 0; j < c; j++) {
                int t;
                cin >> t;
                s[i].emplace_back(t);
            }
        }
        int mx;
        cout << "? " << n << " ";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        cin >> mx;
        vector<int> p(k, mx);
        bool all = false;
        int lo = 1, hi = n;
        while (hi - lo > 0) {
            int mid = (hi + lo) / 2;
            cout << "? " << mid - lo + 1 << " ";
            for (int i = lo; i <= mid; i++) {
                cout << i << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            if (x == mx) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int my = mx;
        for (int i = 0; i < k; i++) {
            bool t = false;
            for (int j : s[i]) {
                if (j == hi) {
                    t = true;
                    break;
                }
            }
            if (t) {
                vector<bool> ok(n + 1, true);
                for (int j : s[i]) {
                    ok[j] = false;
                }
                cout << "? " << n - s[i].size() << " ";
                for (int j = 1; j <= n; j++) {
                    if (ok[j]) {
                        cout << j << " ";
                    }
                }
                cout << endl;
                cin >> my;
                p[i] = my;
                break;
            }
        }
        cout << "! ";
        for (int i : p) {
            cout << i << " ";
        }
        cout << endl;
        string b;
        cin >> b;
        assert(b == "Correct");
    }
    return 0;
}