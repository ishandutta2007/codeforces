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
int a, b, ax, ay, bx, by;
int x1[1002], y1[1002], x2[1002], y2[1002], x3[1002], y3[1002], x4[1002], y4[1002];
int g[1002][1002];
int was[1002];
int d[1002];
int q[1002];

int dist (int x1, int y1, int x2, int y2) {
    re sqr (x2 - x1) + sqr (y2 - y1);
}

int dist (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if (x1 > x2) swap (x1, x2);
    if (y1 > y2) swap (y1, y2);
    if (x3 > x4) swap (x3, x4);
    if (y3 > y4) swap (y3, y4);
    int d = min (dist (x1, y1, x3, y3), dist (x1, y1, x4, y4));
    d = min (d, min (dist (x2, y2, x3, y3), dist (x2, y2, x4, y4)));
    if (x1 == x2) {
        if (y3 >= y1 && y3 <= y2 || y4 >= y1 && y4 <= y2)
            d = min (d, min (sqr (x1 - x3), sqr (x1 - x4)));
    } else {
        if (x3 >= x1 && x3 <= x2 || x4 >= x1 && x4 <= x2)
            d = min (d, min (sqr (y1 - y3), sqr (y1 - y4)));
    }
    if (x3 == x4) {
        if (y1 >= y3 && y1 <= y4 || y2 >= y3 && y2 <= y4)
            d = min (d, min (sqr (x3 - x1), sqr (x3 - x2)));
    } else {
        if (x1 >= x3 && x1 <= x4 || x2 >= x3 && x2 <= x4)
            d = min (d, min (sqr (y3 - y1), sqr (y3 - y2)));
    }
    re d;
}

int main () {
    scanf ("%d%d", &a, &b);
    scanf ("%d%d%d%d", &ax, &ay, &bx, &by);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    x1[n] = x2[n] = ax;
    y1[n] = y2[n] = ay;
    n++;
    x1[n] = x2[n] = bx;
    y1[n] = y2[n] = by;
    n++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            g[i][j] = dist (x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j]);
//          printf ("%d %d = %.10f\n", i, j, sqrt (g[i][j] + 0.0));
        }   
    int l = 0, r = 1;
    q[0] = n - 2;
    was[n - 2] = 1;
    double res = 1e15;
    while (l < r) {
        int x = q[l++];
        if (g[x][n - 1] <= a * a) res = min (res, d[x] * (a + b) + sqrt (g[x][n - 1] + 0.0));
        for (int i = 0; i < n - 1; i++)
            if (g[x][i] <= a * a && !was[i]) {
                was[i] = 1;
                d[i] = d[x] + 1;
                q[r++] = i;
            }
    }
    if (res > 1e14) printf ("-1\n"); else printf ("%.10f\n", res);
    return 0;
}