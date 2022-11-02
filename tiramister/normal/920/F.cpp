#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

    T query(int ql, int qr) {
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

constexpr int X = 1000000;
using lint = long long;

std::vector<int> pcnt(X + 1, 1);

void init() {
    for (int p = 2; p <= X; ++p) {
        if (pcnt[p] > 1) continue;

        for (int q = p; q <= X; q += p) {
            int cnt = 0, x = q;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            pcnt[q] *= cnt + 1;
        }
    }
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    SegmentTree<lint>
        seg(n, 0, [&](auto a, auto b) { return a + b; });

    std::set<int> rems{n};
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        seg.update(i, x);
        if (pcnt[x] < x) rems.insert(i);
    }

    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        --l;

        if (t == 1) {
            auto it = rems.lower_bound(l);

            while (*it < r) {
                int i = *it;
                int x = seg.query(i, i + 1);
                x = pcnt[x];
                seg.update(i, x);

                if (pcnt[x] == x) {
                    it = rems.erase(it);
                } else {
                    ++it;
                }
            }
        } else {
            std::cout << seg.query(l, r) << "\n";
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    init();
    solve();

    return 0;
}