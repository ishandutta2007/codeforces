#include <iostream>
#include <vector>

using lint = long long;

template <int MOD>
struct ModInt {
    using lint = long long;
    using mint = ModInt<MOD>;

    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // assignment
    ModInt& operator=(const ModInt& x) {
        if (this != &x) { this->val = x.val; }
        return *this;
    }

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator~() const {
        // non-recursive extended euclidean algorithm
        int s = val, t = MOD;
        mint sx = 1, sy = 0, tx = 0, ty = 1;
        while (s % t != 0) {
            int div = s / t;
            s -= t * div;
            sx -= tx * div;
            sy -= ty * div;

            std::swap(s, t);
            std::swap(sx, tx);
            std::swap(sy, ty);
        }
        return mint(tx);
    }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }

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
    ModInt& operator/=(const ModInt& x) { return *this *= ~x; }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

template <int MOD>
class Combination {
    using mint = ModInt<MOD>;

private:
    int MAX_V;
    std::vector<mint> f, invf;

public:
    explicit Combination(int N)
        : MAX_V(N), f(MAX_V + 1), invf(MAX_V + 1) {
        f[0] = 1;
        for (int i = 1; i <= MAX_V; ++i) {
            f[i] = f[i - 1] * i;
        }

        invf[MAX_V] = ~f[MAX_V];
        for (int i = MAX_V - 1; i >= 0; --i) {
            invf[i] = invf[i + 1] * (i + 1);
        }
    }

    mint fact(int n) const { return f[n]; }
    mint invfact(int n) const { return invf[n]; }
    mint perm(int a, int b) const {
        return a < b ? mint(0) : f[a] * invf[a - b];
    }
    mint comb(int a, int b) const {
        return a < b ? mint(0) : f[a] * invf[a - b] * invf[b];
    }
};

const Combination<MOD> C(1000000);

template <class T, class Int>
T ipow(T b, Int n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= b;
        n >>= 1;
        b *= b;
    }
    return ret;
}

int main() {
    int n;
    lint m;
    std::cin >> n >> m;

    mint ans = 0, sum = 1;
    int mprev = 0;
    bool less = false;

    for (int k = 1; k <= n; ++k) {
        lint t;
        std::cin >> t;
        m -= t;

        if (m < 0) {
            sum = 0;
        } else if (less) {
            while (mprev > m) {
                sum -= C.comb(k - 1, mprev) / ipow(mint(2), k - 1);
                --mprev;
            }
            sum -= C.comb(k - 1, mprev) / ipow(mint(2), k);
        } else if (m < k) {
            less = true;
            sum = 0;
            for (int i = 0; i <= m; ++i) {
                sum += C.comb(k, i);
            }
            sum /= ipow(mint(2), k);
            mprev = m;
        }

        ans += sum;
    }

    std::cout << ans << std::endl;
    return 0;
}