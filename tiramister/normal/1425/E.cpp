#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    SegmentTree() = default;

    SegmentTree(int n, const T& unit, const Merger& merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    template <class Container>
    SegmentTree(const Container& elems, const T& unit, const Merger& merge)
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
    T fold_all() const { return dat[1]; }
};

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<lint> as(n), ds(n);
    for (auto& a : as) std::cin >> a;
    for (auto& d : ds) std::cin >> d;

    // i
    SegmentTree<lint>
        seg(n, 0, [](auto a, auto b) { return std::max(a, b); });
    {
        lint sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += as[i];
            seg.update(i, sum - ds[i]);
        }
    }

    lint ans = 0;

    if (k != 1) {
        // move 0
        ans = std::max(ans, seg.fold_all());
    }

    if (k >= 1) {
        // move 1

        // i -> i+2
        for (int i = 0; i + 2 < n; ++i) {
            auto front = std::max(0LL, seg.fold(0, i + 1) - as[i + 1]);
            front += std::max(0LL, as[i + 1] - ds[i + 1]);
            auto back = seg.fold(i + 1, n);
            ans = std::max(ans, std::max(front, back));
        }

        // i -> 0
        auto dmin = ds[0], asum = as[0];
        for (int i = 1; i < n - 1; ++i) {
            dmin = std::min(dmin, ds[i]);
            asum += as[i];

            auto front = std::max(0LL, asum - dmin);
            auto back = std::max(0LL, seg.fold(i + 1, n));

            ans = std::max(ans, front + back);
        }
    }

    if (k >= 2) {
        // move 2
        lint asum = std::accumulate(as.begin(), as.end(), 0LL);
        lint dmin = *std::min_element(ds.begin(), --ds.end());  // n-1
        ans = std::max(ans, asum - dmin);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}