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

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ns{n - n / 2, n / 2};

    std::vector<std::vector<std::pair<int, int>>> pss(2);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x != -1) pss[i % 2].emplace_back(x, i / 2);
    }

    mint ans = 1;
    for (int t = 0; t < 2; ++t) {
        const auto& ps = pss[t];
        if (ps.empty()) {
            ans *= mint(k) * mint(k - 1).pow(ns[t] - 1);
            continue;
        }

        mint pat = mint(k - 1).pow(ps.front().second +
                                   (ns[t] - ps.back().second - 1));

        for (int i = 0; i + 1 < (int)ps.size(); ++i) {
            int len = ps[i + 1].second - ps[i].second - 1;
            bool same = ps[i].first == ps[i + 1].first;

            std::vector<mint> dp(2, 0);
            dp[same ? 0 : 1] = 1;
            auto ndp = dp;

            while (len--) {
                ndp[0] = dp[0] * 0 + dp[1] * 1;
                ndp[1] = dp[0] * (k - 1) + dp[1] * (k - 2);
                dp = ndp;
            }

            pat *= dp[1];
        }

        ans *= pat;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}