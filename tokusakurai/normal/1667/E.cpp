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

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty()) cout << '\n';
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
// const int MOD = 1000000007;
const int MOD = 998244353;

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
struct Number_Theoretic_Transform {
    static int max_base;
    static T root;
    static vector<T> r, ir;

    Number_Theoretic_Transform() {}

    static void init() {
        if (!r.empty()) return;
        int mod = T::get_mod();
        int tmp = mod - 1;
        root = 2;
        while (root.pow(tmp >> 1) == 1) root++;
        max_base = 0;
        while (tmp % 2 == 0) tmp >>= 1, max_base++;
        r.resize(max_base), ir.resize(max_base);
        for (int i = 0; i < max_base; i++) {
            r[i] = -root.pow((mod - 1) >> (i + 2)); // r[i]  := 1  2^(i+2) 
            ir[i] = r[i].inverse();                 // ir[i] := 1/r[i]
        }
    }

    static void ntt(vector<T> &a) {
        init();
        int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(n <= (1 << max_base));
        for (int k = n; k >>= 1;) {
            T w = 1;
            for (int s = 0, t = 0; s < n; s += 2 * k) {
                for (int i = s, j = s + k; i < s + k; i++, j++) {
                    T x = a[i], y = w * a[j];
                    a[i] = x + y, a[j] = x - y;
                }
                w *= r[__builtin_ctz(++t)];
            }
        }
    }

    static void intt(vector<T> &a) {
        init();
        int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(n <= (1 << max_base));
        for (int k = 1; k < n; k <<= 1) {
            T w = 1;
            for (int s = 0, t = 0; s < n; s += 2 * k) {
                for (int i = s, j = s + k; i < s + k; i++, j++) {
                    T x = a[i], y = a[j];
                    a[i] = x + y, a[j] = w * (x - y);
                }
                w *= ir[__builtin_ctz(++t)];
            }
        }
        T inv = T(n).inverse();
        for (auto &e : a) e *= inv;
    }

    static vector<T> convolve(vector<T> a, vector<T> b) {
        if (a.empty() || b.empty()) return {};
        int k = (int)a.size() + (int)b.size() - 1, n = 1;
        while (n < k) n <<= 1;
        a.resize(n), b.resize(n);
        ntt(a), ntt(b);
        for (int i = 0; i < n; i++) a[i] *= b[i];
        intt(a), a.resize(k);
        return a;
    }
};

template <typename T>
int Number_Theoretic_Transform<T>::max_base = 0;

template <typename T>
T Number_Theoretic_Transform<T>::root = T();

template <typename T>
vector<T> Number_Theoretic_Transform<T>::r = vector<T>();

template <typename T>
vector<T> Number_Theoretic_Transform<T>::ir = vector<T>();

using NTT = Number_Theoretic_Transform<mint>;

template <typename T>
struct Formal_Power_Series : vector<T> {
    using NTT_ = Number_Theoretic_Transform<T>;
    using vector<T>::vector;

    Formal_Power_Series(const vector<T> &v) : vector<T>(v) {}

    Formal_Power_Series pre(int n) const { return Formal_Power_Series(begin(*this), begin(*this) + min((int)this->size(), n)); }

    Formal_Power_Series rev(int deg = -1) const {
        Formal_Power_Series ret = *this;
        if (deg != -1) ret.resize(deg, T(0));
        reverse(begin(ret), end(ret));
        return ret;
    }

    void normalize() {
        while (!this->empty() && this->back() == 0) this->pop_back();
    }

    Formal_Power_Series operator-() const {
        Formal_Power_Series ret = *this;
        for (int i = 0; i < (int)ret.size(); i++) ret[i] = -ret[i];
        return ret;
    }

    Formal_Power_Series &operator+=(const T &x) {
        if (this->empty()) this->resize(1);
        (*this)[0] += x;
        return *this;
    }

