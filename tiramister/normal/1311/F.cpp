#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
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

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n), vs(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& v : vs) std::cin >> v;

    std::map<lint, int> rev;
    {
        auto nxs = xs;
        rev = compress(nxs);
    }

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
              [&](int i, int j) { return vs[i] != vs[j] ? vs[i] < vs[j] : xs[i] < xs[j]; });

    SegmentTree<lint>
        xseg(n, 0, [&](auto a, auto b) { return a + b; }),
        seg(n, 0, [&](auto a, auto b) { return a + b; });

    lint ans = 0;
    for (auto i : idx) {
        int p = rev[xs[i]];

        lint xsum = xseg.query(0, p + 1);
        lint num = seg.query(0, p + 1);
        ans += num * xs[i] - xsum;

        xseg.update(p, xseg.query(p, p + 1) + xs[i]);
        seg.update(p, seg.query(p, p + 1) + 1);
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