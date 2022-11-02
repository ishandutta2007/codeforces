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

struct Word {
    string s;
    int l;
    char c;
    Word(string s, int l, char c) : s(s), l(l), c(c){};
};

const string vowel = "aiueo";

int main() {
    int N;
    cin >> N;

    map<int, vector<Word>> W;
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int l = 0;
        for(char c : vowel) {
            l += (count(s.begin(), s.end(), c));
        }
        if (l == 0) continue;

        char c;
        for(int i = s.length() - 1; i >= 0; --i) {
            if (count(vowel.begin(), vowel.end(), s[i])) {
                c = s[i];
                break;
            }
        }

        W[l].emplace_back(s, l, c);
    }

    vector<pair<string, string>> goods, bads;
    for(auto& v : W) {
        vector<vector<Word>> NW(5);
        for(auto w : v.second) {
            for(int i = 0; i < 5; ++i) {
                if (w.c == vowel[i]) NW[i].push_back(w);
            }
        }

        vector<string> rem;
        for(int k = 0; k < 5; ++k) {
            for(int i = 0; i + 1 < NW[k].size(); i += 2) {
                goods.emplace_back(NW[k][i].s, NW[k][i + 1].s);
            }
            if (NW[k].size() % 2 > 0) {
                rem.push_back(NW[k].back().s);
            }
        }

        for(int i = 0; i + 1 < rem.size(); i += 2) {
            bads.emplace_back(rem[i], rem[i + 1]);
        }
    }

    cout << min(goods.size(), (goods.size() + bads.size()) / 2) << endl;
    while (!goods.empty()) {
        pair<string, string> p1 = goods.back();
        goods.pop_back();

        pair<string, string> p2;
        if (!bads.empty()) {
            p2 = bads.back();
            bads.pop_back();
        } else if (!goods.empty()) {
            p2 = goods.back();
            goods.pop_back();
        } else {
            continue;
        }

        cout << p2.first  << ' ' << p1.first  << '\n';
        cout << p2.second << ' ' << p1.second << '\n';
    }

    return 0;
}