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
int k;
int xx[100000];
int yy[100000];
map<int, int> allx, ally;
int ox, oy;
vii v[100000], vv[100000];
vii h[100000], hh[100000];
int rx[100000], ry[100000];

int getx (int x) {
    if (allx.find (x) != allx.end ()) re allx[x];
    xx[ox] = x;
    allx[x] = ox++;
    re ox - 1;
}

int gety (int y) {
    if (ally.find (y) != ally.end ()) re ally[y];
    yy[oy] = y;
    ally[y] = oy++;
    re oy - 1;
}

int main () {
    scanf ("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap (x1, x2);
        if (y1 > y2) swap (y1, y2);
        if (x1 == x2)
            v[getx (x1)].pb (mp (y1, y2));
        else
            h[gety (y1)].pb (mp (x1, x2));
    }
    int ans = 0;
    if ((n - oy - 1) & 1) ans ^= m;
    if ((m - ox - 1) & 1) ans ^= n;
    for (int i = 0; i < ox; i++) {
        int cur = n, l = -1, r = -1;
        sort (all (v[i]));
        for (int j = 0; j < sz (v[i]); j++)
            if (r < v[i][j].fi) {
                if (l != -1) vv[i].pb (mp (l, r));
                cur -= r - l;
                l = v[i][j].fi;
                r = v[i][j].se;
            } else r = max (r, v[i][j].se);
        vv[i].pb (mp (l, r));
        cur -= r - l;
        ans ^= cur;
        rx[i] = cur;
    }
    for (int i = 0; i < oy; i++) {
        int cur = m, l = -1, r = -1;
        sort (all (h[i]));
        for (int j = 0; j < sz (h[i]); j++)
            if (r < h[i][j].fi) {
                if (l != -1) hh[i].pb (mp (l, r));
                cur -= r - l;
                l = h[i][j].fi;
                r = h[i][j].se;
            } else r = max (r, h[i][j].se);
        hh[i].pb (mp (l, r));
        cur -= r - l;
        ans ^= cur;
        ry[i] = cur;
    }
    if (ans == 0) printf ("SECOND\n"); else {
        printf ("FIRST\n");
        if (m - ox - 1 > 0 && (ans ^ n) <= n) {
            for (int i = 1; i < m; i++)
                if (allx.find (i) == allx.end ()) {
                    printf ("%d %d %d %d\n", i, 0, i, n - (ans ^ n));
                    re 0;                                 
                }
        }
        if (n - oy - 1 > 0 && (ans ^ m) <= m) {
            for (int i = 1; i < n; i++)
                if (ally.find (i) == ally.end ()) {
                    printf ("%d %d %d %d\n", 0, i, m - (ans ^ m), i);
                    re 0;
                }
        }
        for (int i = 0; i < ox; i++)
            if ((ans ^ rx[i]) <= rx[i]) {
                int cur = rx[i] - (ans ^ rx[i]), pos = 0;
                for (int j = 0; j < sz (vv[i]); j++)
                    if (cur > vv[i][j].fi - pos) {
                        cur -= vv[i][j].fi - pos;
                        pos = vv[i][j].se;
                    } else break;
                pos += cur;
                printf ("%d %d %d %d\n", xx[i], 0, xx[i], pos);
                re 0;
            }
        for (int i = 0; i < oy; i++)
            if ((ans ^ ry[i]) <= ry[i]) {
                int cur = ry[i] - (ans ^ ry[i]), pos = 0;
                for (int j = 0; j < sz (hh[i]); j++)
                    if (cur > hh[i][j].fi - pos) {
                        cur -= hh[i][j].fi - pos;
                        pos = hh[i][j].se;
                    } else break;
                pos += cur;
                printf ("%d %d %d %d\n", 0, yy[i], pos, yy[i]);
                re 0;
            }
    }
    return 0;
}