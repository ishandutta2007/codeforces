#include <iostream>
#include <algorithm>
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

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ls(n), rs(n);
    for (auto& l : ls) std::cin >> l;
    for (auto& r : rs) {
        std::cin >> r;
        ++r;
    }

    std::vector<mint> ps(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        int l = std::max(ls[i + 0], ls[i + 1]),
            r = std::min(rs[i + 0], rs[i + 1]);
        int len = std::max(0, r - l);

        ps[i] = mint(1) -
                mint(len) /
                    (rs[i + 0] - ls[i + 0]) /
                    (rs[i + 1] - ls[i + 1]);
    }

    mint ans = std::accumulate(ps.begin(), ps.end(), mint(0)) + 1;
    ans *= ans;

    for (int i = 0; i + 1 < n; ++i) {
        ans -= ps[i] * ps[i];
        ans += ps[i];
    }

    for (int i = 0; i + 2 < n; ++i) {
        ans -= ps[i + 0] * ps[i + 1] * 2;

        mint p = (mint(1) - ps[i + 0]) +
                 (mint(1) - ps[i + 1]);

        int l = std::max({ls[i + 0],
                          ls[i + 1],
                          ls[i + 2]}),
            r = std::min({rs[i + 0],
                          rs[i + 1],
                          rs[i + 2]});
        int len = std::max(0, r - l);

        p -= mint(len) /
             (rs[i + 0] - ls[i + 0]) /
             (rs[i + 1] - ls[i + 1]) /
             (rs[i + 2] - ls[i + 2]);

        ans += (mint(1) - p) * 2;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}