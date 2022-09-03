#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

vii v, w;
vi u[1000];
int res[1000];

int main () {
    scanf ("%d%d", &n, &m);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        sum += x * 2;
        if (y == 1) v.pb (mp (x, i)); else w.pb (mp (x, i));
    }
    sort (all (v));
    reverse (all (v));
    if (sz (v) >= m) {
        for (int i = 0; i + 1 < m; i++) {
            res[v[i].se] = i;
            sum -= v[i].fi;
        }
        int tmp = 2e9;
        for (int i = m - 1; i < sz (v); i++) {
            res[v[i].se] = m - 1;
            tmp = min (tmp, v[i].fi);
        }
        for (int i = 0; i < sz (w); i++) {
            res[w[i].se] = m - 1;
            tmp = min (tmp, w[i].fi);
        }
        sum -= tmp;

    } else {
        for (int i = 0; i < sz (v); i++) {
            res[v[i].se] = i;
            sum -= v[i].fi;
        }
        for (int i = 0; i < sz (w); i++) res[w[i].se] = min (i + sz (v), m - 1);
    }
    printf ("%.1f\n", sum / 2.0);
    for (int i = 0; i < n; i++) u[res[i]].pb (i + 1);
    for (int i = 0; i < m; i++) {
        printf ("%d", sz (u[i]));
        for (int j = 0; j < sz (u[i]); j++) printf (" %d", u[i][j]);
        printf ("\n");
    }
    return 0;
}