#include <iostream>
#include <numeric>
#include <vector>

template <int MOD>
struct ModInt {
    using lint = long long;
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(lint n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

template <class T>
struct Combination {
    int max_n;
    std::vector<T> f, invf;

    explicit Combination(int n)
        : max_n(n), f(n + 1), invf(n + 1) {
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }

        invf[max_n] = f[max_n].inv();
        for (int i = max_n - 1; i >= 0; --i) {
            invf[i] = invf[i + 1] * (i + 1);
        }
    }

    T fact(int n) const { return f[n]; }
    T invfact(int n) const { return invf[n]; }
    T perm(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b];
    }
    T comb(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b] * invf[b];
    }
};

using lint = long long;

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

const Combination<mint> C(1000000);

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    std::vector<lint> ps;
    {
        lint d;
        std::cin >> d;

        for (lint p = 2; p * p <= d; ++p) {
            if (d % p != 0) continue;
            ps.push_back(p);
            while (d % p == 0) d /= p;
        }

        if (d > 1) ps.push_back(d);
    }

    int m = ps.size();

    auto es = vec(m, vec(2, 0));

    int q;
    std::cin >> q;
    while (q--) {
        for (int i = 0; i < 2; ++i) {
            lint x;
            std::cin >> x;

            for (int j = 0; j < m; ++j) {
                int e = 0;
                while (x % ps[j] == 0) {
                    x /= ps[j];
                    ++e;
                }
                es[j][i] = e;
            }
        }

        mint div = 1;
        int usum = 0, dsum = 0;

        for (const auto& v : es) {
            int s = v[0], g = v[1];
            int d = std::abs(s - g);

            if (s >= g) {
                usum += d;
                div *= C.fact(s - g);
            } else {
                dsum += d;
                div *= C.fact(g - s);
            }
        }

        mint ans = C.fact(usum) * C.fact(dsum) / div;
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}