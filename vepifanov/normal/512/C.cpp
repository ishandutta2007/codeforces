#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <functional>
#include <numeric>

using namespace std;

#ifdef __WIN32__
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#ifdef __WIN32__
    #define ULLD "%I64u"
#else
    #define ULLD "%llu"
#endif

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }

#define filename ""

const int N = 20000;

int n;
int m;
int f[N + 1];

vii v[202];
vii e, o;
int was[202];
int prev[202];
int preve[202];
int cf[50000];
int t;
int q[202];

int addedge (int a, int b, int c) {
    v[a].pb (mp (b, t));
    cf[t] = c;
    t++;
    v[b].pb (mp (a, t));
    cf[t] = 0;
    t++;    
    re 0;
}

int go (int S, int T) {
    for (int i = 0; i < n + 2; i++) was[i] = 0;
    int l = 0, r = 1;
    q[0] = S;
    was[S] = 1;
    while (l < r) {
        int x = q[l++];
        if (x == T) re 1;
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int z = v[x][i].se;
            if (cf[z] > 0 && !was[y]) {
                was[y] = 1;
                q[r++] = y;
                prev[y] = x;
                preve[y] = z;               
            }
        }
    }
    re 0;
}

vi u[200];
vi w;
vvi res;

int go (int x) {
    if (was[x] == 1) re 0;
    was[x] = 1;
    w.pb (x);
    for (int i = 0; i < sz (u[x]); i++)
        go (u[x][i]);
    re 0;
}

int main () {
    for (int i = 2; i <= N; i++)
        if (!f[i])
            for (int j = 2 * i; j <= N; j += i) f[j] = 1;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x & 1)
            o.pb (mp (x, i));
        else
            e.pb (mp (x, i));
    }
    for (int i = 0; i < sz (o); i++) {
        addedge (n, i, 2);
        for (int j = 0; j < sz (e); j++)
            if (!f[o[i].fi + e[j].fi])
                addedge (i, j + sz (o), 1);
    }
    for (int i = 0; i < sz (e); i++)
        addedge (sz (o) + i, n + 1, 2);
    if (sz (o) != sz (e)) {
        printf ("Impossible\n");
        re 0;
    }
    int cur = 0;
    while (go (n, n + 1)) {
        cur++;
        int j = n + 1;
        while (j != n) {
            int k = prev[j];
            int z = preve[j];
            cf[z]--;
            cf[z ^ 1]++;
            j = k;
        }
    }
    if (cur != sz (o) * 2) {
        printf ("Impossible\n");
        re 0;
    }
    for (int i = 0; i < sz (o); i++)
        for (int j = 0; j < sz (v[i]); j++)
            if (v[i][j].fi < n && cf[v[i][j].se] == 0) {
                u[o[i].se].pb (e[v[i][j].fi - sz (o)].se);
                u[e[v[i][j].fi - sz (o)].se].pb (o[i].se);
            }
    memset (was, 0, sizeof (was));
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            w.clear ();
            go (i);
            res.pb (w);
        }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) {
        printf ("%d", sz (res[i]));
        for (int j = 0; j < sz (res[i]); j++)
            printf (" %d", res[i][j] + 1);
        printf ("\n");
    }
    return 0;
}