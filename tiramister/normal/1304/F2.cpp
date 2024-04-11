#include <iostream>
#include <algorithm>
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

constexpr int INF = 1 << 30;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> xs(m), dp(m + 1, -INF);
    dp[m] = 0;

    while (n--) {
        for (auto& x : xs) std::cin >> x;

        // [0, i)
        std::vector<int> psum(m + 1, 0);
        for (int l = 0; l < m; ++l) {
            psum[l + 1] = psum[l] + xs[l];
        }
        // [l, r)
        auto score = [&](int l, int r) {
            return psum[std::min(r, m)] - psum[std::max(0, l)];
        };

        LazySegmentTree<int, int>
            seg(
                m + 1, -INF, 0,
                [](auto a, auto b) { return std::max(a, b); },
                [](auto e, auto f) { return e + f; },
                [](auto a, auto e, int k) { return a + e; });

        // [0, k)
        for (int i = 0; i <= m; ++i) {
            seg.update(i, i + 1, score(std::max(i, k), i + k) + dp[i] + INF);
        }

        dp[0] = seg.query(0, m + 1) + score(0, k);
        for (int i = 1; i <= m; ++i) {
            seg.update(i - k, i, xs[i - 1]);
            if (i + k - 1 < m) seg.update(i, i + k, -xs[i + k - 1]);

            dp[i] = seg.query(0, m + 1) + score(i, i + k);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}