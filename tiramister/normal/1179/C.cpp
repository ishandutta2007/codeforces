#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

template <class T, class E>
struct LazySegmentTree {
    int length;
    std::vector<T> dat;
    std::vector<E> ope;

    void eval(int nidx, int len) {
        if (ope[nidx] == 0) return;

        // propagate
        if (len > 1) {
            ope[nidx * 2 + 0] += ope[nidx];
            ope[nidx * 2 + 1] += ope[nidx];
        }

        // update data
        dat[nidx] += ope[nidx];
        ope[nidx] = 0;
    }

    void update(int ql, int qr, E e, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return;
        if (ql <= nl && nr <= qr) {
            ope[nidx] += e;
            eval(nidx, nr - nl);
            return;
        }

        int nm = (nl + nr) / 2;
        update(ql, qr, e, nidx * 2 + 0, nl, nm);
        update(ql, qr, e, nidx * 2 + 1, nm, nr);

        // update data
        dat[nidx] = std::max(dat[nidx * 2 + 0], dat[nidx * 2 + 1]);
    }

    void update(int ql, int qr, E e) { return update(ql, qr, e, 1, 0, length); }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return 0;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 1, nm, nr);
        return std::max(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    explicit LazySegmentTree(int n)
        : length(1) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, 0);
        ope.assign(length * 2, 0);
    }

    int binsearch(int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr - nl <= 1) return nl;

        int nm = (nl + nr) / 2;
        eval(nidx * 2 + 1, nr - nm);
        T vr = dat[nidx * 2 + 1];

        if (vr > 0) {
            return binsearch(nidx * 2 + 1, nm, nr);
        } else {
            return binsearch(nidx * 2 + 0, nl, nm);
        }
    }

    // find max index i which satisfies dat[i] > 0
    int binsearch() {
        eval(1, length);
        if (dat[1] <= 0) {
            return -1;
        } else {
            return binsearch(1, 0, length);
        }
    }
};

constexpr int L = 1000000;

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n), ys(m);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    LazySegmentTree<int, int> seg(L + 1);
    // hold #x - #y (no less than i)
    // if positive, you can buy it

    for (auto x : xs) seg.update(0, x + 1, 1);
    for (auto y : ys) seg.update(0, y + 1, -1);

    int q;
    std::cin >> q;
    while (q--) {
        int t, i, x;
        std::cin >> t >> i >> x;
        --i;

        if (t == 1) {
            int px = xs[i];
            xs[i] = x;

            seg.update(0, px + 1, -1);
            seg.update(0, xs[i] + 1, 1);
        } else {
            int py = ys[i];
            ys[i] = x;

            seg.update(0, py + 1, 1);
            seg.update(0, ys[i] + 1, -1);
        }

        std::cout << seg.binsearch() << "\n";
    }
    return 0;
}