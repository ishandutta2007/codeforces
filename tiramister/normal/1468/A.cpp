#line 2 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/DataStructure/segment_tree.hpp"

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
#line 2 "main.cpp"
#include <iostream>
#include <algorithm>
#line 5 "main.cpp"

using namespace std;
constexpr int INF = 1 << 30;

void solve() {
    int n;
    cin >> n;

    vector<int> xs(n);
    for (auto& x : xs) {
        cin >> x;
        --x;
    }

    vector<vector<int>> to(n);
    {
        SegmentTree<int>
            seg(n, -1, [](auto a, auto b) { return max(a, b); });

        for (int i = 0; i < n; ++i) {
            int j = seg.fold(xs[i] + 1, n);
            if (j != -1) to[j].push_back(i);
            seg.update(xs[i], i);
        }
    }

    vector<int> down(n, -INF);
    SegmentTree<int>
        seg(n, -INF, [](auto a, auto b) { return max(a, b); });
    seg.update(0, 0);

    for (int i = 0; i < n; ++i) {
        for (auto j : to[i]) {
            int c = seg.fold(0, xs[j] + 1);
            down[j] = c + 2;
        }
        int c = seg.fold(0, xs[i] + 1);
        seg.update(xs[i], max(c + 1, down[i]));
    }

    cout << seg.fold_all() << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}