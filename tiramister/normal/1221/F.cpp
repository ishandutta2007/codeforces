#if __has_include("../library/Basic/Debug.hpp")

#include "../library/Basic/Debug.hpp"

#else

/* ----- Header Files ----- */
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
#include <array>
#include <string>
#include <tuple>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

// others
#include <random>
#include <limits>
#include <functional>
#include <ctime>
#include <cassert>
#include <cstdint>

/* ----- Type Alias ----- */
using Int = long long int;
using Real = long double;
using std::array;
using std::map;
using std::pair;
using std::string;
using std::tuple;
using std::vector;
template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T>
T genv(T v) { return v; }

template <class T, class... Ts>
auto genv(size_t l, Ts... ts) {
    return vector<decltype(genv<T>(ts...))>(l, genv<T>(ts...));
}

template <class Cost = Int>
struct Edge {
    Int src, dst;
    Cost cost;
    Edge(Int src = -1, Int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = Int>
using Edges = vector<Edge<Cost>>;
template <class Cost = Int>
using Graph = vector<vector<Edge<Cost>>>;

#endif

using std::map;

constexpr Int INF = std::numeric_limits<Int>::max() / 3;

struct LazySegmentTree {
    int length;
    std::vector<Int> dat;
    std::vector<Int> ope;

    void eval(int nidx, int len) {
        if (ope[nidx] == 0) return;
        // 
        if (nidx * 2 + 1 < length * 2) {
            ope[nidx * 2] += ope[nidx];
            ope[nidx * 2 + 1] += ope[nidx];
        }
        // 
        dat[nidx] += ope[nidx];
        ope[nidx] = 0;
    }

    Int update(int ql, int qr, Int e, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return dat[nidx];
        if (ql <= nl && nr <= qr) {
            ope[nidx] += e;
            return dat[nidx] + ope[nidx];
        }
        // 
        Int vl = update(ql, qr, e, nidx * 2, nl, (nl + nr) / 2);
        Int vr = update(ql, qr, e, nidx * 2 + 1, (nl + nr) / 2, nr);
        // 
        return dat[nidx] = std::max(vl, vr);
    }

    Int query(int ql, int qr, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return -INF;
        if (ql <= nl && nr <= qr) return dat[nidx];
        Int vl = query(ql, qr, nidx * 2, nl, (nl + nr) / 2);
        Int vr = query(ql, qr, nidx * 2 + 1, (nl + nr) / 2, nr);
        return std::max(vl, vr);
    }

public:
    explicit LazySegmentTree(int N) : length(1) {
        while (length < N) length *= 2;
        dat.assign(length * 2, 0);
        ope.assign(length * 2, 0);
    }

    // half-open interval [ql, qr)
    Int update(int ql, int qr, Int e) { return update(ql, qr, e, 1, 0, length); }

    // half-open interval [ql, qr)
    Int query(int ql, int qr) { return query(ql, qr, 1, 0, length); }
};

/* ----- Misc ----- */
void fastio() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

struct Fout {
    Int precision;
    Fout(Int precision) : precision(precision) {}
};
std::ostream& operator<<(std::ostream& os, const Fout& fio) {
    os << std::fixed << std::setprecision(fio.precision);
    return os;
}


/* ----- Constants ----- */
// constexpr Int MOD = 1000000007;
// const Real PI = acos(-1);
// constexpr Real EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));

template <class T>
map<T, Int> compress(vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    map<T, Int> rev;
    for (Int i = 0; i < v.size(); ++i) rev[v[i]] = i;
    return rev;
}

int main() {
    fastio();

    int n;
    std::cin >> n;

    vector<Int> ls(n), rs(n), cs(n);
    vector<Int> xs{Int(1.1e9)};
    for (int i = 0; i < n; ++i) {
        Int x, y;
        std::cin >> x >> y >> cs[i];
        ls[i] = std::min(x, y);
        rs[i] = std::max(x, y);
        xs.push_back(ls[i]);
        xs.push_back(rs[i]);
    }
    auto revx = compress(xs);
    int m = xs.size();

    Graph<Int> graph(m);
    for (int i = 0; i < n; ++i) {
        graph[revx[ls[i]]].emplace_back(revx[ls[i]], revx[rs[i]], cs[i]);
    }
    for (int l = 0; l + 1 < m; ++l) {
        graph[l].emplace_back(l, l + 1, xs[l] - xs[l + 1]);
    }

    LazySegmentTree segt(m);
    int maxl = m;
    Int maxv = -INF;
    for (int l = m - 1; l >= 0; --l) {
        for (auto e : graph[l]) {
            segt.update(e.dst, m, e.cost);
        }
        // std::cerr << l << ": ";
        // for (int i = 0; i < m; ++i) {
        //     std::cerr << segt.query(i, i + 1) << ',';
        // }
        // std::cerr << std::endl;

        Int cost = segt.query(l, m);
        if (cost > maxv) {
            maxl = l;
            maxv = cost;
        }
    }
    std::cout << maxv << std::endl;

    LazySegmentTree nsegt(m);
    for (int l = maxl; l < m; ++l) {
        for (auto e : graph[l]) {
            nsegt.update(e.dst, m, e.cost);
        }
    }

    int r;
    for (r = maxl; r < m; ++r) {
        if (nsegt.query(r, r + 1) == maxv) break;
    }
    assert(r < m);

    std::cout << xs[maxl] << " " << xs[maxl] << " "
              << xs[r] << " " << xs[r] << std::endl;
    return 0;
}