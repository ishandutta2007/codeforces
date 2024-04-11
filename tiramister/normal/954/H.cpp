#include <iostream>
#include <algorithm>
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

    std::vector<int> xs(n - 1);
    for (auto& x : xs) std::cin >> x;

    std::vector<mint> szs(n, 1);
    for (int i = 0; i + 1 < n; ++i) {
        szs[i + 1] = szs[i] * xs[i];
    }

    std::vector<std::vector<mint>> dss(n);
    dss[n - 1] = {1};
    for (int i = n - 2; i >= 0; --i) {
        dss[i] = dss[i + 1];
        for (auto& d : dss[i]) d *= xs[i];
        dss[i].insert(dss[i].begin(), 1);
    }

    std::vector<mint> ans(n * 2 - 1, 0);
    std::vector<mint> pds(n - 1, 0);

    for (int i = 0; i < n; ++i) {
        auto& ds = dss[i];

        for (int j = 1; j < (int)ds.size(); ++j) {
            ans[j] += ds[j] * szs[i];
        }
        for (int j = 0; j < (int)pds.size(); ++j) {
            ans[j + 1] += pds[j] * szs[i];
        }

        if (i == n - 1) break;

        pds.insert(pds.begin(), 0);
        for (int j = 0; j < (int)ds.size(); ++j) {
            pds[j] += ds[j];
        }

        auto& nds = dss[i + 1];
        for (int j = 0; j < (int)nds.size(); ++j) {
            pds[j + 1] -= nds[j];
        }
    }

    for (int i = 1; i <= n * 2 - 2; ++i) {
        std::cout << ans[i] / 2 << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}