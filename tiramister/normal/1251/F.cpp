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

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <int MOD, int Root>
struct NumberTheoreticalTransform {
    using mint = ModInt<MOD>;
    using mints = std::vector<mint>;

    std::vector<mint> zetas;

    explicit NumberTheoreticalTransform() {
        int exp = MOD - 1;
        while (true) {
            mint zeta = mint(Root).pow(exp);
            zetas.push_back(zeta);
            if (exp % 2 != 0) break;
            exp /= 2;
        }
    }

    void bitrev(mints& f) const {
        int n = f.size();

        for (int i = 0; i < n; ++i) {
            int ti = i, ni = 0;
            for (int k = 0; (1 << k) < n; ++k) {
                int b = (ti & 1);
                ti >>= 1;
                ni <<= 1;
                ni += b;
            }

            if (i < ni) {
                std::swap(f[i], f[ni]);
            }
        }
    }

    void udft(mints& f, bool isinv) const {
        if (f.size() <= 1) return;

        int l = 1;
        int k = 1 << l;
        int n = f.size();

        while (k <= n) {
            mint zeta = zetas[l];
            if (isinv) zeta = zeta.inv();

            for (int r = 0; r < n / k; ++r) {
                mint zetapow = 1;

                for (int j = 0; j < k / 2; ++j) {
                    int b = r * k + j;
                    mint t = zetapow * f[b + k / 2];

                    f[b + k / 2] = f[b] - t;
                    f[b] = f[b] + t;

                    zetapow *= zeta;
                }
            }

            ++l;
            k <<= 1;
        }
    }

    void dft(mints& f, bool isinv) const {
        bitrev(f);
        udft(f, isinv);
    }

    mints ntt(mints f, mints g) const {
        int fdeg = f.size(),
            gdeg = g.size();

        int k = 0;
        while ((1 << k) < fdeg + gdeg) {
            ++k;
        }

        int n = (1 << k);
        f.resize(n, mint(0));
        g.resize(n, mint(0));

        dft(f, false);
        dft(g, false);

        mints h(n);
        for (int i = 0; i < n; ++i) {
            h[i] = f[i] * g[i];
        }

        dft(h, true);
        while ((int)h.size() > fdeg + gdeg - 1) {
            h.pop_back();
        }
        for (auto& x : h) x /= n;
        return h;
    }
};

using NTT = NumberTheoreticalTransform<MOD, 3>;
const NTT Ntt;

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

constexpr int X = 300000;
const Combination<mint> C(X);

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> cnt(X, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ++cnt[--a];
    }

    std::vector<int> bs;
    std::vector<std::vector<mint>> fs(k);
    for (auto& f : fs) {
        int b;
        std::cin >> b;
        bs.push_back(b--);

        int one = 0, two = 0;
        for (int h = 0; h < b; ++h) {
            if (cnt[h] == 1) {
                ++one;
            } else if (cnt[h] > 1) {
                ++two;
            }
        }

        std::vector<mint> g(one + 1);
        for (int i = 0; i <= one; ++i) {
            g[i] = C.comb(one, i) * mint(2).pow(i);
        }

        std::vector<mint> h(two * 2 + 1);
        for (int i = 0; i <= two * 2; ++i) {
            h[i] = C.comb(two * 2, i);
        }

        f = Ntt.ntt(g, h);
    }

    int q;
    std::cin >> q;
    while (q--) {
        int x;
        std::cin >> x;

        mint ans = 0;
        for (int i = 0; i < k; ++i) {
            int j = x / 2 - bs[i] - 1;
            if (0 <= j && j < (int)fs[i].size()) ans += fs[i][j];
        }

        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
    return 0;
}