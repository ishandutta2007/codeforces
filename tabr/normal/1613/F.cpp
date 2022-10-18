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

namespace FFT {
const double PI = acos(-1);
int base = 1;
vector<complex<double>> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

vector<complex<double>> f;

void ensure_base(int nbase) {
    if (nbase <= base) {
        return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
        double angle = 2 * PI / (1 << (base + 1));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            roots[i << 1] = roots[i];
            double angle_i = angle * (2 * i + 1 - (1 << base));
            roots[(i << 1) + 1] = complex<double>(cos(angle_i), sin(angle_i));
        }
        base++;
    }
}

void fft(vector<complex<double>>& a, int n) {
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                complex<double> z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}

template <typename T>
vector<long long> multiply(const vector<T>& a, const vector<T>& b) {
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) {
        nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) f.size()) {
        f.resize(sz);
    }
    for (int i = 0; i < sz; i++) {
        T x = (i < (int) a.size() ? a[i] : 0);
        T y = (i < (int) b.size() ? b[i] : 0);
        f[i] = complex<double>((double) x, (double) y);
    }
    fft(f, sz);
    complex<double> r(0, -0.25 / (sz >> 1));
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        complex<double> z = (f[j] * f[j] - conj(f[i] * f[i])) * r;
        f[j] = (f[i] * f[i] - conj(f[j] * f[j])) * r;
        f[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
        complex<double> a0 = (f[i] + f[i + (sz >> 1)]) * complex<double>(0.5, 0);
        complex<double> a1 = (f[i] - f[i + (sz >> 1)]) * complex<double>(0.5, 0) * roots[(sz >> 1) + i];
        f[i] = a0 + a1 * complex<double>(0, 1);
    }
    fft(f, sz >> 1);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
        res[i] = llround(i % 2 == 0 ? f[i >> 1].real() : f[i >> 1].imag());
    }
    return res;
}
}  // namespace FFT

namespace FFT_MOD {
vector<complex<double>> fa, fb;

vector<mint> multiply_mod(const vector<mint>& a, const vector<mint>& b) {
    if (a.empty() || b.empty()) {
        return {};
    }
    int eq = (a.size() == b.size() && a == b);
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) {
        nbase++;
    }
    FFT::ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) fa.size()) {
        fa.resize(sz);
    }
    for (int i = 0; i < (int) a.size(); i++) {
        int x = (int) (a[i].value + mod);
        fa[i] = complex<double>(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fa.begin() + a.size(), fa.begin() + sz, complex<double>(0, 0));
    FFT::fft(fa, sz);
    if (sz > (int) fb.size()) {
        fb.resize(sz);
    }
    if (eq) {
        copy(fa.begin(), fa.begin() + sz, fb.begin());
    } else {
        for (int i = 0; i < (int) b.size(); i++) {
            int x = (int) (b[i].value + mod);
            fb[i] = complex<double>(x & ((1 << 15) - 1), x >> 15);
        }
        fill(fb.begin() + b.size(), fb.begin() + sz, complex<double>(0, 0));
        FFT::fft(fb, sz);
    }
    double ratio = 0.25 / sz;
    complex<double> r2(0, -1);
    complex<double> r3(ratio, 0);
    complex<double> r4(0, -ratio);
    complex<double> r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        complex<double> a1 = (fa[i] + conj(fa[j]));
        complex<double> a2 = (fa[i] - conj(fa[j])) * r2;
        complex<double> b1 = (fb[i] + conj(fb[j])) * r3;
        complex<double> b2 = (fb[i] - conj(fb[j])) * r4;
        if (i != j) {
            complex<double> c1 = (fa[j] + conj(fa[i]));
            complex<double> c2 = (fa[j] - conj(fa[i])) * r2;
            complex<double> d1 = (fb[j] + conj(fb[i])) * r3;
            complex<double> d2 = (fb[j] - conj(fb[i])) * r4;
            fa[i] = c1 * d1 + c2 * d2 * r5;
            fb[i] = c1 * d2 + c2 * d1;
        }
        fa[j] = a1 * b1 + a2 * b2 * r5;
        fb[j] = a1 * b2 + a2 * b1;
    }
    FFT::fft(fa, sz);
    FFT::fft(fb, sz);
    vector<mint> res(need);
    for (int i = 0; i < need; i++) {
        long long aa = llround(fa[i].real());
        long long bb = llround(fb[i].real());
        long long cc = llround(fa[i].imag());
        res[i] = (aa + ((bb % mod) << 15) + ((cc % mod) << 30));
    }
    return res;
}
}  // namespace FFT_MOD

vector<mint> operator*(const vector<mint>& a, const vector<mint>& b) {
    if (a.empty() || b.empty()) {
        return {};
    } else if (min(a.size(), b.size()) < 150) {
        vector<mint> c(a.size() + b.size() - 1);
        for (int i = 0; i < (int) a.size(); i++) {
            for (int j = 0; j < (int) b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        return c;
    } else {
        return FFT_MOD::multiply_mod(a, b);
    }
}

vector<mint>& operator*=(vector<mint>& a, const vector<mint>& b) {
    return a = a * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<vector<mint>> dp(n, vector<mint>(2));
    set<pair<int, int>> st;
    auto dfs = [&](auto&& self, int v, int p) -> void {
        dp[v][1] = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            self(self, to, v);
            dp[v][0]++;
        }
        st.emplace(1, v);
    };
    dfs(dfs, 0, -1);
    while ((int) st.size() > 1) {
        auto x = *st.begin();
        st.erase(st.begin());
        auto y = *st.begin();
        st.erase(st.begin());
        y.first += x.first;
        st.emplace(y);
        dp[y.second] *= dp[x.second];
    }
    int id = st.begin()->second;
    mint ans = 0;
    debug(dp[0]);
    C(n + 10, 0);
    for (int i = n; i >= 0; i--) {
        if ((n - i) % 2 == 0) {
            ans += mint(1) * dp[id][i] * fact[i];
        } else {
            ans -= mint(1) * dp[id][i] * fact[i];
        }
    }
    cout << ans << '\n';
    return 0;
}