#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>

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
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    explicit SegmentTree(int n, const T& unit, const Merger& merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    template <class Container>
    explicit SegmentTree(const Container& elems, const T& unit, const Merger& merge)
        : length(1), unit(unit), merge(merge) {
        int n = elems.size();
        while (length < n) length <<= 1;

        dat.assign(length * 2, unit);

        std::copy(elems.begin(), elems.end(), dat.begin() + length);

        for (int nidx = length - 1; nidx >= 1; --nidx) {
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }

    void update(int nidx, const T& elem) {
        nidx += length;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx >>= 1;
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }

    T fold(int ql, int qr) {
        ql = std::max(ql, 0);
        qr = std::min(qr, length);
        ql += length, qr += length;

        T lacc = unit, racc = unit;
        while (ql < qr) {
            if (ql & 1) {
                lacc = merge(lacc, dat[ql]);
                ++ql;
            }
            if (qr & 1) {
                --qr;
                racc = merge(dat[qr], racc);
            }
            ql >>= 1, qr >>= 1;
        }

        return merge(lacc, racc);
    }

    T get(int idx) { return dat[idx + length]; }
    T whole() { return dat[1]; }
};

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

struct Frac {
    mint n, d;
    Frac() = default;
    Frac(mint n, mint d) : n(n), d(d) {}

    mint tom() const { return n / d; }
};

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<Frac> fs(n);
    for (auto& f : fs) {
        mint p;
        std::cin >> p;
        f = Frac(1, p / 100);
    }
    fs.emplace_back(0, 1);

    SegmentTree<Frac>
        seg(fs, Frac(0, 1), [](auto a, auto b) {
            return Frac(a.n + a.d * b.n, a.d * b.d);
        });

    mint ans = seg.fold(0, n).tom();

    std::set<int> idxs{0, n};
    while (q--) {
        int i;
        std::cin >> i;
        --i;

        if (idxs.count(i)) {
            int pi = *(--idxs.find(i));
            int ni = *(++idxs.find(i));
            ans -= seg.fold(pi, i).tom();
            ans -= seg.fold(i, ni).tom();

            idxs.erase(i);
            ans += seg.fold(pi, ni).tom();

        } else {
            int pi = *(--idxs.lower_bound(i));
            int ni = *idxs.lower_bound(i);
            ans -= seg.fold(pi, ni).tom();

            idxs.insert(i);
            ans += seg.fold(pi, i).tom();
            ans += seg.fold(i, ni).tom();
        }

        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}