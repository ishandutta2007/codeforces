#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    SegmentTree() = default;

    SegmentTree(int n, const T& unit, const Merger& merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    template <class Container>
    SegmentTree(const Container& elems, const T& unit, const Merger& merge)
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

    T fold(int ql, int qr) const {
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

    T get(int idx) const { return dat[idx + length]; }
    T fold_all() const { return dat[1]; }
};

constexpr int INF = 1 << 20;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> ps(n), qs(m);
    for (auto& [x, y] : ps) std::cin >> x >> y;
    for (auto& [x, y] : qs) std::cin >> x >> y;
    qs.emplace_back(INF, -1);

    std::sort(ps.begin(), ps.end());
    std::sort(qs.begin(), qs.end());

    {
        std::vector<std::pair<int, int>> stk;
        for (auto q : qs) {
            while (!stk.empty() &&
                   stk.back().second <= q.second) {
                stk.pop_back();
            }
            stk.push_back(q);
        }
        std::swap(qs, stk);
        m = qs.size();
    }

    std::vector<std::vector<std::pair<int, int>>> mp(INF);
    std::vector<int> dys(n);
    for (int i = 0; i < n; ++i) {
        {
            dys[i] = std::max(0, qs[0].second - ps[i].second + 1);
        }

        for (int j = 1; j < m; ++j) {
            int dx = std::max(0, qs[j - 1].first - ps[i].first + 1);
            int dy = std::max(0, qs[j].second - ps[i].second + 1);
            mp[dx].emplace_back(i, dy);
        }
    }

    SegmentTree<int>
        seg(dys, -1, [](auto a, auto b) { return std::max(a, b); });
    int ans = seg.fold_all();

    for (int dx = 0; dx < INF; ++dx) {
        for (auto [i, dy] : mp[dx]) seg.update(i, dy);
        ans = std::min(ans, dx + seg.fold_all());
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}