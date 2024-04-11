#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
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
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::pair<int, lint>> xs(n);
    for (auto& p : xs) std::cin >> p.first >> p.second;

    std::vector<std::pair<int, lint>> ys(m);
    for (auto& p : ys) std::cin >> p.first >> p.second;

    std::vector<std::tuple<int, int, lint>> zs(q);
    for (auto& t : zs) {
        int x, y;
        lint z;
        std::cin >> x >> y >> z;
        t = std::make_tuple(x, y, z);
    }

    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());
    std::sort(zs.begin(), zs.end());

    LazySegmentTree<lint, lint>
        seg(
            m, -INF, 0,
            [](auto a, auto b) { return std::max(a, b); },
            [](auto e, auto f) { return e + f; },
            [](auto a, auto e, int k) { return a + e; });
    for (int i = 0; i < m; ++i) {
        seg.update(i, i + 1, INF - ys[i].second);
    }

    lint ans = -INF;
    int zidx = 0;
    for (auto p : xs) {
        int a;
        lint ca;
        std::tie(a, ca) = p;

        while (zidx < q) {
            int x, y;
            lint z;
            std::tie(x, y, z) = zs[zidx];
            if (x >= a) break;

            int yidx = std::lower_bound(ys.begin(), ys.end(),
                                        std::make_pair(y + 1, 0LL)) -
                       ys.begin();
            seg.update(yidx, m, z);
            ++zidx;
        }

        lint gain = seg.query(0, m) - ca;
        ans = std::max(ans, gain);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}