#include <iostream>
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
constexpr int N = 1 << 10;

mint calc(lint n, int k) {
    // is leading zero, is tight, the set of the used digits
    auto dp = vec(2, vec(2, vec(N, mint(0))));
    auto ndp = dp;

    auto cnt = dp;
    auto ncnt = cnt;
    cnt[0][0][0] = cnt[0][1][0] = 1;

    mint ret = 0;
    mint ten = 1;
    while (n > 0) {
        for (int z = 0; z < 2; ++z) {
            for (int t = 0; t < 2; ++t) {
                std::fill(ndp[z][t].begin(), ndp[z][t].end(), 0);
                std::fill(ncnt[z][t].begin(), ncnt[z][t].end(), 0);
            }
        }

        int c = n % 10;
        n /= 10;

        for (int z = 0; z < 2; ++z) {
            for (int b = 0; b < N; ++b) {
                for (int d = 0; d <= 9; ++d) {
                    int nb = b | (1 << d);
                    int nz = (d == 0);

                    {
                        ndp[nz][0][nb] += dp[z][0][b] + ten * d * cnt[z][0][b];
                        ncnt[nz][0][nb] += cnt[z][0][b];
                    }

                    if (d < c) {
                        ndp[nz][1][nb] += dp[z][0][b] + ten * d * cnt[z][0][b];
                        ncnt[nz][1][nb] += cnt[z][0][b];
                    }

                    if (d == c) {
                        ndp[nz][1][nb] += dp[z][1][b] + ten * d * cnt[z][1][b];
                        ncnt[nz][1][nb] += cnt[z][1][b];
                    }
                }
            }
        }

        std::swap(dp, ndp);
        std::swap(cnt, ncnt);

        ten *= 10;

        for (int b = 0; b < N; ++b) {
            if (__builtin_popcount(b) <= k) ret += dp[0][n == 0][b];
        }
    }

    return ret;
}

void solve() {
    lint l, r;
    int k;
    std::cin >> l >> r >> k;

    std::cout << calc(r, k) - calc(l - 1, k) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}