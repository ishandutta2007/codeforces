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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M, K, N, S;
    cin >> M >> K >> N >> S;
    auto a = Vec<int>(M, 0), b = Vec<int>(S, 0);
    for (auto& v : a) cin >> v;
    for (auto& v : b) cin >> v;

    auto s = b;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int L = s.size();
    map<int, int> rev;
    for (int i = 0; i < L; ++i) rev[s[i]] = i;
    auto need = Vec<int>(L, 0);
    for (auto v : b) ++need[rev[v]];

    auto cnt = Vec<int>(L, 0);
    int D = M - K * N;
    int r = 0;
    for (int l = 0; l < M; l += K) {
        while (r < min(D + K + l, M)) {
            if (rev.count(a[r])) ++cnt[rev[a[r]]];
            ++r;
        }
        bool judge = true;
        for (int k = 0; k < L; ++k) {
            if (cnt[k] < need[k]) judge = false;
        }

        if (judge) {
            vector<int> ans;
            for (int i = l; i < r; ++i) {
                if (D == 0) break;
                if (!rev.count(a[i]) || cnt[rev[a[i]]] > need[rev[a[i]]]) {
                    ans.push_back(i + 1);
                    if (rev.count(a[i])) --cnt[rev[a[i]]];
                    --D;
                }
            }

            cout << ans.size() << endl;
            for (int v : ans) cout << v << " ";
            cout << endl;
            return 0;
        }

        for (int i = 0; i < K; ++i) {
            if (l + i >= M) break;
            if (rev.count(a[l + i])) --cnt[rev[a[l + i]]];
        }
    }

    cout << -1 << endl;
    return 0;
}