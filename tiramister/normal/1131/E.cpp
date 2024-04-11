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

int samecount(string S) {
    for (int i = 1; i < S.length(); ++i) {
        if (S[i] != S[i - 1]) return i;
    }
    return S.length();
}

int subcount(string S, char c) {
    int ret = 0, cnt = 1;
    for (char sc : S) {
        if (sc != c) cnt = 0;
        ret = max(ret, cnt);
        ++cnt;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> S(N);
    for (auto& s : S) cin >> s;
    reverse(S.begin(), S.end());

    char lc = S[0].front(), rc = S[0].back();
    int l = samecount(S[0]);
    reverse(S[0].begin(), S[0].end());
    int r = samecount(S[0]);
    bool same = (l == S[0].length());

    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) ans = max(ans, subcount(S[0], c));

    string rest;
    for (int i = 1; i < N; ++i) {
        cerr << make_pair(l, lc) << " " << make_pair(r, rc) << " " << same << endl;

        if (same) {
            ans = (l + 1) * (subcount(S[i], lc) + 1) - 1;

            if (S[i].front() == lc) {
                l = (l + 1) * (samecount(S[i]) + 1) - 1;
            }

            reverse(S[i].begin(), S[i].end());
            if (S[i].front() == rc) {
                r = (r + 1) * (samecount(S[i]) + 1) - 1;
            }

            same = (S[i].front() == rc && samecount(S[i]) == S[i].length());
        } else {
            for (int j = i; j < N; ++j) rest += S[j];
            break;
        }
    }

    if (!same) {
        if (lc == rc && find(rest.begin(), rest.end(), lc) != rest.end()) {
            ans = max(ans, l + r + 1);
        } else {
            if (find(rest.begin(), rest.end(), lc) != rest.end()) ans = max(ans, l + 1);
            if (find(rest.begin(), rest.end(), rc) != rest.end()) ans = max(ans, r + 1);
        }
    }

    cout << ans << endl;
    return 0;
}