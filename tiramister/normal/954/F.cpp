#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

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

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

using lint = long long;

void solve() {
    int n;
    lint m;
    std::cin >> n >> m;

    std::vector<lint> xs{0, m - 1};
    std::vector<std::vector<std::pair<lint, lint>>> ps(3);
    while (n--) {
        int a;
        lint l, r;
        std::cin >> a >> l >> r;
        --a, --l;

        ps[a].emplace_back(l, r);
        xs.push_back(l);
        xs.push_back(r);
    }

    auto revx = compress(xs);
    n = xs.size();

    std::vector<int> pat(n, 0);
    for (int t = 0; t < 3; ++t) {
        std::vector<int> lpat(n, 0);
        for (auto p : ps[t]) {
            int l = revx[p.first],
                r = revx[p.second];
            ++lpat[l];
            --lpat[r];
        }

        for (int i = 0; i + 1 < n; ++i) {
            lpat[i + 1] += lpat[i];
        }

        for (int i = 0; i < n; ++i) {
            if (lpat[i] > 0) pat[i] |= (1 << t);
        }
    }

    auto mats = vec(8, vec(8, vec(3, vec(3, mint(0)))));
    for (int b = 0; b < 8; ++b) {
        for (int c = 0; c < 8; ++c) {
            for (int i = 0; i < 3; ++i) {
                if ((b >> i) & 1) continue;

                for (int j = 0; j < 3; ++j) {
                    if ((c >> j) & 1) continue;

                    if (std::abs(i - j) > 1) continue;
                    mats[b][c][j][i] = 1;
                }
            }
        }
    }

    std::vector<mint> ans{0, 1, 0};
    for (int i = 0; i + 1 < n; ++i) {
        lint len = xs[i + 1] - xs[i];

        ans = mpow(mats[pat[i]][pat[i]], len - 1) * ans;
        // if (len > 1) {
        //     std::cerr << len - 1 << ":"
        //               << std::bitset<3>(pat[i]) << "->"
        //               << std::bitset<3>(pat[i]) << "\n";
        //     for (auto a : ans) std::cerr << a << ' ';
        //     std::cerr << "\n";
        // }

        ans = mats[pat[i]][pat[i + 1]] * ans;

        // std::cerr << 1 << ":"
        //           << std::bitset<3>(pat[i]) << "->"
        //           << std::bitset<3>(pat[i + 1]) << "\n";
        // for (auto a : ans) std::cerr << a << ' ';
        // std::cerr << "\n";
    }

    std::cout << ans[1] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}