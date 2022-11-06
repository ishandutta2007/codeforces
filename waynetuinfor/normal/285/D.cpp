#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define imie(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int mod = 1e9 + 7;

struct modint {
    int v;
    modint();
    modint(int);
    modint operator+(const modint &) const;
    modint operator-(const modint &) const;
    modint operator*(const modint &) const;
    modint operator/(const modint &) const;
    modint operator+(const int &) const;
    modint operator-(const int &) const;
    modint operator*(const int &) const;
    modint operator/(const int &) const;
    modint &operator+=(const modint &);
    modint &operator-=(const modint &);
    modint &operator*=(const modint &);
    modint &operator/=(const modint &);
    modint &operator+=(const int &);
    modint &operator-=(const int &);
    modint &operator*=(const int &);
    modint &operator/=(const int &);
    modint &operator=(const modint &);
    modint &operator=(const int &);
};

modint fpow(modint a, int n) {
    modint ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

modint::modint() { v = 0; }
modint::modint(int v) { this->v = v; }
modint modint::operator+(const modint &m) const { return modint(v + m.v >= mod ? v + m.v - mod : v + m.v); }
modint modint::operator+(const int &m) const { return modint(v + m >= mod ? v + m - mod : v + m); }
modint& modint::operator+=(const modint &m) { v += m.v; if (v >= mod) v -= mod; return *this; }
modint& modint::operator+=(const int &m) { v += m; if (v >= mod) v -= mod; return *this; }
modint modint::operator-(const modint &m) const { return modint(v - m.v < 0 ? v - m.v + mod : v - m.v); }
modint modint::operator-(const int &m) const { return modint(v - m < 0 ? v - m + mod : v - m); }
modint& modint::operator-=(const modint &m) { v -= m.v; if (v < 0) v += mod; return *this; }
modint& modint::operator-=(const int &m) { v -= m; if (v < 0) v += mod; return *this; }
modint modint::operator*(const modint &m) const { return modint(v * 1ll * m.v % mod); }
modint modint::operator*(const int &m) const { return modint(v * 1ll * m % mod); }
modint& modint::operator*=(const modint &m) { v = v * 1ll * m.v % mod; return *this; }
modint& modint::operator*=(const int &m) { v = v * 1ll * m % mod; return *this; }
modint modint::operator/(const modint &m) const { return operator*(modint(fpow(m, mod - 2))); }
modint modint::operator/(const int &m) const { return operator*(modint(fpow(modint(m), mod - 2))); }
modint& modint::operator/=(const modint &m) { (v *= 1ll * fpow(m, mod - 2).v) %= mod; return *this; }
modint& modint::operator/=(const int &m) { v = v * 1ll * fpow(modint(m), mod - 2).v % mod; return *this; }
modint& modint::operator=(const modint &m) { v = m.v; }
modint& modint::operator=(const int &m) { v = m; }
ostream &operator<<(ostream &s, const modint &m) { return s << m.v; }
istream &operator>>(istream &s, modint &m) { return s >> m.v; }

const int maxn = 16;

modint solve(int n) {
    if (n % 2 == 0) return 0;
    int left = n / 2, right = n - n / 2;
    modint fl = 1, fr = 1;
    for (int i = 1; i <= left; ++i) fl *= i;
    for (int i = 1; i <= right; ++i) fr *= i;
    modint fac = 1;
    for (int i = 1; i <= n; ++i) fac *= i;
    // debug() << imie(left) << imie(right);
    // debug() << imie(fl) << imie(fr);
    modint ans = 0;
    for (int i = 0; i < (1 << n); ++i) if (__builtin_popcount(i) == left) {
        map<int, modint> cnt;
        vector<int> b;
        for (int j = 0; j < n; ++j) if ((1 << j) & i) b.push_back(j + 1);
        // debug() << imie(b);
        do {
            int mask = 0;
            bool ok = true;
            for (int j = 0; ok && j < left; ++j) {
                int c = (j + b[j] - 1) % n;
                if (mask & (1 << c)) ok = false;
                mask |= (1 << c);
            }
            if (ok) cnt[mask] += 1;
        } while (next_permutation(b.begin(), b.end()));
        b.clear();
        for (int j = 0; j < n; ++j) if (!((1 << j) & i)) b.push_back(j + 1);
        do {
            int mask = 0;
            bool ok = true;
            for (int j = 0; ok && j < right; ++j) {
                int c = (j + left + b[j] - 1) % n;
                if (mask & (1 << c)) ok = false;
                mask |= (1 << c);
            }
            if (ok) ans += fac * cnt[((1 << n) - 1) ^ mask];
        } while (next_permutation(b.begin(), b.end()));
    }
    return ans;
}

int ans[20];

int main() {
    // freopen("285d_table.txt", "w", stdout);
    ans[1] = 1;
    ans[2] = 0;
    ans[3] = 18;
    ans[4] = 0;
    ans[5] = 1800;
    ans[6] = 0;
    ans[7] = 670320;
    ans[8] = 0;
    ans[9] = 734832000;
    ans[10] = 0;
    ans[11] = 890786230;
    ans[12] = 0;
    ans[13] = 695720788;
    ans[14] = 0;
    ans[15] = 150347555;
    ans[16] = 0;
    int n; cin >> n;
    cout << ans[n] << endl;
    // for (int i = 1; i <= 16; ++i) {
        // debug() << imie(i);
        // cout << "ans[" << i << "] = " << solve(i) << ";" << endl;
    // }    
}