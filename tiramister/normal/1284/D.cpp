#include <iostream>
#include <vector>
#include <functional>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < v.size(); ++i) {
        rev[v[i]] = i;
    }
    return rev;
}

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

struct Seg {
    int sa, ea, sb, eb;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Seg> segs(n);
    std::vector<int> coos;
    for (auto& s : segs) {
        std::cin >> s.sa >> s.ea >> s.sb >> s.eb;
        coos.push_back(s.sa);
        coos.push_back(s.ea);
        coos.push_back(s.sb);
        coos.push_back(s.eb);
    }

    auto rev = compress(coos);
    int m = coos.size();

    for (auto& s : segs) {
        s.sa = rev[s.sa];
        s.ea = rev[s.ea];
        s.sb = rev[s.sb];
        s.eb = rev[s.eb];
    }

    for (int q = 0; q < 2; ++q) {
        auto nsegs = segs;
        std::sort(segs.begin(), segs.end(),
                  [](Seg lhs, Seg rhs) { return lhs.sa < rhs.sa; });
        std::sort(nsegs.begin(), nsegs.end(),
                  [](Seg lhs, Seg rhs) { return lhs.ea < rhs.ea; });

        LazySegmentTree<int, int> segt(
            m, 0, 0,
            [](int a, int b) { return a + b; },
            [](int e, int f) { return e + f; },
            [](int e, int a, int k) { return a + e * k; });

        int idx = 0;
        for (auto& seg : segs) {
            while (idx < n && nsegs[idx].ea < seg.sa) {
                segt.update(nsegs[idx].sb, nsegs[idx].eb + 1, 1);
                ++idx;
            }

            if (segt.query(seg.sb, seg.eb + 1) > 0) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }

        for (auto& s : segs) {
            std::swap(s.sa, s.sb);
            std::swap(s.ea, s.eb);
        }
    }

    std::cout << "YES" << std::endl;
    return 0;
}