#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

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
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
        lint v;
        is >> v;
        x = v;
        return is;
    }
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

    T fact(int n) const { return n < 0 ? T(0) : f[n]; }
    T invfact(int n) const { return n < 0 ? T(0) : invf[n]; }
    T perm(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b];
    }
    T binom(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b] * invf[b];
    }
};

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;
const Combination<mint> C(500000);

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> ins(n + 1), outs(n + 1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        ins[l].push_back(i);
        outs[r].push_back(i);
    }

    std::vector<std::pair<int, int>> es(m);
    std::vector<int> vs;  // 
    for (auto& [u, v] : es) {
        std::cin >> u >> v;
        vs.push_back(--u);
        vs.push_back(--v);
    }

    auto vrev = compress(vs);
    int k = vrev.size();
    for (auto& [u, v] : es) u = vrev[u], v = vrev[v];

    // x
    std::vector<mint> ind(k + 1);

    // sind
    auto calc_ind = [&](lint s) {
        std::fill(ind.begin(), ind.end(), 0);

        for (int b = 0; b < (1 << m); ++b) {
            lint t = 0;  // 
            for (int i = 0; i < m; ++i) {
                if ((~b >> i) & 1) continue;
                auto [u, v] = es[i];
                t |= 1LL << u;
                t |= 1LL << v;
            }

            if (~s & t) continue;  // s

            int used = __builtin_popcountll(s & t);  // 
            int cnt = __builtin_popcountll(s & ~t);  // 

            mint sign = mint(-1).pow(__builtin_popcount(b));
            for (int z = 0; z <= cnt; ++z) {
                ind[z + used] += sign * C.binom(cnt, z);
            }
        }
    };

    mint ans = 0;
    int num = 0;    // 
    lint mask = 0;  // 
    calc_ind(mask);

    for (int x = 1; x <= n; ++x) {
        // 
        for (auto v : ins[x]) {
            if (vrev.count(v)) {
                mask ^= 1LL << vrev[v];
                calc_ind(mask);
            } else {
                ++num;
            }
        }

        for (int z = 0; z <= k; ++z) {
            // x-zz
            ans += C.binom(num, x - z) * ind[z];
        }

        // 
        for (auto v : outs[x]) {
            if (vrev.count(v)) {
                mask ^= 1LL << vrev[v];
                calc_ind(mask);
            } else {
                --num;
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}