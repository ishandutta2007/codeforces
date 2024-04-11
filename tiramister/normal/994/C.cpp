/* main code starts from line 133. */

/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>

// container library
#include <array>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
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
#define pb push_back
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

#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<decltype((v).front())>())

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)

#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n - 1, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// Usual REP runs from 0 to n-1 (R: n-1 to 0)
// Natural REP runs from 1 to n (R: n to 1)

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

#define fcout cout << fixed << setprecision(10)

/* ----------- debug ---------- */

template <typename T, typename U>
void testP2(T a, U b) {
    cout << "(" << a << ", " << b << ")" << endl;
    return;
}

template <typename T>
void testV(T v) {
    cout << "[";
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << "\b\b]" << endl;
    return;
}

template <typename T>
void testV2(T v) {
    for (auto sv : v) {
        testV(sv);
    }
    cout << endl;
    return;
}

#define GET_VAR_NAME(variable) #variable
#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;
#define testP(p)                      \
    cout << GET_VAR_NAME(p) << " = "; \
    testP2(p.fst, p.snd);

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */


/* ---------- Global Variance ----------- */


/* ------------- Functions -------------- */


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    V<ll> x1(4), y1(4), x2(4), y2(4);

    ll xmin = 1000, xmax = -1000, ymin = 1000, ymax = -1000;

    REP(i, 4) {
        cin >> x1[i] >> y1[i];
        xmin = min(xmin, x1[i]);
        xmax = max(xmax, x1[i]);
        ymin = min(ymin, y1[i]);
        ymax = max(ymax, y1[i]);
    }

    ll xmin2 = 1000, xmax2 = -1000, ymin2 = 1000, ymax2 = -1000;
    REP(j, 4) {
        cin >> x2[j] >> y2[j];
        xmin2 = min(xmin2, x2[j]);
        xmax2 = max(xmax2, x2[j]);
        ymin2 = min(ymin2, y2[j]);
        ymax2 = max(ymax2, y2[j]);

        if (xmin <= x2[j] && x2[j] <= xmax && ymin <= y2[j] && y2[j] <= ymax) {
            cout << "YES" << endl;
            return 0;
        }
    }

    if (xmin * 2 <= x2[0] + x2[2] && x2[0] + x2[2] <= xmax * 2 && ymin * 2 <= y2[0] + y2[2] && y2[0] + y2[2] <= ymax * 2) {
        cout << "YES" << endl;
        return 0;
    }

    xmin = 1000, xmax = -1000, ymin = 1000, ymax = -1000;
    REP(j, 4) {
        ll x = x2[j], y = y2[j];
        x2[j] = x - y;
        y2[j] = x + y;
        xmin = min(xmin, x2[j]);
        xmax = max(xmax, x2[j]);
        ymin = min(ymin, y2[j]);
        ymax = max(ymax, y2[j]);
    }

    REP(i, 4) {
        ll x = x1[i], y = y1[i];
        x1[i] = x - y;
        y1[i] = x + y;

        if (xmin <= x1[i] && x1[i] <= xmax && ymin <= y1[i] && y1[i] <= ymax) {
            cout << "YES" << endl;
            return 0;
        }
    }

    if (xmin * 2 <= x1[0] + x1[2] && x1[0] + x1[2] <= xmax * 2 && ymin * 2 <= y1[0] + y1[2] && y1[0] + y1[2] <= ymax * 2) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}