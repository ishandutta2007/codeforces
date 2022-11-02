#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

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
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

mint comb(int n, int m) {
    mint ret = 1;
    for (int i = 1; i <= m; ++i) {
        ret *= n - i + 1;
        ret /= i;
    }
    return ret;
}

void solve() {
    int n;
    std::cin >> n;

    mint prod = 1;
    std::vector<int> ls(n), rs(n), xs;
    for (int i = n - 1; i >= 0; --i) {
        std::cin >> ls[i] >> rs[i];
        ++rs[i];
        prod *= rs[i] - ls[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) ls[i] = std::max(ls[i - 1], ls[i]);
        if (i + 1 < n) rs[i] = std::min(rs[i + 1], rs[i]);

        if (rs[i] <= ls[i]) {
            std::cout << 0 << std::endl;
            return;
        }

        xs.push_back(ls[i]);
        xs.push_back(rs[i]);
    }

    auto rev = compress(xs);
    for (auto& l : ls) l = rev[l];
    for (auto& r : rs) r = rev[r];

    int m = xs.size();

    auto dp = vec(n, vec(m, mint(0)));
    for (int x = ls[0]; x < rs[0]; ++x) {
        dp[0][x] = (xs[x + 1] - xs[x]);
    }

    for (int i = 1; i < n; ++i) {
        for (int k = ls[i]; k < rs[i]; ++k) {
            int len = xs[k + 1] - xs[k];

            for (int j = i; j >= 0 && k < rs[j]; --j) {
                mint sum = 0;
                if (j == 0) {
                    sum = 1;
                } else {
                    for (int p = 0; p < k; ++p) {
                        sum += dp[j - 1][p];
                    }
                }

                dp[i][k] += comb(len + i - j, i - j + 1) * sum;
            }
        }
    }

    mint ans = std::accumulate(dp.back().begin(), dp.back().end(), mint(0));
    std::cout << ans / prod << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}