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
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

constexpr int M = 1000000;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<mint> choosed(M, 0), cnt(M, 0);
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;

        for (int j = 0; j < k; ++j) {
            int a;
            std::cin >> a;
            --a;
            choosed[a] += (mint(n) * k).inv();
            cnt[a] += 1;
        }
    }

    mint ans = 0;
    for (int a = 0; a < M; ++a) {
        ans += choosed[a] * cnt[a] / n;
    }

    std::cout << ans << std::endl;
    return 0;
}