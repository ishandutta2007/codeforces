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
using Zp = Z<(int)1e9 + 7>;
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
constexpr int Nmax = 1e5, Kmax = 100;
std::vector<Zp> eval[Kmax + 1];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<Zp> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> a[i];
    }
    Combinatorics<Zp> C(2 * N + 2 * Kmax + 1);
    for (int x = 0; x <= Kmax; ++x) {
        eval[x].resize(N + 2);
    }
    for (int j = 0; j < M; ++j) {
        int l, r, k;
        std::cin >> l >> r >> k;
        for (int x = 0; x <= Kmax; ++x) {
            Zp v = C.C(x + N - l + k, k);
            eval[x][l] += v;
            eval[x][r + 1] -= v;
        }
    }
    for (int x = 0; x <= Kmax; ++x) {
        std::partial_sum(eval[x].begin(), eval[x].end(), eval[x].begin());
    }
    for (int i = 1; i <= N; ++i) {
        std::vector<Zp> p(Kmax + 1);
        for (int x = 0; x <= Kmax; ++x) {
            p[x] = eval[x][i];
        }
        std::cout << a[i] + C.interpolate(p, i - N) << "\n "[i < N];
    }
    exit(0);
}