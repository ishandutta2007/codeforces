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
#define sqrt(x) sqrt(abs(x))

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
        re x > 0 ? x : -x;
}

const double eps = 1e-7;
const double pi = 2 * asin (1.0);

int n;
int m;
double xp, yp, vp, x, y, v, r;

double dist (double x1, double y1, double x2, double y2) {
        re sqrt (sqr (x2 - x1) + sqr (y2 - y1));
}

vector<pair<double, double> > get (double x, double y) {
        double d = sqrt (x * x + y * y);
        double dx = -x / d;
        double dy = -y / d;
        double h = sqrt (d * d - r * r);
        double ang = atan2 (r, h);
        vector<pair<double, double> > v;
        double x1 = x + (dx * cos (ang) - dy * sin (ang)) * h;
        double y1 = y + (dx * sin (ang) + dy * cos (ang)) * h;
        double x2 = x + (dx * cos (-ang) - dy * sin (-ang)) * h;
        double y2 = y + (dx * sin (-ang) + dy * cos (-ang)) * h;
        v.pb (mp (x1, y1));
        v.pb (mp (x2, y2));
        re v;
}

double geth (double x1, double y1, double x2, double y2) {
        double l = 0, r = 1;
        for (int it = 0; it < 200; it++) {
                double s1 = l + (r - l) / 3;
                double s2 = r - (r - l) / 3;
                double h1 = sqrt (sqr (x1 + (x2 - x1) * s1) + sqr (y1 + (y2 - y1) * s1));
                double h2 = sqrt (sqr (x1 + (x2 - x1) * s2) + sqr (y1 + (y2 - y1) * s2));
                if (h1 < h2) r = s2; else l = s1;
        }
        re sqrt (sqr (x1 + (x2 - x1) * l) + sqr (y1 + (y2 - y1) * l));
}

int can (double t) {
        double R = sqrt (xp * xp + yp * yp);
        double ang = vp * t / R;
        double xx = xp * cos (ang) - yp * sin (ang);
        double yy = xp * sin (ang) + yp * cos (ang);
        double d = dist (x, y, xx, yy);
        if (geth (x, y, xx, yy) < r - eps) {
                vector<pair<double, double> > v1 = get (x, y);
                vector<pair<double, double> > v2 = get (xx, yy);
                d = 1e18;
                for (int i = 0; i < 2; i++)
                        for (int j = 0; j < 2; j++) {
                                double a1 = atan2 (v1[i].fi, v1[i].se);
                                double a2 = atan2 (v2[j].fi, v2[j].se);
                                double ang = min (abs (a1 - a2), 2 * pi - abs (a1 - a2));
                                double cd = dist (x, y, v1[i].fi, v1[i].se) + dist (xx, yy, v2[j].fi, v2[j].se) + ang * r;
                                d = min (d, cd);
                        }
        }
        if (d > t * ::v) re 0;
        re 1;
}

int main() {
        scanf ("%lf%lf%lf", &xp, &yp, &vp);
        scanf ("%lf%lf%lf%lf", &x, &y, &v, &r);
        double l = 0, r = 1e9;
        for (int it = 0; it < 100; it++) {
                double s = (l + r) / 2;
                if (can (s)) r = s; else l = s;
        }
        printf ("%.10f\n", (l + r) / 2);
        return 0;
}