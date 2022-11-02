#include <iostream>
#include <vector>
#include <functional>

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
        dat.assign(length * 2, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 1, nm, nr);
        return merge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    void update(int nidx, T elem) {
        nidx += length;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx >>= 1;
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    SegmentTree<int> seg(n + m, 0, [](auto a, auto b) { return a + b; });

    std::vector<int> mins(n), maxs(n), prev(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = n - i - 1;
        mins[i] = i + 1;
        maxs[i] = mins[i];
        seg.update(i, 1);
    }

    for (int j = n; j < n + m; ++j) {
        int x;
        std::cin >> x;
        --x;
        mins[x] = 1;
        maxs[x] = std::max(maxs[x], seg.query(prev[x], j));
        seg.update(prev[x], 0);
        seg.update(j, 1);
        prev[x] = j;
    }

    for (int x = 0; x < n; ++x) {
        maxs[x] = std::max(maxs[x], seg.query(prev[x], n + m));
        std::cout << mins[x] << " " << maxs[x] << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}