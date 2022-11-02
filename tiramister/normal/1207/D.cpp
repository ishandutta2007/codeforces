#include <iostream>
#include <algorithm>
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
struct Combination {
    int max_n;
    std::vector<T> f, invf;

    explicit Combination(int n)
        : max_n(n), f(n + 1), invf(n + 1) {
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }

        invf[max_n] = f[max_n].inv();
        for (int i = max_n - 1; i >= 0; --i) {
            invf[i] = invf[i + 1] * (i + 1);
        }
    }

    T fact(int n) const { return f[n]; }
    T invfact(int n) const { return invf[n]; }
    T perm(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b];
    }
    T comb(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b] * invf[b];
    }
};

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

const Combination<mint> C(1000000);

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ps(n);
    for (auto& p : ps) std::cin >> p.first >> p.second;

    mint ans = C.fact(n);
    for (int q = 0; q < 2; ++q) {
        std::map<int, int> cnt;
        for (auto p : ps) {
            int x = p.first;
            if (!cnt.count(x)) cnt[x] = 0;
            ++cnt[x];
        }

        mint out = 1;
        for (auto p : cnt) out *= C.fact(p.second);
        ans -= out;

        for (auto& p : ps) std::swap(p.first, p.second);
    }

    std::sort(ps.begin(), ps.end());
    bool sorted = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (ps[i].second > ps[i + 1].second) sorted = false;
    }

    std::map<std::pair<int, int>, int> cnt;
    for (auto p : ps) {
        if (!cnt.count(p)) cnt[p] = 0;
        ++cnt[p];
    }

    mint out = 1;
    for (auto p : cnt) out *= C.fact(p.second);

    if (sorted) ans += out;

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}