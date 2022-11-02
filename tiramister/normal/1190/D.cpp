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


// 
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

    SegmentTree(int N) : length(1) {
        while (length < N) length <<= 1;
        dat.assign(length * 2, 0);
    }

    // half-open interval [ql, qr)
    lint query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    void update(int idx, lint e) {
        int nidx = idx + length;
        dat[nidx] += e;
        while (nidx > 0) {
            nidx >>= 1;
            dat[nidx] = dat[nidx * 2] + dat[nidx * 2 + 1];
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

const int INF = std::numeric_limits<int>::max() / 2;
// const lint INF = std::numeric_limits<lint>::max() / 3;
// const ldouble PI = acos(-1);
// const ldouble EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));


using namespace std;

int main() {
    cerr << INF << endl;
    int N;
    cin >> N;
    map<int, vector<int>> mp;
    vector<int> xs({0, INF});
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        mp[-y].push_back(x);
        xs.push_back(x);
    }

    auto revx = compress(xs);
    SegmentTree seg(xs.size());

    lint ans = 0;
    set<int> X;
    for (auto& p : mp) {
        p.second.push_back(0);
        p.second.push_back(INF);
        sort(p.second.begin(), p.second.end());
        for (auto& x : p.second) {
            if (!X.count(x)) {
                seg.update(revx[x], 1);
                X.insert(x);
            }
            x = revx[x];
        }
        // cerr << p.second << endl;

        lint D = seg.query(1, xs.size() - 1);
        // cerr << "D : " << D << endl;
        ans += D * (D + 1) / 2;

        for (int i = 0; i + 1 < p.second.size(); ++i) {
            lint L = p.second[i];
            lint R = p.second[i + 1];
            // cerr << "L, R : " << make_pair(L, R) << endl;

            lint E = seg.query(L + 1, R);
            // cerr << "E : " << E << endl;
            ans -= E * (E + 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}