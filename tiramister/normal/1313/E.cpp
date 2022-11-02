#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <functional>

template <class Container>
std::vector<int> zalgo(const Container& dat) {
    int n = dat.size();

    std::vector<int> ret(n);
    ret[0] = n;

    int i = 1, len = 0;
    while (i < n) {
        while (i + len < n && dat[len] == dat[i + len]) {
            ++len;
        }
        ret[i] = len;

        if (len == 0) {
            ++i;
            continue;
        }

        int nlen = 1;
        while (i + nlen < n && nlen + ret[nlen] < len) {
            ret[i + nlen] = ret[nlen];
            ++nlen;
        }

        i += nlen;
        len -= nlen;
    }

    return ret;
}

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

using lint = long long;

void solve() {
    int n, m;
    std::vector<int> xs, ys;

    {
        std::string a, b, s;
        std::cin >> n >> m >> a >> b >> s;

        xs = zalgo(s + "$" + a);
        xs.erase(xs.begin(), xs.begin() + m + 1);

        std::reverse(b.begin(), b.end());
        std::reverse(s.begin(), s.end());

        ys = zalgo(s + "$" + b);
        ys.erase(ys.begin(), ys.begin() + m + 1);
        std::reverse(ys.begin(), ys.end());

        // for (auto x : xs) std::cerr << x << " ";
        // std::cerr << std::endl;

        // for (auto y : ys) std::cerr << y << " ";
        // std::cerr << std::endl;
    }

    for (auto& x : xs) x = std::min(x, m - 1);
    for (auto& y : ys) y = std::min(y, m - 1);
    for (auto& y : ys) y = y - m + 1;

    std::vector<int> xidxs(n), yidxs(n);

    std::iota(xidxs.begin(), xidxs.end(), 0);
    std::sort(xidxs.begin(), xidxs.end(),
              [&](int i, int j) { return xs[i] < xs[j]; });

    std::iota(yidxs.begin(), yidxs.end(), 0);
    std::sort(yidxs.begin(), yidxs.end(),
              [&](int i, int j) { return ys[i] > ys[j]; });

    SegmentTree<lint>
        yseg(n, 0, [](auto a, auto b) { return a + b; }),
        cseg(n, 0, [](auto a, auto b) { return a + b; });

    lint ans = 0;
    int yi = 0;
    for (auto xidx : xidxs) {
        auto x = xs[xidx];
        while (yi < n && ys[yidxs[yi]] >= -x) {
            yseg.update(yidxs[yi], ys[yidxs[yi]]);
            cseg.update(yidxs[yi], 1);
            ++yi;
        }
        ans += yseg.query(xidx, xidx + m - 1) +
               cseg.query(xidx, xidx + m - 1) * x;
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