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

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

int main() {
    int n, x;
    std::string t;
    std::cin >> n >> x >> t;

    auto sdp = vec(x + 2, vec(n + 1, vec(n + 1, mint(0))));
    auto pdp = sdp, adp = sdp;
    auto cnts = vec(x + 2, mint(0));    // 
    auto lenpow = vec(x + 2, mint(0));  // 2^|F(k)|

    // 
    for (int k = 0; k < 2; ++k) {
        std::string s(1, '0' + k);  // F(k)

        for (int l = 0; l <= n; ++l) {
            // 
            sdp[k][l][l] = 2;
            pdp[k][l][l] = 2;
            adp[k][l][l] = 1;

            if (s == t.substr(l, 1)) {
                sdp[k][l][l + 1] = 1;
                pdp[k][l][l + 1] = 1;
                adp[k][l][l + 1] = 1;
            }
        }
        cnts[k] = adp[k][0][n];
        lenpow[k] = 2;
    }

    for (int k = 2; k <= x; ++k) {
        lenpow[k] = lenpow[k - 1] * lenpow[k - 2];

        for (int l = 0; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                pdp[k][l][r] = 0;
                sdp[k][l][r] = 0;
                adp[k][l][r] = 0;

                for (int i = l; i <= r; ++i) {
                    // F(k-1)[l, i)
                    pdp[k][l][r] += (i == r ? pdp : adp)[k - 1][l][i] * pdp[k - 2][i][r];
                    sdp[k][l][r] += sdp[k - 1][l][i] * (i == l ? sdp : adp)[k - 2][i][r];
                    adp[k][l][r] += adp[k - 1][l][i] * adp[k - 2][i][r];
                }
            }
        }

        // 
        cnts[k] = cnts[k - 1] * lenpow[k - 2] + cnts[k - 2] * lenpow[k - 1];
        for (int i = 1; i < n; ++i) {
            cnts[k] += sdp[k - 1][0][i] * pdp[k - 2][i][n];
        }
    }

    std::cout << cnts[x] << std::endl;
    return 0;
}