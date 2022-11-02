// IO library
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// contancer library
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v) os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "{";
    for (auto vv : v) os << vv << ",";
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template <class K, class T>
ostream& operator<<(ostream& os, map<K, T> v) {
    os << "{";
    for (auto vv : v) os << vv << ",";
    return os << "}";
}

template <class T>
ostream& operator<<(ostream& os, queue<T> q) {
    os << "[";
    while (!q.empty()) {
        os << q.front() << ",";
        q.pop();
    }
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, priority_queue<T> q) {
    os << "{";
    while (!q.empty()) {
        os << q.top() << ",";
        q.pop();
    }
    return os << "}";
}

const ll MOD = 1000000007;
// const ll MOD = 998244353;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const ld PI = acos(-1);
// const ld EPS = 1e-10;
// mt19937 mt(ll(time(0)));

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

template <typename T, typename U>
T ipow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= b;
        n >>= 1;
        b *= b;
    }
    return ret;
}

template <typename T, typename U>
T mpow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * b % MOD;
        n >>= 1;
        b = b * b % MOD;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    auto h = Vec<int>(N, M, 0);
    for (auto& v : h) {
        for (auto& e : v) cin >> e;
    }

    auto xless = Vec<int>(N, M, 0), xmore = Vec<int>(N, M, 0);
    for (int x = 0; x < N; ++x) {
        map<int, vector<int>> mp;
        for (int y = 0; y < M; ++y) {
            mp[h[x][y]].push_back(y);
        }
        int cnt = 0;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            for (int y : itr->second) {
                xless[x][y] = cnt;
            }
            ++cnt;
        }

        cnt = 0;
        for (auto itr = mp.rbegin(); itr != mp.rend(); ++itr) {
            for (int y : itr->second) {
                xmore[x][y] = cnt;
            }
            ++cnt;
        }
    }

    auto yless = Vec<int>(N, M, 0), ymore = Vec<int>(N, M, 0);
    for (int y = 0; y < M; ++y) {
        map<int, vector<int>> mp;
        for (int x = 0; x < N; ++x) {
            mp[h[x][y]].push_back(x);
        }
        int cnt = 0;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            for (int x : itr->second) {
                yless[x][y] = cnt;
            }
            ++cnt;
        }

        cnt = 0;
        for (auto itr = mp.rbegin(); itr != mp.rend(); ++itr) {
            for (int x : itr->second) {
                ymore[x][y] = cnt;
            }
            ++cnt;
        }
    }

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < M; ++y) {
            cout << max(xless[x][y], yless[x][y]) + max(xmore[x][y], ymore[x][y]) + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}