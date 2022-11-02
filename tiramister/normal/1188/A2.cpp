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
const lint INF = std::numeric_limits<lint>::max() / 3;
// const ldouble PI = acos(-1);
// const ldouble EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));


using namespace std;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

int chnum(vector<lint>& v) {
    int ret = 0;
    for (auto c : v) {
        if (c > -INF / 2) ++ret;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<lint>> cost(N, vector<lint>(N, -INF));
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cin >> cost[u][v];
        cost[v][u] = cost[u][v];
    }

    vector<tuple<int, int, lint>> ans;
    if (N == 2) {
        ans.emplace_back(1, 2, cost[0][1]);
    } else {
        int root = -1;
        for (int v = 0; v < N; ++v) {
            if (chnum(cost[v]) == 2) {
                fail();
            } else if (chnum(cost[v]) > 1) {
                root = v;
                break;
            }
        }

        vector<vector<int>> chs(N);
        vector<int> leaf(N), par(N);
        function<int(int, int)> dfs = [&](int v, int r) {
            par[v] = r;
            for (int sv = 0; sv < N; ++sv) {
                if (sv == v || sv == r || cost[v][sv] == -INF) continue;
                leaf[v] = dfs(sv, v);
                chs[v].push_back(sv);
            }
            if (chs[v].empty()) leaf[v] = v;
            return leaf[v];
        };
        dfs(root, -1);

        auto update = [&](int lc, int rc, int lca, lint c) {
            ans.emplace_back(lc + 1, rc + 1, c);
            while (lc != lca) {
                cost[lc][par[lc]] -= c;
                cost[par[lc]][lc] -= c;
                lc = par[lc];
            }
            while (rc != lca) {
                cost[rc][par[rc]] -= c;
                cost[par[rc]][rc] -= c;
                rc = par[rc];
            }
        };

        queue<pair<int, int>> que;
        // (vertex, a leaf which does not belongs to the subtree)
        que.emplace(root, -1);

        while (!que.empty()) {
            int v, exch;
            tie(v, exch) = que.front();
            que.pop();
            assert(chs[v].size() != 1);

            if (chs[v].empty()) continue;
            if (chs[v].size() == 2) {
                assert(exch >= 0);
                int lv = leaf[chs[v][0]];
                int lc = cost[v][chs[v][0]];
                int rv = leaf[chs[v][1]];
                int rc = cost[v][chs[v][1]];

                lint diff = rc - lc;
                update(lv, exch, par[v], -diff / 2);
                update(rv, exch, par[v], diff / 2);

                lint rem = cost[v][chs[v][0]];
                update(lv, rv, v, rem);
            } else if (chs[v].size() >= 3) {
                while (chs[v].size() > 3) {
                    int lv = leaf[chs[v].front()];
                    int rv = leaf[chs[v].back()];
                    lint rc = cost[v][chs[v].back()];
                    update(lv, rv, v, rc);
                    que.emplace(chs[v].back(), leaf[chs[v][0]]);
                    chs[v].pop_back();
                }

                vector<int> ch(3);
                vector<lint> c(3);
                for (int i = 0; i < 3; ++i) {
                    ch[i] = leaf[chs[v][i]];
                    c[i] = cost[v][chs[v][i]];
                }
                lint csum = accumulate(c.begin(), c.end(), 0LL);

                for (int i = 0; i < 3; ++i) {
                    lint d = csum / 2 - c[i];
                    update(ch[(i + 1) % 3], ch[(i + 2) % 3], v, d);
                }
            }

            que.emplace(chs[v][0], leaf[chs[v][1]]);
            for (int i = 1; i < chs[v].size(); ++i) {
                que.emplace(chs[v][i], leaf[chs[v][0]]);
            }
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;

    for (auto t : ans) {
        int u, v, x;
        tie(u, v, x) = t;
        cout << u << " " << v << " " << x << "\n";
    }
    return 0;
}