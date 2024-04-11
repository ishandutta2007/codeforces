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
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
vector<pair<D, D> > all;
D t1, t2, x0, y0, x1, y1, x2, y2, d01, d02, d12;

const D eps = 1e-11;

D dist (D x1, D y1, D x2, D y2) {
    return sqrt (sqr (x2 - x1) + sqr (y2 - y1));
}

int cross (D x1, D y1, D r1, D x2, D y2, D r2) {
    D d = dist (x1, y1, x2, y2);
    if (d > r1 + r2 + eps) return 0;
    if (min (r1, r2) + d < max (r1, r2) - eps) return -1;
    D A = 2 * (x2 - x1);
    D B = 2 * (y2 - y1);
    D C = x1 * x1 + y1 * y1 - r1 * r1 - x2 * x2 - y2 * y2 + r2 * r2;
    D ax, ay, bx, by;
    if (fabs (A) > eps) {
        ay = 0;
        by = 1;
        ax = -C / A;
        bx = -(B + C) / A;
    } else {
        ax = 0;
        bx = 1;
        ay = -C / B;
        by = -(A + C) / B;
    }
    D dx = bx - ax, dy = by - ay;
    D a = dx * dx + dy * dy;
    D b = (2 * ax * dx - 2 * dx * x1 + 2 * ay * dy - 2 * dy * y1);
    D c = (ax * ax + x1 * x1 - 2 * ax * x1 + ay * ay + y1 * y1 - 2 * ay * y1 - r1 * r1);
    d = b * b - 4 * a * c;
    if (d < -eps) return 0;
    if (fabs (d) < eps) d = 0;
    D t = (-b + sqrt (d)) / (2 * a);
    D xc1, yc1, xc2, yc2;
    xc1 = ax + dx * t;
    yc1 = ay + dy * t;
    t = (-b - sqrt (d)) / (2 * a);
    xc2 = ax + dx * t;
    yc2 = ay + dy * t;
    all.push_back (make_pair (xc1, yc1));
    all.push_back (make_pair (xc2, yc2));
    return 1;
}

int cross (D ax, D ay, D bx, D by, D x1, D y1, D r1) {
    D dx = bx - ax, dy = by - ay;
    D a = dx * dx + dy * dy;
    D b = (2 * ax * dx - 2 * dx * x1 + 2 * ay * dy - 2 * dy * y1);
    D c = (ax * ax + x1 * x1 - 2 * ax * x1 + ay * ay + y1 * y1 - 2 * ay * y1 - r1 * r1);
    D d = b * b - 4 * a * c;
    if (d < -eps) return 0;
    if (fabs (d) < eps) d = 0;
    D t = (-b + sqrt (d)) / (2 * a);
    D xc1, yc1, xc2, yc2;
    xc1 = ax + dx * t;
    yc1 = ay + dy * t;
    t = (-b - sqrt (d)) / (2 * a);
    xc2 = ax + dx * t;
    yc2 = ay + dy * t;
    all.push_back (make_pair (xc1, yc1));
    all.push_back (make_pair (xc2, yc2));
    return 1;
}

int check (D R) {
    D r1 = d01 + t1 - R;
    D r2 = d02 + t2 - R;
    all.clear ();   
    int r12 = cross (x1, y1, r1, x2, y2, r2);
    int r01 = cross (x1, y1, r1, x0, y0, R);
    int r02 = cross (x2, y2, r2, x0, y0, R);
//  printf ("%.10f = %.10f %.10f %d %d %d\n", R, r1, r2, r01, r02, r12);
    if (r12 > 0)
        cross (all[0].fi, all[0].se, all[1].fi, all[1].se, x0, y0, R);
    if (r01 == -1 && r02 == -1 && r12 != 0) return 1;
    for (int i = 0; i < all.size (); i++) {
        D d0 = dist (x0, y0, all[i].first, all[i].second);
        D d1 = dist (x1, y1, all[i].first, all[i].second);
        D d2 = dist (x2, y2, all[i].first, all[i].second);
//      printf ("   %.10f %.10f %.10f\n", d0 - R, d1 - r1, d2 - r2);
        if (d0 < R + eps && d1 < r1 + eps && d2 < r2 + eps)
            return 1;
    }
    return 0;
}

int main() {
    cin >> t2 >> t1 >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    d01 = dist (x0, y0, x1, y1);
    d02 = dist (x0, y0, x2, y2);
    d12 = dist (x2, y2, x1, y1);
    D ans = 0;
    D l = 0, r = min (d01 + t1, d02 + t2);
    for (int it = 0; it < 200; it++) {
        D s = (l + r) / 2;
        if (check (s)) l = s; else r = s;
    }
    ans = r;
    if (t1 + d01 + d12 < d02 + t2 + eps) ans = max (ans, d01 + t1);
    if (d02 + d12 < d01 + t1 + eps) ans = max (ans, min (d01 + t1, t2 + d02 + d12));
    printf ("%.10f\n", (double)ans);
    return 0;
}