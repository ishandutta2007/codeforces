#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
using Vector = std::vector<T>;
template <class T>
using Matrix = Vector<Vector<T>>;

template <class T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
    int n = a.size(), m = b.size(), l = b.front().size();
    Matrix<T> ret(n, Vector<T>(l, 0));

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < l; ++k) {
            for (int j = 0; j < m; ++j) {
                ret[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return ret;
}

template <class T>
Vector<T> operator*(const Matrix<T>& a, const Vector<T>& v) {
    int n = a.size(), m = v.size();
    Vector<T> ret(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ret[i] += a[i][j] * v[j];
        }
    }
    return ret;
}

template <class T, class Int>
Matrix<T> mpow(Matrix<T> b, Int n) {
    Matrix<T> ret(b.size(), Vector<T>(b.size(), 0));
    for (int i = 0; i < (int)b.size(); ++i) ret[i][i] = 1;

    while (n > 0) {
        if (n & 1) ret = ret * b;
        n >>= 1;
        b = b * b;
    }
    return ret;
}

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

constexpr int N = 4 * 4 * 4;

std::vector<int> decode(int p) {
    std::vector<int> ret(3);
    for (int i = 0; i < 3; ++i) {
        ret[2 - i] = p % 4;
        p /= 4;
    }
    return ret;
}

int encode(const std::vector<int>& gs) {
    int ret = 0;
    for (auto g : gs) {
        ret = ret * 4 + g;
    }
    return ret;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<std::vector<std::pair<int, int>>> segs(n);
    {
        std::vector<std::vector<std::pair<int, int>>> cs(n);

        int m;
        std::cin >> m;
        while (m--) {
            int x, y, c;
            std::cin >> x >> y >> c;
            --x, --y, --c;
            cs[x].emplace_back(y, c);
        }

        for (int i = 0; i < n; ++i) {
            std::sort(cs[i].begin(), cs[i].end());

            int x = 0;
            for (auto [nx, c] : cs[i]) {
                if (nx > x) {
                    segs[i].emplace_back(nx - x, 3);
                }
                segs[i].emplace_back(1, c);
                x = nx + 1;
            }
            if (xs[i] > x) {
                segs[i].emplace_back(xs[i] - x, 3);
            }
        }
    }

    auto mats = vec(4, vec(N, vec(N, mint(0))));
    {
        auto fss = vec(3, vec(3, 0));
        for (auto& fs : fss) {
            for (auto& f : fs) std::cin >> f;
        }

        for (int p = 0; p < N; ++p) {
            auto gs = decode(p);
            std::vector<int> ngs{0, gs[0], gs[1]};

            for (int c = 0; c < 3; ++c) {
                std::vector<bool> app(4, false);

                for (int d = 0; d < 3; ++d) {
                    if (fss[c][d] == 0) continue;
                    app[gs[d]] = true;
                }

                auto& g = ngs[0];
                g = 0;
                while (app[g]) ++g;

                int q = encode(ngs);

                mats[c][q][p] += 1;
                mats[3][q][p] += 1;
            }
        }
    }

    auto skip = vec(30, vec(N, vec(N, mint(0))));
    skip[0] = mats[3];
    for (int i = 1; i < 30; ++i) {
        skip[i] = skip[i - 1] * skip[i - 1];
    }

    std::vector<mint> pat(4, 0);
    auto npat = pat;
    pat[0] = 1;

    int init = encode({3, 3, 3});

    for (int i = 0; i < n; ++i) {
        std::vector<mint> v(N, 0);
        v[init] = 1;

        for (auto [x, c] : segs[i]) {
            if (c != 3) {
                v = mats[c] * v;
            } else {
                int j = 0;
                while (x > 0) {
                    if (x & 1) v = skip[j] * v;
                    x >>= 1;
                    ++j;
                }
            }
        }

        std::fill(npat.begin(), npat.end(), 0);

        for (int p = 0; p < N; ++p) {
            int g = decode(p).front();
            for (int pg = 0; pg < 4; ++pg) {
                npat[g ^ pg] += pat[pg] * v[p];
            }
        }

        pat = npat;
    }

    std::cout << pat[0] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}