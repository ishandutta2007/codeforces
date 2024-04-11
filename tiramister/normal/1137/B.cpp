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
mt19937 mt(ll(time(0)));

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

#include <string>
#include <vector>

using namespace std;
using ll = long long;

class RollingHash {
public:
    RollingHash(string S, ll _base = mt() % 30 + 30, ll _mod = 1e9 + 7) : base(_base), mod(_mod), len(S.length()) {
        hash.resize(len + 1);
        bpow.resize(len + 1);

        hash[0] = 0;
        bpow[0] = 1;
        for (int i = 0; i < len; ++i) {
            hash[i + 1] = (hash[i] * base + S[i]) % mod;
            bpow[i + 1] = bpow[i] * base % mod;
        }
    }

    ll seghash(int b, int e) {
        return (hash[e] - hash[b] * bpow[e - b] % mod + mod) % mod;
    }

    vector<ll> hash, bpow;
    ll base, mod;
    int len;
};

int main() {
    string S, T;
    cin >> S >> T;

    RollingHash rh(T);
    int l = 0;
    for (l = 1; l < T.size(); ++l) {
        bool judge = true;
        for (int i = 0; i + l < T.size(); i += l) {
            int r = (i + l * 2 <= T.size() ? i + l * 2 : T.size());
            if (rh.seghash(i, r - l) != rh.seghash(i + l, r)) {
                judge = false;
                break;
            }
        }
        if (judge) break;
    }

    T = T.substr(0, l);

    int cnt[2];
    cnt[0] = count(S.begin(), S.end(), '0');
    cnt[1] = S.length() - cnt[0];

    for (int i = 0; i < S.size(); ++i) {
        char to = T[i % l];
        if (cnt[to - '0'] == 0) {
            to = 1 - (to - '0') + '0';
        }
        S[i] = to;
        --cnt[to - '0'];
    }

    cout << S << endl;
    return 0;
}