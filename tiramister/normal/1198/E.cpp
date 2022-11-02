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

template <class Cap, bool isDirect>
class MaxFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        int rev;
        Edge(int src, int dst, Cap cap, int rev)
            : src(src), dst(dst), cap(cap), rev(rev){};
    };

    class Graph {
    public:
        int size;
        std::vector<std::vector<Edge>> path;

        explicit Graph(int N = 0) : size(N), path(size) {}
        void span(int u, int v, Cap cap, int rev) {
            path[u].push_back(Edge(u, v, cap, rev));
        }
        std::vector<Edge>& operator[](int v) { return path[v]; }
    };

private:
    Graph graph;
    std::vector<int> dist, iter;

    void bfs(int s) {
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (const auto& e : graph[v]) {
                if (e.cap > 0 && dist[e.dst] < 0) {
                    dist[e.dst] = dist[v] + 1;
                    que.push(e.dst);
                }
            }
        }
    }

    int dfs(int v, int g, Cap f) {
        if (v == g) return f;

        // iter
        for (int& itr = iter[v]; itr < graph[v].size(); ++itr) {
            auto e = graph[v][itr];
            if (e.cap > 0 && dist[v] < dist[e.dst]) {
                Cap df = dfs(e.dst, g, std::min(f, e.cap));

                // 
                if (df > 0) {
                    graph[v][itr].cap -= df;
                    graph[e.dst][e.rev].cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

public:
    explicit MaxFlow(int size)
        : graph(size), dist(size, -1), iter(size) {}

    void span(int u, int v, Cap cap) {
        graph.span(u, v, cap, graph[v].size());
        graph.span(v, u, (isDirect ? 0 : cap), graph[u].size() - 1);
    }

    Cap exec(int s, int g) {
        const Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            bfs(s);
            if (dist[g] < 0) return ret;

            std::fill(iter.begin(), iter.end(), 0);
            Cap flow;
            while (true) {
                flow = dfs(s, g, INF);
                if (flow == 0) break;
                ret += flow;
            }
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

// const int INF = std::numeric_limits<int>::max() / 3;
const lint INF = std::numeric_limits<lint>::max() / 2000;
// const ldouble PI = acos(-1);
// const ldouble EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));


using namespace std;

constexpr int S = 400, G = 401;

int encode(int v, int d) { return v + d * 200; }

int main() {
    int N, M;
    cin >> N >> M;
    vector<lint> lx(M), ly(M), rx(M), ry(M), xs(M * 2), ys(M * 2);
    for (int i = 0; i < M; ++i) {
        cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
        ++rx[i], ++ry[i];
        xs[i * 2] = lx[i], xs[i * 2 + 1] = rx[i];
        ys[i * 2] = ly[i], ys[i * 2 + 1] = ry[i];
    }

    auto revx = compress(xs);
    auto revy = compress(ys);

    MaxFlow<lint, true> mf(402);
    set<tuple<int, int, lint>> ps;
    for (int i = 0; i < M; ++i) {
        for (int x = revx[lx[i]]; x < revx[rx[i]]; ++x) {
            for (int y = revy[ly[i]]; y < revy[ry[i]]; ++y) {
                ps.emplace(S, encode(x, 0), xs[x + 1] - xs[x]);
                ps.emplace(encode(x, 0), encode(y, 1), INF);
                ps.emplace(encode(y, 1), G, ys[y + 1] - ys[y]);
            }
        }
    }
    for (auto p : ps) {
        int x, y;
        lint c;
        tie(x, y, c) = p;
        mf.span(x, y, c);
    }

    cout << mf.exec(S, G) << endl;
    return 0;
}