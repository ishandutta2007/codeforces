#include <bits/stdc++.h>
template<int P>
struct Z {
    int x;
    Z() : x(0) {}
    Z(int64_t x_) {
        x = x_ % P;
        if (x < 0) x += P;
    }
    Z& operator+=(Z rhs) {
        x += rhs.x;
        if (x >= P) x -= P;
        return *this;
    }
    Z& operator-=(Z rhs) {
        x -= rhs.x;
        if (x < 0) x += P;
        return *this;
    }
    Z& operator*=(Z rhs) {
        x = int64_t(x) * rhs.x % P;
        return *this;
    }
    Z& operator/=(Z rhs) {
        return *this *= rhs.power(-1);
    }
    Z power(int64_t p) const {
        p %= P - 1;
        if (p < 0) p += P - 1;
        Z res = 1;
        for (Z y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    Z operator-() const {
        return Z() - *this;
    }
    bool operator==(Z rhs) const {
        return x == rhs.x;
    }
    bool operator!=(Z rhs) const {
        return x != rhs.x;
    }
    friend Z operator+(Z lhs, Z rhs) {
        return lhs += rhs;
    }
    friend Z operator-(Z lhs, Z rhs) {
        return lhs -= rhs;
    }
    friend Z operator*(Z lhs, Z rhs) {
        return lhs *= rhs;
    }
    friend Z operator/(Z lhs, Z rhs) {
        return lhs /= rhs;
    }
    friend std::ostream& operator<<(std::ostream& out, Z a) {
        return out << a.x;
    }
    friend std::istream& operator>>(std::istream& in, Z& a) {
        int64_t x;
        in >> x;
        a = Z(x);
        return in;
    }
    inline static const Z X = [](){
        std::uniform_int_distribution<int64_t> unif(1, P - 1);
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using Zp = Z<998244353>;
template<typename T>
struct root_of_unity {
    T operator()(int N) const = delete; // not implemented
};
template<typename T>
struct root_of_unity<std::complex<T>> {
    inline static const T PI = std::acos(-1);
    std::complex<T> operator()(int N) const {
        return std::polar<T>(1, 2 * PI / N);
    }
};
constexpr int ntt_mod = 998244353;
template<>
struct root_of_unity<Z<ntt_mod>> {
    Z<ntt_mod> operator()(int N) const {
        return Z<ntt_mod>(3).power((ntt_mod - 1) / N);
    }
};
template<typename T>
std::vector<T> fft(std::vector<T> p, bool inverse) {
    int N = p.size();
    std::vector<T> q(N);
    for (int i = 0; i < N; ++i) {
        int rev = 0;
        for (int b = 1; b < N; b <<= 1) {
            rev = (rev << 1) | !!(i & b);
        }
        q[rev] = p[i];
    }
    std::swap(p, q);
    root_of_unity<T> rt;
    for (int b = 1; b < N; b <<= 1) {
        T w = rt(b << 1);
        if (inverse) w = T(1) / w;
        for (auto [i, x] = std::pair(0, T(1)); i < N; ++i, x *= w) {
            q[i] = p[i & ~b] + x * p[i | b];
        }
        std::swap(p, q);
    }
    if (inverse) {
        T inv = T(1) / T(N);
        for (int i = 0; i < N; ++i) p[i] *= inv;
    }
    return p;
}
template<typename T>
std::vector<T> operator*(std::vector<T> p, std::vector<T> q) {
    int N = p.size() + q.size() - 1, M = 1;
    while (M < N) M <<= 1;
    p.resize(M), q.resize(M);
    auto phat = fft(p, false), qhat = fft(q, false);
    for (int i = 0; i < M; ++i) {
        phat[i] *= qhat[i];
    }
    auto r = fft(phat, true);
    r.resize(N);
    return r;
}
template<typename T>
struct Combinatorics {
    std::vector<T> f, inv, pref, suff;
    Combinatorics(int N) : f(N), inv(N), pref(N), suff(N) {
        f[0] = inv[0] = 1;
        for (int x = 1; x < N; ++x) {
            f[x] = x * f[x - 1];
            inv[x] = 1 / f[x];
        }
    }
    T interpolate(const std::vector<T>& y, T x) {
        int n = y.size();
        pref[0] = suff[n - 1] = 1;
        for (int i = 0; i + 1 < n; ++i) {
            pref[i + 1] = pref[i] * (x - i);
        }
        for (int i = n - 1; i > 0; --i) {
            suff[i - 1] = suff[i] * (x - i);
        }
        T res = 0;
        for (int i = 0, sgn = (n % 2 ? +1 : -1); i < n; ++i, sgn *= -1) {
            res += y[i] * sgn * pref[i] * suff[i] * inv[i] * inv[n - 1 - i];
        }
        return res;
    }
    T C(int n, int k) {
        return k < 0 || n < k ? 0 : f[n] * inv[k] * inv[n - k];
    }
    T S(int n, int k) {
        return k == 0 ? n == 0 : C(n + k - 1, k - 1);
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> deg(N, -1);
    deg[0] = 0;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        ++deg[u], ++deg[v];
    }
    std::vector<int> freq(N);
    for (int u = 0; u < N; ++u) {
        ++freq[deg[u]];
    }
    Combinatorics<Zp> C(N + 1);
    std::vector<Zp> p = {1};
    for (int k = N - 1; k >= 0; --k) {
        std::vector<Zp> q(freq[k] + 1);
        for (int i = 0; i <= freq[k]; ++i) {
            q[i] = C.C(freq[k], i) * Zp(k).power(i);
        }
        p = p * q;
    }
    Zp ans = 0;
    for (int k = 0, sgn = 1; k < N; ++k, sgn *= -1) {
        ans += sgn * p[k] * C.f[N - k];
    }
    std::cout << ans << '\n';
    exit(0);
}