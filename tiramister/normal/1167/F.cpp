#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <functional>

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
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    explicit SegmentTree(int n, T unit, Merger merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2 - 1, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 1, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 2, nm, nr);
        return merge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 0, 0, length); }

    void update(int nidx, T elem) {
        nidx += length - 1;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx = (nidx - 1) >> 1;
            T vl = dat[nidx * 2 + 1];
            T vr = dat[nidx * 2 + 2];
            dat[nidx] = merge(vl, vr);
        }
    }
};

// example:
// SegmentTree<int>(n, 0, [](int a, int b) { return a + b; });

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        pos[a] = i;
    }

    SegmentTree<mint>
        left(n, 0, [](mint a, mint b) { return a + b; }),
        right(n, 0, [](mint a, mint b) { return a + b; });

    mint ans = 0;
    for (auto p : pos) {
        mint a;
        int i;
        std::tie(a, i) = p;

        mint l = i + 1, r = n - i;
        mint sum = l * r + left.query(0, i) * r + right.query(i, n) * l;
        ans += sum * a;
        left.update(i, l);
        right.update(i, r);
    }

    std::cout << ans << std::endl;
    return 0;
}