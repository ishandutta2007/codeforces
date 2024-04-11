#include <iostream>
#include <algorithm>
#include <vector>

struct ModInt {
    static int MOD;

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

int ModInt::MOD;
using mint = ModInt;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (n > m) {
        std::cout << 0 << std::endl;
        return;
    }

    ModInt::MOD = m;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.begin(), xs.end());

    std::vector<int> cnt(m, 0);
    mint ans = 1;
    for (auto x : xs) {
        x %= m;
        for (int i = 0; i < m; ++i) {
            ans *= mint(x - i).pow(cnt[i]);
        }
        ++cnt[x];
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}