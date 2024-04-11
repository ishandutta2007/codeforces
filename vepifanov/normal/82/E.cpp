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
typedef double D;
typedef pair<int, int> ii;
typedef pair<D, D> pdd;
typedef vector<pdd> vdd;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const double eps = 1e-5;

int n;
int m;
int l[500], r[500], h, f;
double L[500], R[500];

bool cross (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, D *xc, D *yc) {
    int a = x2 - x1;
    int b = x3 - x4;
    int c = x3 - x1;
    int d = y2 - y1;
    int e = y3 - y4;
    int f = y3 - y1;
    int P = a * e - b * d;
    if (!P) re false;
    int T = c * e - b * f;
    D t = (T + 0.0) / P;
    *xc = x1 + (x2 - x1) * t;
    *yc = y1 + (y2 - y1) * t;
    re true;
}

bool _in (D x, D y, int i, int j) {
    if (y > h + eps || y < -h - eps) re false;
    D l1 = (l[i] + 0.0) / (f - h) * (f - y);
    D r1 = (r[i] + 0.0) / (f - h) * (f - y);
    D l2 = (l[j] + 0.0) / (f - h) * (y + f);
    D r2 = (r[j] + 0.0) / (f - h) * (y + f);
    re (x > l1 - eps && x < r1 + eps && x > l2 - eps && x < r2 + eps);
}

D vect (D x1, D y1, D x2, D y2) {
    re x1 * y2 - x2 * y1;
}

bool l1 (pdd a, pdd b) {
    re a.se < b.se - eps || fabs (a.se - b.se) < eps && a.fi < b.fi;
}

bool l2 (pdd a, pdd b) {
    re a.fi < b.fi - eps || fabs (a.fi - b.fi) < eps && a.se < b.se;
}

bool l3 (pdd a, pdd b) {
    re a.se > b.se + eps || fabs (a.se - b.se) < eps && a.fi < b.fi;
}

bool l4 (pdd a, pdd b) {
    re a.fi > b.fi + eps || fabs (a.fi - b.fi) < eps && a.se < b.se;
}


double go (vdd w) {
    vdd u;
    int m = sz (w);
    int r = 0;
    double lx = w[0].fi, rx = w[0].fi, ly = w[0].se, ry = w[0].se;
    for (int i = 0; i < m; i++) {
        lx = min (lx, w[i].fi);
        rx = max (rx, w[i].fi);
        ly = min (ly, w[i].se);
        ry = max (ry, w[i].se);
    }   
    sort (all (w), l1);
    for (int i = 0; i < m; i++)
        if (fabs (w[i].fi - lx) < eps)
            u.pb (w[i]);
    sort (all (w), l2);
    for (int i = 0; i < m; i++)
        if (fabs (w[i].se - ry) < eps)
            u.pb (w[i]);
    sort (all (w), l3);
    for (int i = 0; i < m; i++)
        if (fabs (w[i].fi - rx) < eps)
            u.pb (w[i]);
    sort (all (w), l4);
    for (int i = 0; i < m; i++)
        if (fabs (w[i].se - ly) < eps)
            u.pb (w[i]);
    double res = 0;
    u.pb (u[0]);
    for (int i = 0; i + 1 < sz (u); i++)
        res += vect (u[i + 1].fi, u[i + 1].se, u[i].fi, u[i].se);
    re fabs (res) / 2;
}

int main() {
    scanf ("%d%d%d", &n, &h, &f);   
    for (int i = 0; i < n; i++) scanf ("%d%d", &l[i], &r[i]);
    D sum = 0;
    for (int i = 0; i < n; i++) {
        int l = ::l[i], r = ::r[i];
        D L = l, R = r;
        L = L / (f - h) * (f + h);
        R = R / (f - h) * (f + h);
        sum += 2 * h * (r - l + R - L);
        ::R[i] = R;
        ::L[i] = L;
    }
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                vdd v;
                v.pb (mp (l[i], h));
                v.pb (mp (r[i], h));
                v.pb (mp (L[i], -h));
                v.pb (mp (R[i], -h));
                v.pb (mp (l[j], -h));
                v.pb (mp (r[j], -h));
                v.pb (mp (L[j], h));
                v.pb (mp (R[j], h));
                D xc, yc;
                if (cross (0, f, l[i], h, 0, -f, l[j], -h, &xc, &yc)) v.pb (mp (xc, yc));
                if (cross (0, f, l[i], h, 0, -f, r[j], -h, &xc, &yc)) v.pb (mp (xc, yc));
                if (cross (0, f, r[i], h, 0, -f, l[j], -h, &xc, &yc)) v.pb (mp (xc, yc));
                if (cross (0, f, r[i], h, 0, -f, r[j], -h, &xc, &yc)) v.pb (mp (xc, yc));
                vdd w;
                for (int k = 0; k < sz (v); k++)
                    if (_in (v[k].fi, v[k].se, i, j))
                        w.pb (v[k]);
                if (sz (w)) sum -= go (w);
            }
    printf ("%.10f\n", sum);
    return 0;
}