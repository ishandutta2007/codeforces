/* main code starts from line 155. */

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

#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)

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

template <typename T>
T mypow(T b, T n) {
    if (n == 0) return 1;
    if (n == 1) return n;
    if (n % 2 == 0) {
        return mypow(sq(b), n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

/* --------------------
template <typename T>
T mypow(T b, T n) {
    if (n == 0) return 1;
    if (n == 1) return n % MOD;
    if (n % 2 == 0) {
        return mypow(sq(b) % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}
-------------------- */

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

    ll n, m, q;
    cin >> n >> m >> q;
    V<V<ll>> r(n), c(m);
    V<bool> rok(n, false), cok(m, false);
    V<bool> rv(n, false), cv(m, false);

    map<P<ll, ll>, ll> used;

    ll x = 0, y = 0;
    FOR(i, 1, q) {
        cin >> x >> y;
        x--;
        y--;
        r[x].pb(y);
        c[y].pb(x);
    }

    ll ans = 0;

    queue<ll> rq, cq;

    if (q == 0) {
        ans++;
    }

    ll xi = 0, yi = 0;
    while (xi < n || yi < m) {
        rok[x] = true;
        cok[y] = true;
        rq.push(x);
        cq.push(y);

        while (!rq.empty() || !cq.empty()) {
            while (!rq.empty()) {
                ll rt = rq.front();
                rq.pop();
                if (rv[rt]) continue;
                rv[rt] = true;

                for (ll sc : r[rt]) {
                    if (!cok[sc]) {
                        cok[sc] = true;
                        cq.push(sc);
                    }
                }
            }

            while (!cq.empty()) {
                ll ct = cq.front();
                cq.pop();
                if (cv[ct]) continue;
                cv[ct] = true;

                for (ll sr : c[ct]) {
                    if (!rok[sr]) {
                        rok[sr] = true;
                        rq.push(sr);
                    }
                }
            }
        }

        ans++;

        while (xi < n) {
            if (!rok[xi]) {
                break;
            }
            xi++;
        }

        if (xi < n) {
            x = xi;
            continue;
        }

        while (yi < m) {
            if (!cok[yi]) {
                break;
            }
            yi++;
        }

        if (yi < m) {
            y = yi;
            continue;
        }
    }

    cout << ans - 1 << endl;
    return 0;
}