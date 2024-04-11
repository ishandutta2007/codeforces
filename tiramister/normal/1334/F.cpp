#include <iostream>
#include <vector>
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

    void eval(int nidx, int len) {
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
        eval(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return;
        if (ql <= nl && nr <= qr) {
            ope[nidx] = omerge(ope[nidx], e);
            eval(nidx, nr - nl);
            return;
        }

        int nm = (nl + nr) / 2;
        update(ql, qr, e, nidx * 2 + 0, nl, nm);
        update(ql, qr, e, nidx * 2 + 1, nm, nr);

        // update data
        dat[nidx] = dmerge(dat[nidx * 2 + 0], dat[nidx * 2 + 1]);
    }

    void update(int ql, int qr, E e) { return update(ql, qr, e, 1, 0, length); }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return d_unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 1, nm, nr);
        return dmerge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    explicit LazySegmentTree(int n, T d_unit, E o_unit,
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
};

using lint = long long;

constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<lint> ps(n);
    for (auto& p : ps) std::cin >> p;

    int m;
    std::cin >> m;

    std::vector<int> ys(m);
    for (auto& y : ys) std::cin >> y;

    LazySegmentTree<lint, lint>
        seg(
            m + 1, 0LL, 0LL,
            [&](auto a, auto b) { return a + b; },
            [&](auto e, auto f) { return e + f; },
            [&](auto a, auto e, int k) { return a + e * k; });
    seg.update(1, m + 1, INF);

    for (int i = 0; i < n; ++i) {
        auto x = xs[i];
        auto p = ps[i];

        int j = std::lower_bound(ys.begin(), ys.end(), x) - ys.begin();
        auto prev = seg.query(j, j + 1);

        seg.update(0, j + 1, p);
        seg.update(j + 1, m + 1, std::min(p, 0LL));

        if (j >= m || x != ys[j]) continue;

        auto nxt = seg.query(j + 1, j + 2);
        if (nxt > prev) {
            seg.update(j + 1, j + 2, prev - nxt);
        }
    }

    auto ans = seg.query(m, m + 1);
    if (ans >= INF / 2) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl
              << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}