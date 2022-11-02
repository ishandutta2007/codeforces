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
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
        lint v;
        is >> v;
        x = v;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1000000007;
using mint = ModInt<MOD>;

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    // 
    std::vector<int> mu(k + 1, 1);
    std::vector<bool> isp(k + 1, true);
    for (int p = 2; p <= k; ++p) {
        if (!isp[p]) continue;

        for (int q = p; q <= k; q += p) {
            mu[q] = -mu[q];
            isp[q] = false;
        }

        if (lint(p) * p > k) continue;
        for (int q = p * p; q <= k; q += p * p) mu[q] = 0;
    }

    // 
    std::vector<std::vector<int>> ds(k + 1);
    for (int p = 1; p <= k; ++p) {
        if (mu[p] == 0) continue;
        for (int q = p; q <= k; q += p) ds[q].push_back(p);
    }

    // n
    std::vector<mint> npow(k + 1);
    for (int p = 0; p <= k; ++p) npow[p] = mint(p).pow(n);

    mint ans = 0, sum = 0;
    std::vector<mint> fs(k + 1, 0);
    for (int g = 1; g <= k; ++g) {
        for (auto x : ds[g]) {
            sum -= fs[x] * mu[x];
            fs[x] = npow[g / x];
            sum += fs[x] * mu[x];
        }
        ans += (sum.val ^ g);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}