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

/* ----- Misc ----- */
void fastio() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

struct Fout {
    Int precision;
    explicit Fout(Int precision) : precision(precision) {}
};

std::ostream& operator<<(std::ostream& os, const Fout& fio) {
    os << std::fixed << std::setprecision(fio.precision);
    return os;
}

/* ----- Constants ----- */
// constexpr Int INF = std::numeric_limits<Int>::max() / 3;
// constexpr Int MOD = 1000000007;
// const Real PI = acos(-1);
// constexpr Real EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));

int main() {
    int n;
    std::cin >> n;
    vector<Int> a(n), two(n, 0);
    vector<int> cnt(70, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        Int b = a[i];
        while ((b & 1) == 0) {
            ++two[i];
            b >>= 1;
        }
        ++cnt[two[i]];
    }

    int maxi = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
    std::cout << n - cnt[maxi] << std::endl;

    for (int i = 0; i < n; ++i) {
        if (two[i] != maxi) {
            std::cout << a[i] << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}