#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    static int get_mod() { return mod; }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() { return *this += Mod_Int(1); }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() { return *this -= Mod_Int(1); }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const { return Mod_Int(-x); }

    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }

    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }

    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }

    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }

    bool operator==(const Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Mod_Int &p) const { return x != p.x; }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template <typename T>
struct Combination {
    static vector<T> _fac, _ifac;

    Combination() {}

    static void init(int n) {
        _fac.resize(n + 1), _ifac.resize(n + 1);
        _fac[0] = 1;
        for (int i = 1; i <= n; i++) _fac[i] = _fac[i - 1] * i;
        _ifac[n] = _fac[n].inverse();
        for (int i = n; i >= 1; i--) _ifac[i - 1] = _ifac[i] * i;
    }

    static T fac(int k) { return _fac[k]; }

    static T ifac(int k) { return _ifac[k]; }

    static T inv(int k) { return fac(k - 1) * ifac(k); }

    static T P(int n, int k) {
        if (k < 0 || n < k) return 0;
        return fac(n) * ifac(n - k);
    }

    static T C(int n, int k) {
        if (k < 0 || n < k) return 0;
        return fac(n) * ifac(n - k) * ifac(k);
    }

    static T H(int n, int k) { // kn
        if (n < 0 || k < 0) return 0;
        return k == 0 ? 1 : C(n + k - 1, k);
    }

    static T second_stirling_number(int n, int k) { // nk1
        T ret = 0;
        for (int i = 0; i <= k; i++) {
            T tmp = C(k, i) * T(i).pow(n);
            ret += ((k - i) & 1) ? -tmp : tmp;
        }
        return ret * ifac(k);
    }

    static T bell_number(int n, int k) { // nk
        if (n == 0) return 1;
        k = min(k, n);
        vector<T> pref(k + 1);
        pref[0] = 1;
        for (int i = 1; i <= k; i++) {
            if (i & 1)
                pref[i] = pref[i - 1] - ifac(i);
            else
                pref[i] = pref[i - 1] + ifac(i);
        }
        T ret = 0;
        for (int i = 1; i <= k; i++) { ret += T(i).pow(n) * ifac(i) * pref[k - i]; }
        return ret;
    }
};

template <typename T>
vector<T> Combination<T>::_fac = vector<T>();

template <typename T>
vector<T> Combination<T>::_ifac = vector<T>();

using comb = Combination<mint>;

int main() {
    int T;
    cin >> T;

    comb::init(200000);

    while (T--) {
        int N, L, R;
        cin >> N >> L >> R;

        int K = min(1 - L, R - N);
        chmax(K, 0);
    
        mint ans = 0;
        if (N & 1) {
            ans += (comb::C(N, (N + 1) / 2) + comb::C(N, (N - 1) / 2)) * K;
        } else {
            ans += comb::C(N, N / 2) * K;
        }

        rep2(i, K + 1, K + N + 1) {
            int l = L + i, r = R - i;
            chmax(l, 1), chmin(r, N);
            int a = l - 1, b = N - r;
            if (a + b > N) continue;
            a = N / 2 - a, b = N / 2 - b;
            if (N & 1) {
                ans += comb::C(a + b + 1, a) + comb::C(a + b + 1, b);
            } else {
                ans += comb::C(a + b, b);
            }
        }

        cout << ans << '\n';
    }
}