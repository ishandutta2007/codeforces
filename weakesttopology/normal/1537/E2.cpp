#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll modpow(ll x, ll p, ll mod) {
    ll res = 1;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}
template<ll mod>
struct FreeGroup {
    inline static const ll base = uniform_int_distribution<ll>(2, mod - 1)(rng), inv_base = modpow(base, mod - 2, mod);
    ll shift, inv_shift, hash;
    FreeGroup(ll shift, ll inv_shift, ll hash) : shift(shift), inv_shift(inv_shift), hash(hash) { }
    FreeGroup() : shift(1), inv_shift(1), hash(0) { }
    FreeGroup(ll c) : shift(base), inv_shift(inv_base), hash(c + 1) { }
    FreeGroup(const string& s) : FreeGroup() {
        for (auto c : s) *this += FreeGroup(c);
    }
    FreeGroup& operator+=(const FreeGroup& rhs) {
        shift = shift * rhs.shift % mod;
        inv_shift = inv_shift * rhs.inv_shift % mod;
        hash = (rhs.shift * hash + rhs.hash) % mod;
        return *this;
    }
    FreeGroup& operator-=(const FreeGroup& rhs) { return *this += (-rhs); }
    FreeGroup operator+(const FreeGroup& rhs) const { return FreeGroup(*this) += rhs; }
    FreeGroup operator-(const FreeGroup& rhs) const { return FreeGroup(*this) -= rhs; }
    FreeGroup operator+() const { return *this; }
    FreeGroup operator-() const {
        return FreeGroup(inv_shift, shift, (mod - inv_shift * hash % mod) % mod);
    }
    FreeGroup power(ll p) const {
        FreeGroup x = *this;
        if (p < 0) p *= -1, x = -x;
        FreeGroup res;
        while (p) {
            if (p & 1) res = res + x;
            x += x, p >>= 1;
        }
        return res;
    }
    bool operator<(const FreeGroup& rhs) const { return pair(shift, hash) < pair(rhs.shift, rhs.hash); }
    bool operator==(const FreeGroup& rhs) const { return shift == rhs.shift && hash == rhs.hash; }
    bool operator!=(const FreeGroup& rhs) const { return not (*this == rhs); }
};
constexpr ll mod = 1e9 + 9;
using F = FreeGroup<mod>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (n == 1) {
        cout << string(k, s[0]) << endl;
        exit(0);
    }
    vector<F> h;
    F sum;
    for (auto ch : s) {
        sum += ch;
        h.push_back(sum);
    }
    auto query = [&](int l, int r) { return (l ? -h[l - 1] : F()) + h[r]; };
    auto cmp = [&](int la, int ra, int lb, int rb) {
        int lena = ra - la + 1, lenb = rb - lb + 1;
        int L = min(lena, lenb);
        if (query(la, la + L - 1) == query(lb, lb + L - 1)) return lena < lenb;
        else {
            int lcp = 0;
            for (int z = L; z; z >>= 1) {
                while (lcp + z < L && query(la, la + lcp + z - 1) == query(lb, lb + lcp + z - 1)) lcp += z;
            }
            return s[la + lcp] < s[lb + lcp];
        }
    };
    auto update = [&]() {
        while (n < k) {
            s += s;
            n = (int)size(s);
            h.resize(n);
            for (int j = n / 2; j < n; ++j) {
                h[j] = h[j - 1] + s[j];
            }
        }
    };
    update();
    for (int i = 0; i < k; ++i) {
        if (cmp(0, i, i + 1, min(n - 1, 2 * i + 1))) {
            s.erase(begin(s) + i + 1, end(s));
            h.erase(begin(h) + i + 1, end(h));
            n = (int)size(s);
            update();
        }
    }
    cout << s.substr(0, k) << endl;
    exit(0);
}