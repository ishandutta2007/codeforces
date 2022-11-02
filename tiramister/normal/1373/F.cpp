#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

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

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    std::vector<lint> ss(n * 2 + 1, 0);
    for (int i = 0; i < n * 2; ++i) {
        ss[i + 1] = ss[i] + xs[i % n] - ys[i % n];
    }

    if (ss[n] > 0) {
        std::cout << "NO\n";
        return;
    }

    SegmentTree<lint>
        seg(ss, -INF,
            [](auto a, auto b) { return std::max(a, b); });

    for (int i = 0; i < n; ++i) {
        auto r = seg.fold(i, i + n);
        if (r - ss[i] - xs[i] > 0) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}