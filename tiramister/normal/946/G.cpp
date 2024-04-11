#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

constexpr int INF = 1 << 30;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs, zs;
    xs.reserve(n + 1);
    zs.reserve((n + 1) * 2);
    for (int i = 0; i <= n; ++i) {
        int x;
        if (i < n) {
            std::cin >> x;
        } else {
            x = INF;
        }
        x -= i;

        xs.push_back(x);
        zs.push_back(x);
        zs.push_back(x + 1);
    }

    auto rev = compress(zs);
    for (auto& x : xs) x = rev[x];
    int m = zs.size();

    SegmentTree<int>
        pseg(m, 0, [](auto a, auto b) { return std::max(a, b); }),
        nseg(m, 0, [](auto a, auto b) { return std::max(a, b); });

    for (int i = 0; i <= n; ++i) {
        // normal transition
        nseg.update(xs[i], nseg.query(0, xs[i] + 1) + 1);

        if (i > 0) {
            // skip x_{i - 1}
            nseg.update(xs[i], std::max(nseg.query(xs[i], xs[i] + 1),
                                        pseg.query(0, xs[i] + 2) + 2));
            // normal transition
            pseg.update(xs[i - 1], pseg.query(0, xs[i - 1] + 1) + 1);
        }
    }

    std::cout << (n + 1) - nseg.query(0, m) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}