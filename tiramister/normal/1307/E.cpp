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

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> ss(n);
    for (auto& s : ss) {
        std::cin >> s;
        --s;
    }

    std::vector<std::vector<int>> hs(n);
    while (m--) {
        int f, h;
        std::cin >> f >> h;
        --f;
        hs[f].push_back(h);
    }

    std::vector<std::vector<std::pair<int, int>>> cows(n);
    for (int c = 0; c < n; ++c) {
        for (auto h : hs[c]) {
            int l = 0, eat = 0;
            while (l < n) {
                if (ss[l] == c) ++eat;
                if (eat == h) break;
                ++l;
            }
            if (l == n) continue;

            int r = n - 1;
            eat = 0;
            while (r >= 0) {
                if (ss[r] == c) ++eat;
                if (eat == h) break;
                --r;
            }
            if (r < 0) continue;

            cows[c].emplace_back(l, r);
        }
    }

    int maxnum = -1;
    mint ans = 0;
    for (int l = -1; l < n; ++l) {
        int num = 0;
        mint pat = 1;

        for (int c = 0; c < n; ++c) {
            bool just = (l >= 0 && ss[l] == c);

            lint lcnt = 0, rcnt = 0, lrcnt = 0;
            for (auto p : cows[c]) {
                bool lok = (just ? p.first == l : p.first <= l),
                     rok = p.second > l;
                if (lok) ++lcnt;
                if (rok) ++rcnt;
                if (lok && rok) ++lrcnt;
            }

            lint sz = lcnt + rcnt - lrcnt;
            if (lcnt > 0 && rcnt > 0 && sz > 1) {
                num += 2;
                pat *= (lcnt * rcnt - lrcnt);
            } else if (lcnt > 0 || rcnt > 0) {
                num++;
                pat *= (just ? lcnt : lcnt + rcnt);
            }

            if (just && lcnt == 0) {
                num = -1;
                break;
            }
        }

        if (num > maxnum) {
            maxnum = num;
            ans = pat;
        } else if (num == maxnum) {
            ans += pat;
        }
    }

    std::cout << maxnum << " " << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}