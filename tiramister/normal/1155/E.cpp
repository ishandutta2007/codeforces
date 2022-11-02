#include <iostream>
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

constexpr int MOD = 1000003;
using mint = ModInt<MOD>;

mint query(mint x) {
    std::cout << "? " << x << std::endl;

    mint y;
    std::cin >> y;
    return y;
}

constexpr int N = 11;

void solve() {
    std::vector<mint> ys(N);
    for (int x = 0; x < N; ++x) {
        ys[x] = query(x);
    }

    std::vector<mint> poly;
    for (int i = 0; i < N; ++i) {
        std::vector<mint> p{ys[i]};

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            // p *= x - x_j
            p.push_back(0);
            for (int k = (int)p.size() - 2; k >= 0; --k) {
                p[k + 1] += p[k];
                p[k] *= -j;
            }

            // p /= x_i - x_j
            for (auto& a : p) a /= mint(i - j);
        }

        poly.resize(p.size(), 0);

        for (int j = 0; j < (int)p.size(); ++j) {
            poly[j] += p[j];
        }
    }

    int ans = -1;
    for (int x = 0; x < MOD; ++x) {
        mint xx = 1;
        mint y = 0;

        for (int i = 0; i < N; ++i) {
            y += poly[i] * xx;
            xx *= x;
        }

        if (y == 0) {
            ans = x;
            break;
        }
    }

    std::cout << "! " << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}