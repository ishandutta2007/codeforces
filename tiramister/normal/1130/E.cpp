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

void sim(int p, int q) {
    for (int l = 1; l < 2000; ++l) {
        int n = p + l;
        int a = q + n;
        if (n > 2000) break;
        if (a > 1000000 * l) continue;
        cerr << n << " " << a << endl;

        cout << n << endl;
        for (int i = 0; i < n - l; ++i) cout << -1 << " ";
        for (int i = l; i > 0; --i) {
            cout << a / i << " ";
            a -= a / i;
        }
        cout << endl;
        exit(0);
    }
}

int main() {
    int K;
    cin >> K;

    for (int p = 1; p * p <= K; ++p) {
        if (K % p != 0) continue;
        sim(p, K / p);
        sim(K / p, p);
    }

    cout << -1 << endl;
    return 0;
}