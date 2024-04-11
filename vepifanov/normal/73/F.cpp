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

const double pi = 2 * asin (1.0);

int n;
int m;
double x[10000], y[10000], a[10000], w[10000];
double ax, ay, bx, by;

double dist (double x1, double y1, double x2, double y2) {
    re sqrt (sqr (x2 - x1) + sqr (y2 - y1));
}

double get (int i, double x, double y) {
    double b = atan2 (y - ::y[i], x - ::x[i]);
    double ang = abs (a[i] - b);
    if (ang > 2 * pi) ang -= 2 * pi;
    re min (ang, 2 * pi - ang) / w[i];
}

double cross (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double a = x2 - x1;
    double b = x3 - x4;
    double c = x3 - x1;
    double d = y2 - y1;
    double e = y3 - y4;
    double f = y3 - y1;
    re (c * e - b * f) / (a * e - b * d);
}

int calc (double v) {
    int tmp = 0;
    double d = dist (ax, ay, bx, by);
    double dx = (bx - ax);
    double dy = (by - ay);
    double t = d / v;
    for (int i = 0; i < n; i++) {
        if (w[i] < 1e-6) continue;
        if (get (i, bx, by) < t) tmp++; else {
            double l = 0, r = max (0.0, min (1.0, cross (ax, ay, bx, by, x[i], y[i], x[i] + (by - ay), y[i] + (ax - bx))));
            for (int it = 0; it < 40; it++) {
                double s1 = (2 * l + r) / 3;
                double s2 = (l + 2 * r) / 3;
                double d1 = get (i, ax + dx * s1, ay + dy * s1) - t * s1;
                double d2 = get (i, ax + dx * s2, ay + dy * s2) - t * s2;
                if (d1 < d2) r = s2; else l = s1;
            }
            double ss = (l + r) / 2;
            double dd = get (i, ax + dx * ss, ay + dy * ss) - t * ss;
            if (dd < 0) tmp++;
        }
        }
    re tmp;
}

int main () {
    cin >> ax >> ay >> bx >> by >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> a[i] >> w[i];
    cin >> m;
    double l = 0, r = 1e10;
    for (int it = 0; it < 60; it++) {
        double s = (l + r) / 2;
        if (calc (s) <= m) r = s; else l = s;
    }
    printf ("%.10f\n", r);
    return 0;
}