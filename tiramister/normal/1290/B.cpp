#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
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
    std::string s;
    std::cin >> s;
    int n = s.length();

    int q;
    std::cin >> q;
    std::vector<std::tuple<int, int, int>> qs;
    qs.reserve(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        qs.emplace_back(r, l, i);
    }
    std::sort(qs.begin(), qs.end());

    std::vector<bool> ans(q);

    SegmentTree<int> seg(n + 1, 0, [&](auto a, auto b) { return a + b; });
    int ridx = 0;
    std::vector<int> prev(26, 0);
    for (auto t : qs) {
        int i, l, r;
        std::tie(r, l, i) = t;
        while (ridx < r) {
            ++ridx;
            int c = s[ridx - 1] - 'a';
            seg.update(prev[c], 0);
            seg.update(ridx, 1);
            prev[c] = ridx;
        }

        int num = seg.query(l, r + 1);
        if (num == 1) {
            ans[i] = (l == r);
        } else if (num == 2) {
            ans[i] = (s[l - 1] != s[r - 1]);
        } else {
            ans[i] = true;
        }
    }

    for (auto a : ans) {
        std::cout << (a ? "Yes" : "No") << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}