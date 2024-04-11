#include <iostream>
#include <vector>
#include <string>

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

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    auto front = vec(2, vec(n + 1, vec(n + 1, mint(0))));
    front[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            auto cur = front[0][i][k] + front[1][i][k];
            if (s[i] == '(' || s[i] == '?') front[0][i + 1][k + 1] += cur;
            if (s[i] == ')' || s[i] == '?') front[1][i + 1][k + 0] += cur;
        }
    }

    auto back = vec(2, vec(n + 1, vec(n + 1, mint(0))));
    back[0][n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int k = 0; k < n; ++k) {
            auto cur = back[0][i + 1][k] + back[1][i + 1][k];
            if (s[i] == '(' || s[i] == '?') back[0][i][k + 0] += cur;
            if (s[i] == ')' || s[i] == '?') back[1][i][k + 1] += cur;
        }
    }

    mint ans = 0;
    for (int i = 1; i < n; ++i) {
        mint acc = 0;
        for (int k = n; k > 0; --k) {
            acc += back[0][i][k] + back[1][i][k];
            ans += front[0][i][k] * acc;
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}