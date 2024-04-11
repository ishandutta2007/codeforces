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
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;
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
#define SORT(v) sort((v).begin(), (v).end())
#define GSORT(v) sort((v).begin(), (v).end(), greater<decltype((v).front())>())

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (ll i = (b)-1; i >= (a); --i)

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
const ll INF = 1LL << 40;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// mt19937 mt(LL(time(0)));

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
        return mypow(sq(b) /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

// #define DEBUG

map<ll, ll> compress(const vector<ll>& v) {
    set<ll> s;
    for (auto c : v) {
        s.insert(c);
    }

    map<ll, ll> ret;
    ll idx = 0;
    for (ll c : s) {
        ret[c] = idx;
        ++idx;
    }

    return ret;
}

void solve() {
    ll N, h;
    cin >> N >> h;

    V<ll> x(N * 2 + 2, 0);
    FOR(i, 0, N) {
        cin >> x[i * 2 + 1] >> x[i * 2 + 2];
    }
    x[N * 2 + 1] = INF;

    map<ll, ll> com = compress(x);
    V<ll> sum(N * 2 + 2, 0);
    // sum[i] = [0, xi]

    FOR(i, 0, N) {
        sum[i * 2 + 1] = sum[i * 2];
        sum[i * 2 + 2] = sum[i * 2 + 1] + x[i * 2 + 2] - x[i * 2 + 1];
    }
    sum[N * 2 + 1] = sum[N * 2];

    ll ok = h, ng = INF;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;

        bool judge = false;
        FOR(i, 0, N) {
            ll to = x[i * 2 + 1] + mid;
            ll d, idx;
            tie(d, idx) = *(com.lower_bound(to));

            if (idx % 2 == 0) {
                to = d;
                if (to - x[i * 2 + 1] < sum[idx] - sum[i * 2 + 1] + h) {
                    judge = true;
                    break;
                }
            } else {
                if (to - x[i * 2 + 1] <= sum[idx] - sum[i * 2 + 1] + h) {
                    judge = true;
                    break;
                }
            }
        }

        if (judge) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return;
}


/* ---------- Do not edit below part ---------- */


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(10);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    int num;
    cin >> num;
    FOR(_, 0, num) {
        cout << "++++++++++++++++++++" << endl;
        solve();
    }
#else
    solve();
#endif

    return 0;
}