    Formal_Power_Series &operator+=(const Formal_Power_Series &v) {
        if (v.size() > this->size()) this->resize(v.size());
        for (int i = 0; i < (int)v.size(); i++) (*this)[i] += v[i];
        this->normalize();
        return *this;
    }

    Formal_Power_Series &operator-=(const T &x) {
        if (this->empty()) this->resize(1);
        *this[0] -= x;
        return *this;
    }

    Formal_Power_Series &operator-=(const Formal_Power_Series &v) {
        if (v.size() > this->size()) this->resize(v.size());
        for (int i = 0; i < (int)v.size(); i++) (*this)[i] -= v[i];
        this->normalize();
        return *this;
    }

    Formal_Power_Series &operator*=(const T &x) {
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= x;
        return *this;
    }

    Formal_Power_Series &operator*=(const Formal_Power_Series &v) {
        if (this->empty() || empty(v)) {
            this->clear();
            return *this;
        }
        return *this = NTT_::convolve(*this, v);
    }

    Formal_Power_Series &operator/=(const T &x) {
        assert(x != 0);
        T inv = x.inverse();
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= inv;
        return *this;
    }

    Formal_Power_Series &operator/=(const Formal_Power_Series &v) {
        if (v.size() > this->size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - (int)v.size() + 1;
        return *this = (rev().pre(n) * v.rev().inv(n)).pre(n).rev(n);
    }

    Formal_Power_Series &operator%=(const Formal_Power_Series &v) { return *this -= (*this / v) * v; }

    Formal_Power_Series &operator<<=(int x) {
        Formal_Power_Series ret(x, 0);
        ret.insert(end(ret), begin(*this), end(*this));
        return *this = ret;
    }

    Formal_Power_Series &operator>>=(int x) {
        Formal_Power_Series ret;
        ret.insert(end(ret), begin(*this) + x, end(*this));
        return *this = ret;
    }

    Formal_Power_Series operator+(const T &x) const { return Formal_Power_Series(*this) += x; }

    Formal_Power_Series operator+(const Formal_Power_Series &v) const { return Formal_Power_Series(*this) += v; }

    Formal_Power_Series operator-(const T &x) const { return Formal_Power_Series(*this) -= x; }

    Formal_Power_Series operator-(const Formal_Power_Series &v) const { return Formal_Power_Series(*this) -= v; }

    Formal_Power_Series operator*(const T &x) const { return Formal_Power_Series(*this) *= x; }

    Formal_Power_Series operator*(const Formal_Power_Series &v) const { return Formal_Power_Series(*this) *= v; }

    Formal_Power_Series operator/(const T &x) const { return Formal_Power_Series(*this) /= x; }

    Formal_Power_Series operator/(const Formal_Power_Series &v) const { return Formal_Power_Series(*this) /= v; }

    Formal_Power_Series operator%(const Formal_Power_Series &v) const { return Formal_Power_Series(*this) %= v; }

    Formal_Power_Series operator<<(int x) const { return Formal_Power_Series(*this) <<= x; }

    Formal_Power_Series operator>>(int x) const { return Formal_Power_Series(*this) >>= x; }

    T val(const T &x) const {
        T ret = 0;
        for (int i = (int)this->size() - 1; i >= 0; i--) ret *= x, ret += (*this)[i];
        return ret;
    }

    Formal_Power_Series diff() const { // df/dx
        int n = this->size();
        Formal_Power_Series ret(n - 1);
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * i;
        return ret;
    }

    Formal_Power_Series integral() const { // f(x)dx
        int n = this->size();
        Formal_Power_Series ret(n + 1);
        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / (i + 1);
        return ret;
    }

    Formal_Power_Series inv(int deg) const { // 1/f(x) (f[0] != 0)
        assert((*this)[0] != T(0));
        Formal_Power_Series ret(1, (*this)[0].inverse());
        for (int i = 1; i < deg; i <<= 1) {
            Formal_Power_Series f = pre(2 * i), g = ret;
            f.resize(2 * i), g.resize(2 * i);
            NTT_::ntt(f), NTT_::ntt(g);
            Formal_Power_Series h(2 * i);
            for (int j = 0; j < 2 * i; j++) h[j] = f[j] * g[j];
            NTT_::intt(h);
            for (int j = 0; j < i; j++) h[j] = 0;
            NTT_::ntt(h);
            for (int j = 0; j < 2 * i; j++) h[j] *= g[j];
            NTT_::intt(h);
            for (int j = 0; j < i; j++) h[j] = 0;
            ret -= h;
        }
        ret.resize(deg);
        return ret;
    }

    Formal_Power_Series inv() const { return inv(this->size()); }

    Formal_Power_Series log(int deg) const { // log(f(x)) (f[0] = 1)
        assert((*this)[0] == 1);
        Formal_Power_Series ret = (diff() * inv(deg)).pre(deg - 1).integral();
        ret.resize(deg);
        return ret;
    }

    Formal_Power_Series log() const { return log(this->size()); }

    Formal_Power_Series exp(int deg) const { // exp(f(x)) (f[0] = 0)
        assert((*this)[0] == 0);
        Formal_Power_Series inv;
        inv.reserve(deg + 1);
        inv.push_back(0), inv.push_back(1);

        auto inplace_integral = [&](Formal_Power_Series &F) -> void {
            int n = F.size();
            int mod = T::get_mod();
            while ((int)inv.size() <= n) {
                int i = inv.size();
                inv.push_back((-inv[mod % i]) * (mod / i));
            }
            F.insert(begin(F), 0);
            for (int i = 1; i <= n; i++) F[i] *= inv[i];
        };

        auto inplace_diff = [](Formal_Power_Series &F) -> void {
            if (F.empty()) return;
            F.erase(begin(F));
            T coeff = 1, one = 1;
            for (int i = 0; i < (int)F.size(); i++) {
                F[i] *= coeff;
                coeff += one;
            }
        };

        Formal_Power_Series ret{1, this->size() > 1 ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};
        for (int m = 2; m < deg; m *= 2) {
            auto y = ret;
            y.resize(2 * m);
            NTT_::ntt(y);
            z1 = z2;
            Formal_Power_Series z(m);
            for (int i = 0; i < m; i++) z[i] = y[i] * z1[i];
            NTT_::intt(z);
            fill(begin(z), begin(z) + m / 2, 0);
            NTT_::ntt(z);
            for (int i = 0; i < m; i++) z[i] *= -z1[i];
            NTT_::intt(z);
            c.insert(end(c), begin(z) + m / 2, end(z));
            z2 = c, z2.resize(2 * m);
            NTT_::ntt(z2);
            Formal_Power_Series x(begin(*this), begin(*this) + min((int)this->size(), m));
            inplace_diff(x);
            x.push_back(0);
            NTT_::ntt(x);
            for (int i = 0; i < m; i++) x[i] *= y[i];
            NTT_::intt(x);
            x -= ret.diff(), x.resize(2 * m);
            for (int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = 0;
            NTT_::ntt(x);
            for (int i = 0; i < 2 * m; i++) x[i] *= z2[i];
            NTT_::intt(x);
            x.pop_back();
            inplace_integral(x);
            for (int i = m; i < min((int)this->size(), 2 * m); i++) x[i] += (*this)[i];
            fill(begin(x), begin(x) + m, 0);
            NTT_::ntt(x);
            for (int i = 0; i < 2 * m; i++) x[i] *= y[i];
            NTT_::intt(x);
            ret.insert(end(ret), begin(x) + m, end(x));
        }
        ret.resize(deg);
        return ret;
    }

    Formal_Power_Series exp() const { return exp(this->size()); }

    Formal_Power_Series pow(long long k, int deg) const { // f(x)^k
        int n = this->size();
        for (int i = 0; i < n; i++) {
            if ((*this)[i] == 0) continue;
            T rev = (*this)[i].inverse();
            Formal_Power_Series C(*this * rev), D(n - i, 0);
            for (int j = i; j < n; j++) D[j - i] = C[j];
            D = (D.log() * k).exp() * ((*this)[i].pow(k));
            Formal_Power_Series E(deg, 0);
            if (i > 0 && k > deg / i) return E;
            long long S = i * k;
            for (int j = 0; j + S < deg && j < D.size(); j++) E[j + S] = D[j];
            E.resize(deg);
            return E;
        }
        return Formal_Power_Series(deg, 0);
    }

    Formal_Power_Series pow(long long k) const { return pow(k, this->size()); }

    Formal_Power_Series Taylor_shift(T c) const { // f(x+c)
        int n = this->size();
        vector<T> ifac(n, 1);
        Formal_Power_Series f(n), g(n);
        for (int i = 0; i < n; i++) {
            f[n - 1 - i] = (*this)[i] * ifac[n - 1];
            if (i < n - 1) ifac[n - 1] *= i + 1;
        }
        ifac[n - 1] = ifac[n - 1].inverse();
        for (int i = n - 1; i > 0; i--) ifac[i - 1] = ifac[i] * i;
        T pw = 1;
        for (int i = 0; i < n; i++) {
            g[i] = pw * ifac[i];
            pw *= c;
        }
        f *= g;
        Formal_Power_Series b(n);
        for (int i = 0; i < n; i++) b[i] = f[n - 1 - i] * ifac[i];
        return b;
    }
};

using fps = Formal_Power_Series<mint>;

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

    static T H(int n, int k) { // k  n 
        if (n < 0 || k < 0) return 0;
        return k == 0 ? 1 : C(n + k - 1, k);
    }

    static T second_stirling_number(int n, int k) { // n k  1 
        T ret = 0;
        for (int i = 0; i <= k; i++) {
            T tmp = C(k, i) * T(i).pow(n);
            ret += ((k - i) & 1) ? -tmp : tmp;
        }
        return ret * ifac(k);
    }

    static T bell_number(int n, int k) { // n k 
        if (n == 0) return 1;
        k = min(k, n);
        vector<T> pref(k + 1);
        pref[0] = 1;
        for (int i = 1; i <= k; i++) {
            if (i & 1) {
                pref[i] = pref[i - 1] - ifac(i);
            } else {
                pref[i] = pref[i - 1] + ifac(i);
            }
        }
        T ret = 0;
        for (int i = 1; i <= k; i++) ret += T(i).pow(n) * ifac(i) * pref[k - i];
        return ret;
    }
};

template <typename T>
vector<T> Combination<T>::_fac = vector<T>();

template <typename T>
vector<T> Combination<T>::_ifac = vector<T>();

using comb = Combination<mint>;

int main() {
    int N;
    cin >> N;

    comb::init(N);

    vector<mint> f(N + 1, 0);
    vector<mint> s(N + 1, 0);
    rep(i, N) s[i + 1] = s[i] + comb::inv(i + 1);
    rep2(i, 1, N) {
        f[i] = 1;
        f[i] -= s[i - 1] - s[(N - 1) / 2];
        f[i] *= comb::fac(i - 1);
    }
    // print(f);

    vector<mint> g1(N + 1, 0), g2(N + 1, 0);
    rep2(i, (N + 1) / 2, N) g1[i] = comb::fac(N - i - 1) * comb::ifac(i - 1) * f[i];
    rep2(i, 0, N) g2[i] = comb::ifac(i);
    vector<mint> g = NTT::convolve(g1, g2);
    vector<mint> h(N, 0);
    rep2(i, 1, N - 1) h[i] = g[N - i] * comb::fac(N - 1 - i) * i;
    h[0] = f[N];
    print(h);
}