#include <iostream>
#include <numeric>
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
        while ((1 << k) < fdeg + gdeg) ++k;

        int n = (1 << k);
        f.resize(n, mint(0));
        g.resize(n, mint(0));

        dft(f, false);
        dft(g, false);

        mints h(n);
        for (int i = 0; i < n; ++i) h[i] = f[i] * g[i];

        dft(h, true);
        h.resize(fdeg + gdeg - 1);
        for (auto& x : h) x /= n;
        return h;
    }
};

struct UnionFind {
    std::vector<int> par, sz;
    int gnum;

    explicit UnionFind(int n)
        : par(n), sz(n, 1), gnum(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return (par[v] == v) ? v : (par[v] = find(par[v]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) std::swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return sz[find(v)]; }
};

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;
const NumberTheoreticalTransform<MOD, 3> NTT;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length(), m = t.length();

    std::vector<UnionFind> ufs(n, UnionFind(6));
    for (int u = 0; u < 6; ++u) {
        for (int v = 0; v < 6; ++v) {
            char c = 'a' + u;
            std::vector<mint> xs(n, 0);
            for (int i = 0; i < n; ++i) {
                if (s[i] == c) xs[i] = 1;
            }

            char d = 'a' + v;
            std::vector<mint> ys(m, 0);
            for (int i = 0; i < m; ++i) {
                if (t[i] == d) ys[m - 1 - i] = 1;
            }

            auto zs = NTT.ntt(xs, ys);
            for (int i = 0; i < n; ++i) {
                if (zs[i + m - 1] != 0) ufs[i].unite(u, v);
            }
        }
    }

    for (int i = 0; i <= n - m; ++i) {
        std::cout << 6 - ufs[i].gnum << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}