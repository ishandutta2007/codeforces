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

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

/* ----------- debug ---------- */

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
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

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

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

vector<int> path[100010];
int d[100010];
int N, K;

void bfs(int r) {
    fill(d, d + N, -1);
    d[r] = 0;

    queue<int> que;
    que.push(r);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : path[v]) {
            if (d[sv] < 0) {
                d[sv] = d[v] + 1;
                que.push(sv);
            }
        }
    }
    return;
}

// -1
int dfs(int v) {
    d[v] = 0;
    vector<int> ch;
    for (int sv : path[v]) {
        if (d[sv] >= 0) continue;
        ch.push_back(dfs(sv));
    }

    if (ch.size() == 0) {
        // 0
        d[v] = 0;
    } else if (ch.size() < 3) {
        // hedgehog
        d[v] = -1;
    } else {
        ch.erase(unique(ch.begin(), ch.end()), ch.end());
        if (ch.size() > 1) {
            // 
            d[v] = -1;
        } else {
            d[v] = ch[0] + 1;
        }
    }

    return d[v];
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    // (r)
    bfs(0);
    int r = 0;
    for (int v = 0; v < N; ++v) {
        if (d[v] > d[r]) r = v;
    }

    // (sr)
    bfs(r);
    int sr = 0;
    for (int v = 0; v < N; ++v) {
        if (d[sr] < d[v]) sr = v;
    }

    // d[v]*2
    set<int> center;
    for (int v = 0; v < N; ++v) {
        if (d[v] * 2 == d[sr]) center.insert(v);
    }

    // srbfs
    bfs(sr);
    for (int v = 0; v < N; ++v) {
        if (d[v] * 2 == d[r] && center.find(v) != center.end()) {
            r = v;
            break;
        }
    }

    fill(d, d + N, -1);

    // DFS
    cout << (dfs(r) == K ? "Yes" : "No") << endl;
    return 0;
}