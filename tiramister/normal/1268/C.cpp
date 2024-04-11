#include <iostream>
#include <vector>

using lint = long long;

struct SegmentTree {
    int length;
    std::vector<lint> dat;

    lint query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return 0;
        if (ql <= nl && nr <= qr) return dat[nidx];
        lint vl = query(ql, qr, nidx * 2, nl, (nl + nr) / 2);
        lint vr = query(ql, qr, nidx * 2 + 1, (nl + nr) / 2, nr);
        return vl + vr;
    }

    // half-open interval [ql, qr)
    lint query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    void update(int idx, lint newval) {
        int nidx = idx + length;
        dat[nidx] = newval;
        while (nidx > 0) {
            nidx >>= 1;
            dat[nidx] = dat[nidx * 2] + dat[nidx * 2 + 1];
        }
    }

    int binary_search(lint v) {
        int nidx = 1;
        while (nidx < length) {
            lint vl = dat[nidx * 2];
            if (vl >= v) {
                nidx = nidx * 2;
            } else {
                v -= vl;
                nidx = nidx * 2 + 1;
            }
        }
        return nidx - length;
    }

    explicit SegmentTree(int N) : length(1) {
        while (length < N) length <<= 1;
        dat.assign(length * 2, 0);
    }
};

lint seqsum(lint l, lint r) {
    return r * (r - 1) / 2 - l * (l - 1) / 2;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        int p;
        std::cin >> p;
        pos[p - 1] = i;
    }

    SegmentTree seg(n), segval(n);
    lint acc = 0;
    for (int k = 0; k < n; ++k) {
        acc += seg.query(pos[k], n);
        seg.update(pos[k], 1);
        segval.update(pos[k], pos[k]);

        int mi = k / 2;
        int midx = seg.binary_search(k / 2 + 1);
        lint med = midx - mi;

        lint ans = acc;
        ans += med * (k % 2 == 0);

        ans -= segval.query(0, midx + 1);
        ans += segval.query(midx + 1, n);

        ans += seqsum(0, mi + 1);
        ans -= seqsum(mi + 1, k + 1);

        std::cout << ans << ' ';
    }
    std::cout << std::endl;
    return 0;
}