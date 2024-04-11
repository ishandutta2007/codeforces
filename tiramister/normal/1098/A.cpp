/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

using ll = long long;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

#define mp make_pair
#define mt make_tuple

/* ----------- debug ---------- */

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p);

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1000000007;
// const ll MOD = 998244353;
// const int INF = 1 << 25;
const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

vector<int> child[100010];
int p[100010];
ll s[100010], a[100010];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; ++i) {
        cin >> p[i];
        --p[i];
        child[p[i]].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    ll ans = 0;

    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        if (v == 0) {
            a[v] = s[v];
        } else {
            if (s[v] < 0) {
                if (child[v].empty()) {
                    a[v] = 0;
                } else {
                    ll minval = INF;
                    for (int sv : child[v]) {
                        minval = min(minval, s[sv]);
                    }
                    a[v] = minval - s[p[v]];
                    if (a[v] < 0) {
                        cout << -1 << endl;
                        return 0;
                    }
                    s[v] = minval;
                }
            } else {
                a[v] = s[v] - s[p[v]];
            }
        }

        ans += a[v];

        for (int sv : child[v]) {
            que.push(sv);
        }
    }

    cout << ans << endl;
    return 0;
}