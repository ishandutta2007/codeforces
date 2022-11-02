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
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    int N = 0;
    for(auto& s : S) {
        cin >> s;
        N += count(s.begin(), s.end(), '*');
    }

    for(int x = 0; x < H; ++x) {
        for(int y = 0; y < W; ++y) {
            if (S[x][y] == '.') continue;
            int lx, rx, ly, ry;
            for(lx = x - 1; lx >= 0 && S[lx][y] == '*'; --lx);
            for(rx = x + 1; rx < H  && S[rx][y] == '*'; ++rx);
            for(ly = y - 1; ly >= 0 && S[x][ly] == '*'; --ly);
            for(ry = y + 1; ry < W  && S[x][ry] == '*'; ++ry);

            int X = rx - lx - 1, Y = ry - ly - 1;
            if (lx < x - 1 &&  x + 1 < rx && ly < y - 1 && y + 1 < ry &&
                X + Y - 1 == N) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}