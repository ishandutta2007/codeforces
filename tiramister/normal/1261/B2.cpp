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

struct Query {
    int pos, id;
    Query(int pos, int id) : pos(pos), id(id) {}
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    std::vector<std::pair<int, int>> ps(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i];
        ps[i] = std::make_pair(xs[i], -i);
    }
    std::sort(ps.rbegin(), ps.rend());

    int qn;
    std::cin >> qn;
    std::vector<std::vector<Query>> qs(n + 1);
    for (int i = 0; i < qn; ++i) {
        int k, pos;
        std::cin >> k >> pos;
        qs[k].emplace_back(pos, i);
    }

    std::vector<int> ans(qn);
    SegmentTree<int>
        seg(n, 0, [](auto a, auto b) { return a + b; });

    for (int k = 1; k <= n; ++k) {
        auto [x, i] = ps[k - 1];
        seg.update(-i, 1);

        for (auto q : qs[k]) {
            // ok(ok)q.pos
            int ok = 0, ng = n;
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                if (seg.fold(0, mid) < q.pos) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }

            ans[q.id] = ok;
        }
    }

    for (auto i : ans) std::cout << xs[i] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}