#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
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

    T fold(int ql, int qr) const {
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

    T get(int idx) const { return dat[idx + length]; }
    T whole() const { return dat[1]; }
};

using lint = long long;
constexpr lint INF = 1LL << 40;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<SegmentTree<std::array<lint, 2>>>
        segs(10, SegmentTree<std::array<lint, 2>>(
                     n, {INF, INF},
                     [](auto a, const auto& b) {
                         for (auto x : b) {
                             if (a[1] > x) a[1] = x;
                             if (a[0] > a[1]) std::swap(a[0], a[1]);
                         }
                         return a;
                     }));

    for (int i = 0; i < n; ++i) {
        lint x;
        std::cin >> x;

        auto y = x;
        for (auto& seg : segs) {
            if (y % 10 != 0) {
                seg.update(i, {x, INF});
            }
            y /= 10;
        }
    }

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int i;
            lint x;
            std::cin >> i >> x;
            --i;

            auto y = x;
            for (auto& seg : segs) {
                seg.update(i, {INF, INF});
                if (y % 10 != 0) {
                    seg.update(i, {x, INF});
                }
                y /= 10;
            }

        } else {
            int l, r;
            std::cin >> l >> r;
            --l;

            lint ans = INF;
            for (const auto& seg : segs) {
                auto res = seg.fold(l, r);
                ans = std::min(ans, res[0] + res[1]);
            }

            std::cout << (ans == INF ? -1 : ans) << "\n";
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}