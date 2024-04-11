#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

template <class Data, class Operator>
class SegmentTree {
    using DataMerger = std::function<Data(Data, Data)>;
    using Applier = std::function<Data(Operator, Data)>;

private:
    int length;
    std::vector<Data> dat;
    Data dat_id;        // 
    DataMerger dmerge;  // 
    Applier app;        // 

    Data query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return dat_id;
        if (ql <= nl && nr <= qr) return dat[nidx];
        Data vl = query(ql, qr, nidx * 2, nl, (nl + nr) / 2);
        Data vr = query(ql, qr, nidx * 2 + 1, (nl + nr) / 2, nr);
        return dmerge(vl, vr);
    }

public:
    explicit SegmentTree(int N, Data dat_id, DataMerger dmerge, Applier app)
        : length(1), dat_id(dat_id), dmerge(dmerge), app(app) {
        while (length < N) length <<= 1;
        dat.assign(length * 2, dat_id);
    }

    // half-open interval [ql, qr)
    Data query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    void update(int idx, Operator e) {
        int nidx = idx + length;
        dat[nidx] = app(e, dat[nidx]);
        while (nidx > 0) {
            nidx >>= 1;
            dat[nidx] = dmerge(dat[nidx * 2], dat[nidx * 2 + 1]);
        }
    }
};

const int INF = std::numeric_limits<int>::max() / 3;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<queue<int>> apos(N);
        SegmentTree<int, int> seg(N, INF,
                                  [](int a, int b) { return min(a, b); },
                                  [](int e, int a) { return e; });
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            --A[i];
            apos[A[i]].push(i);
            seg.update(i, A[i]);
        }

        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
            --B[i];
        }

        bool judge = true;
        for (int i = 0; i < N; ++i) {
            if (apos[B[i]].empty()) {
                judge = false;
                break;
            }

            int r = apos[B[i]].front();
            apos[B[i]].pop();

            if (seg.query(0, r + 1) < B[i]) {
                judge = false;
                break;
            }
            seg.update(r, INF);
        }
        cout << (judge ? "YES" : "NO") << "\n";
    }
    return 0;
}