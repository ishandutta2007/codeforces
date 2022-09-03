#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef double D;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const D eps = 1e-12;

int n;
int m;
int x[10001], y[10001], z[10001];
int vp, vs, px, py, pz;

D dist (D x1, D y1, D z1, D x2, D y2, D z2) {
    re sqrt (sqr (x2 - x1) + sqr (y2 - y1) + sqr (z2 - z1));
}

int main() {
    scanf ("%d", &n);   
    for (int i = 0; i <= n; i++)
        scanf ("%d%d%d", &x[i], &y[i], &z[i]);
    scanf ("%d%d", &vp, &vs);
    scanf ("%d%d%d", &px, &py, &pz);
    D ct = 0;
    for (int i = 1; i <= n; i++) {
        D ds = dist (x[i - 1], y[i - 1], z[i - 1], x[i], y[i], z[i]);
        D dp = dist (px, py, pz, x[i], y[i], z[i]);
        if (ct + ds / vs > dp / vp - eps) {
            D l = 0, r = 1;
            for (int it = 0; it < 200; it++) {
                D s = (l + r) / 2;
                D cx = x[i - 1] + (x[i] - x[i - 1]) * s;
                D cy = y[i - 1] + (y[i] - y[i - 1]) * s;
                D cz = z[i - 1] + (z[i] - z[i - 1]) * s;
                D ds = dist (x[i - 1], y[i - 1], z[i - 1], cx, cy, cz);
                D dp = dist (px, py, pz, cx, cy, cz);
                if (ct + ds / vs > dp / vp - eps) r = s; else l = s;
            }
            D s = (l + r) / 2;
            D cx = x[i - 1] + (x[i] - x[i - 1]) * s;
            D cy = y[i - 1] + (y[i] - y[i - 1]) * s;
            D cz = z[i - 1] + (z[i] - z[i - 1]) * s;
            D ds = dist (x[i - 1], y[i - 1], z[i - 1], cx, cy, cz);
            printf ("YES\n");
            printf ("%.10f\n", ct + ds / vs);
            printf ("%.10f %.10f %.10f\n", cx, cy, cz);
            re 0;
        }
        ct += ds / vs;
    }                                           
    printf ("NO\n");
    return 0;
}