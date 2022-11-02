#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

template <class T, class E>
struct LazySegmentTree {
    using DMerger = std::function<T(T, T)>;
    using OMerger = std::function<E(E, E)>;
    using Applier = std::function<T(T, E, int)>;

    int length;

    T d_unit;
    E o_unit;

    std::vector<T> dat;
    std::vector<E> ope;

    DMerger dmerge;
    OMerger omerge;
    Applier app;

    explicit LazySegmentTree(int n,
                             T d_unit, E o_unit,
                             DMerger dmerge,
                             OMerger omerge,
                             Applier app)
        : length(1),
          d_unit(d_unit),
          o_unit(o_unit),
          dmerge(dmerge),
          omerge(omerge),
          app(app) {
        while (length < n) length <<= 1;

        dat.assign(length * 2, d_unit);
        ope.assign(length * 2, o_unit);
    }

    template <class Container>
    explicit LazySegmentTree(const Container& elems,
                             T d_unit, E o_unit,
                             DMerger dmerge,
                             OMerger omerge,
                             Applier app)
        : length(1),
          d_unit(d_unit),
          o_unit(o_unit),
          dmerge(dmerge),
          omerge(omerge),
          app(app) {
        int n = elems.size();
        while (length < n) length <<= 1;

        dat.assign(length * 2, d_unit);
        ope.assign(length * 2, o_unit);

        std::copy(elems.begin(), elems.end(), dat.begin() + length);

        for (int nidx = length - 1; nidx >= 1; --nidx) {
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = dmerge(vl, vr);
        }
    }

    void propagate(int nidx, int len) {
        if (ope[nidx] == o_unit) return;

        // propagate
        if (len > 1) {
            ope[nidx * 2 + 0] = omerge(ope[nidx * 2 + 0], ope[nidx]);
            ope[nidx * 2 + 1] = omerge(ope[nidx * 2 + 1], ope[nidx]);
        }

        // update data
        dat[nidx] = app(dat[nidx], ope[nidx], len);
        ope[nidx] = o_unit;
    }

    void update(int ql, int qr, E e, int nidx, int nl, int nr) {
        propagate(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return;
        if (ql <= nl && nr <= qr) {
            ope[nidx] = omerge(ope[nidx], e);
            propagate(nidx, nr - nl);
            return;
        }

        int nm = (nl + nr) / 2;
        update(ql, qr, e, nidx * 2 + 0, nl, nm);
        update(ql, qr, e, nidx * 2 + 1, nm, nr);

        // update data
        dat[nidx] = dmerge(dat[nidx * 2 + 0], dat[nidx * 2 + 1]);
    }

    void update(int ql, int qr, E e) { return update(ql, qr, e, 1, 0, length); }

    T fold(int ql, int qr, int nidx, int nl, int nr) {
        propagate(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return d_unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = fold(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = fold(ql, qr, nidx * 2 + 1, nm, nr);
        return dmerge(vl, vr);
    }

    T fold(int ql, int qr) { return fold(ql, qr, 1, 0, length); }

    T get(int idx) { return fold(idx, idx + 1); }
    T whole() { return fold(0, length); }
};

void solve() {
    int n, k, m;
    std::cin >> n >> k >> m;
    --k;

    LazySegmentTree<int, int>
        seg(
            n * 2, 0, 0,
            [](auto a, auto b) { return std::max(a, b); },
            [](auto e, auto f) { return e + f; },
            [](auto a, auto e, int) { return a + e; });
    for (int i = 0; i < n * 2; ++i) seg.update(i, i + 1, i);

    std::multiset<int> is{0};
    std::set<std::pair<int, int>> ps;
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;

        int i = y + std::abs(x - k);
        auto p = std::make_pair(x, y);

        if (ps.count(p)) {
            ps.erase(p);
            is.erase(is.find(i));
            seg.update(0, i + 1, -1);
        } else {
            ps.insert(p);
            is.insert(i);
            seg.update(0, i + 1, 1);
        }

        std::cout << std::max(seg.fold(0, *is.rbegin() + 1) - n, 0) << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}