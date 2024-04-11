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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int N;
        cin >> N;
        vector<pair<int, int>> A(N, make_pair(0, 0));
        for (int i = 0; i < N; ++i) {
            int a;
            cin >> a;
            --a;
            ++A[a].first;

            int f;
            cin >> f;
            if (f) ++A[a].second;
        }

        sort(A.begin(), A.end(), [](auto p, auto q) {
            return p.first > q.first;
        });

        set<int> choose;
        int pre = N + 1;
        for (auto p : A) {
            int sel = min(pre - 1, p.first);
            if (sel > 0) {
                choose.insert(sel);
                pre = sel;
            }
        }
        int sum = accumulate(choose.begin(), choose.end(), 0);

        sort(A.begin(), A.end(), [](auto p, auto q) {
            return p.second > q.second;
        });
        int score = 0;
        for (auto p : A) {
            auto itr = choose.upper_bound(p.first);
            if (itr == choose.begin()) continue;
            --itr;
            // choose *itr candies
            score += min(p.second, *itr);
            choose.erase(itr);
        }

        cout << sum << " " << score << "\n";
    }
    return 0;
}