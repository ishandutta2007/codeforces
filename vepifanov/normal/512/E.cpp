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

int n;
int m;
int g[1000][1000];
vi v[2][1000];

vii norm (int t) {
    for (int i = 0; i < n; i++) {
        v[t][i].pb ((i + 1) % n);
        v[t][i].pb ((i + n - 1) % n);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < sz (v[t][i]); j++)
            g[i][v[t][i][j]] = 1;
    vii res;
    sort (all (v[t][0]));
    while (sz (v[t][0]) != n - 1)
        for (int j = 0; j + 1 < sz (v[t][0]); j++)
            if (v[t][0][j] + 1 != v[t][0][j + 1]) {
                int a = v[t][0][j];
                int b = v[t][0][j + 1];
                assert (g[a][b]);
                for (int k = 1; k < n; k++)
                    if (g[k][a] && g[k][b]) {
                        g[a][b] = g[b][a] = 0;
                        g[0][k] = g[k][0] = 1;
                        if (t == 0) res.pb (mp (a, b)); else res.pb (mp (0, k));
                        v[t][0].insert (v[t][0].begin () + j + 1, k);
                        break;
                    }
                break;
            }
    re res;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n - 3; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[0][a].pb (b);
        v[0][b].pb (a);
    }
    for (int i = 0; i < n - 3; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[1][a].pb (b);
        v[1][b].pb (a);
    }
    vii a = norm (0);
    vii b = norm (1);
    reverse (all (b));
    printf ("%d\n", sz (a) + sz (b));
    for (int i = 0; i < sz (a); i++)
        printf ("%d %d\n", a[i].fi + 1, a[i].se + 1);
    for (int i = 0; i < sz (b); i++)
        printf ("%d %d\n", b[i].fi + 1, b[i].se + 1);
    return 0;
}