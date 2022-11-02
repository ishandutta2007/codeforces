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
// const lint INF = std::numeric_limits<lint>::max() / 3;
// const ldouble PI = acos(-1);
// const ldouble EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));


using namespace std;

int getbit() {
    int f;
    cin >> f;
    int ret = 0;
    for (int i = 0; i < f; ++i) {
        int b;
        cin >> b;
        ret += (1 << (b - 1));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> fav(N);
    for (auto& f : fav) f = getbit();

    vector<int> sat(1 << 9, 0);
    for (int b = 0; b < (1 << 9); ++b) {
        for (auto f : fav) {
            if ((f & b) == f) ++sat[b];
        }
    }

    vector<vector<pair<int, int>>> pizza(1 << 9);
    for (int i = 0; i < M; ++i) {
        int p, pat;
        cin >> p;
        pat = getbit();
        pizza[pat].emplace_back(p, i);
    }

    for (int b = 0; b < (1 << 9); ++b) {
        sort(pizza[b].begin(), pizza[b].end());
    }

    pair<int, int> ans(-1, -1), maxscore(-1, -1);
    // 1 kind
    for (int b = 0; b < (1 << 9); ++b) {
        if (pizza[b].size() < 2) continue;
        auto score = make_pair(sat[b], -(pizza[b][0].first + pizza[b][1].first));
        if (score > maxscore) {
            ans = make_pair(pizza[b][0].second, pizza[b][1].second);
            maxscore = score;
        }
    }

    // 2 kinds
    for (int b = 0; b < (1 << 9); ++b) {
        for (int c = b + 1; c < (1 << 9); ++c) {
            if (pizza[b].empty() || pizza[c].empty()) continue;

            auto score = make_pair(sat[b | c], -(pizza[b][0].first + pizza[c][0].first));
            if (score > maxscore) {
                ans = make_pair(pizza[b][0].second, pizza[c][0].second);
                maxscore = score;
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << endl;
    return 0;
}