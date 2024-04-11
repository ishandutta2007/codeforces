#include <iostream>
#include <algorithm>
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
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

struct RollingHash {
    int base, len;
    std::vector<mint> hash, bpow;

    RollingHash() = default;

    RollingHash(const std::string& s, int base)
        : base(base), len(s.length()), hash(len + 1), bpow(len + 1) {
        hash[0] = 0;
        bpow[0] = 1;

        for (int i = 0; i < len; ++i) {
            hash[i + 1] = hash[i] * base + s[i];
            bpow[i + 1] = bpow[i] * base;
        }
    }

    mint seghash(int b, int e) {
        return hash[e] - hash[b] * bpow[e - b];
    }
};

constexpr int base = 258391;

void solve() {
    int n, q;
    std::string s;
    std::cin >> n >> q >> s;

    std::vector<RollingHash> rhs(26);
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;

        auto t = s;
        for (auto& d : t) {
            if (d == c) {
                d = '1';
            } else {
                d = '0';
            }
        }

        rhs[i] = RollingHash(t, base);
    }

    while (q--) {
        int x, y, len;
        std::cin >> x >> y >> len;
        --x, --y;

        std::vector<mint> xhs(26), yhs(26);
        for (int i = 0; i < 26; ++i) {
            xhs[i] = rhs[i].seghash(x, x + len);
            yhs[i] = rhs[i].seghash(y, y + len);
        }

        std::sort(xhs.begin(), xhs.end());
        std::sort(yhs.begin(), yhs.end());

        std::cout << (xhs == yhs ? "YES" : "NO") << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}