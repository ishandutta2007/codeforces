#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

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

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto firstbit = [&](lint x) {
        int i = m - 1;
        while (i >= 0) {
            if ((x >> i) & 1) break;
            --i;
        }
        return i;
    };

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<lint> bs;
    while (!xs.empty()) {
        int i = std::max_element(xs.begin(), xs.end()) - xs.begin();
        std::swap(xs.back(), xs[i]);
        if (xs.back() == 0) break;

        auto b = xs.back();
        xs.pop_back();

        for (auto& x : xs) x = std::min(x, x ^ b);
        for (auto& x : bs) x = std::min(x, x ^ b);

        bs.push_back(b);
    }

    int d = bs.size();
    std::vector<mint> cnt(m + 1, 0);

    if (d < 20) {
        for (lint b = 0; b < (1LL << d); ++b) {
            lint x = 0;
            for (int i = 0; i < d; ++i) {
                if ((b >> i) & 1) x ^= bs[i];
            }
            cnt[__builtin_popcountll(x)] += 1;
        }
    } else {
        {
            int j = m - 1;
            for (auto& b : bs) {
                int i = firstbit(b);

                for (auto& x : bs) {
                    int bi = ((x >> i) & 1),
                        bj = ((x >> j) & 1);
                    if (bi != bj) x ^= ((1LL << i) | (1LL << j));
                }

                b ^= (1LL << j);
                --j;
            }
        }

        int k = m - d;
        auto dp = vec(d + 1, vec(1LL << k, mint(0)));
        dp[0][0] = 1;

        for (auto b : bs) {
            for (int c = d; c > 0; --c) {
                for (lint x = 0; x < (1LL << k); ++x) {
                    dp[c][x ^ b] += dp[c - 1][x];
                }
            }
        }

        for (int c = 0; c <= d; ++c) {
            for (lint x = 0; x < (1LL << k); ++x) {
                cnt[c + __builtin_popcountll(x)] += dp[c][x];
            }
        }
    }

    for (auto c : cnt) {
        std::cout << c * mint(2).pow(n - d) << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}