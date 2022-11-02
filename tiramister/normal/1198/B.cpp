// IO
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm
#include <algorithm>
#include <cmath>
#include <numeric>

// container
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

// others
#include <random>
#include <limits>
#include <functional>
#include <ctime>
#include <cassert>

// type alias
using lint = long long;
using ldouble = long double;
template <class T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;


/* ----- class ----- */

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Edges = std::vector<Edge<Cost>>;

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

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

/* ----- debug ----- */

#if __has_include("../setting/source/debug.hpp")
#include "../setting/source/debug.hpp"
#endif


/* ----- short functions ----- */

template <class T>
inline T sq(T a) { return a * a; }

template <class T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

template <class T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template <class T, class U>
T ipow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= b;
        n >>= 1;
        b *= b;
    }
    return ret;
}

// 0-indexed
template <class T, class U>
inline T kthbit(T a, U k) { return (a >> k) & 1; }

template <class T, class U>
inline T mask(T a, U k) { return a & ((1 << k) - 1); }

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < v.size(); ++i) rev[v[i]] = i;
    return rev;
}

template <class T>
T Vec(T v) { return v; }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return std::vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}


/* ----- constants ----- */

const int INF = std::numeric_limits<int>::max() / 3;
// const lint INF = std::numeric_limits<lint>::max() / 3;
// const ldouble PI = acos(-1);
// const ldouble EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));


using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    vector<int> prev(N, -1);

    int Q;
    cin >> Q;
    SegmentTree<int, int> seg(Q, -INF,
                              [](int a, int b) { return max(a, b); },
                              [](int a, int e) { return max(a, e); });

    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            A[p] = x;
            prev[p] = q;
        } else {
            int x;
            cin >> x;
            seg.update(q, x);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << max(A[i], seg.query(prev[i], Q)) << " ";
    }

    cout << endl;
    return 0;
}