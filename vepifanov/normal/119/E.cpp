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
double x[900], y[900], z[900], ox[900], oy[900], oz[900];
double LX, RX, LY, RY;

double goxy (double x, double y) {
    double res = 0;
    for (int i = 0; i < n; i++) {
//      printf ("%.5f %.5f %.5f %.5f = %.10f\n", x, y, ::x[i], ::y[i], sqrt (sqr (x - ::x[i]) + sqr (y - ::y[i])));
        res = max (res, sqr (x - ::x[i]) + sqr (y - ::y[i]));
    }   
//  printf ("%.5f %.5f = %.10f\n", x, y, res);
    re res;
}

double goy (double x) {
    double l = LY, r = RY;
    for (int it = 0; it < 40; it++) {
        double s1 = l + (r - l) / 3;
        double s2 = l + 2 * (r - l) / 3;
        double f1 = goxy (x, s1), f2 = goxy (x, s2);
        if (f1 < f2) r = s2; else l = s1;
    }
    re goxy (x, (l + r) / 2);
}

double gox () {
    double l = LX, r = RX;
    for (int it = 0; it < 40; it++) {
        double s1 = l + (r - l) / 3;
        double s2 = l + 2 * (r - l) / 3;
        double f1 = goy (s1), f2 = goy (s2);
//      printf ("%.5f = %.10f , %.5f = %.10f\n", s1, f1, s2, f2);
        if (f1 < f2) r = s2; else l = s1;
//      printf ("%.10f .. %.10f\n", l, r);
    }
//  printf ("%.10f .. %.10f\n", l, r);
    re goy ((l + r) / 2);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%lf%lf%lf", &x[i], &y[i], &z[i]);
        ox[i] = x[i];
        oy[i] = y[i];
        oz[i] = z[i];
    }   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            x[j] = ox[j];
            y[j] = oy[j];
            z[j] = oz[j];
        }   
        double a, b, c;
        scanf ("%lf%lf%lf", &a, &b, &c);
        double cosa, sina;
        if (a * a + b * b > 1e-8) {
            cosa = b / sqrt (a * a + b * b);
            sina = a / sqrt (a * a + b * b);
            for (int j = 0; j < n; j++) {
                double nx = x[j] * cosa - y[j] * sina;
                double ny = x[j] * sina + y[j] * cosa;
                x[j] = nx;
                y[j] = ny;
            }
            sina = sqrt (a * a + b * b) / sqrt (a * a + b * b + c * c);
            cosa = c / sqrt (a * a + b * b + c * c);
            for (int j = 0; j < n; j++) {
                double ny = y[j] * cosa - z[j] * sina;
                double nz = y[j] * sina + z[j] * cosa;
                y[j] = ny;
                z[j] = nz;
            }
        }
        LX = LY = 1e9;
        RX = RY = -1e9;
        for (int j = 0; j < n; j++) {
            LX = min (LX, x[j]);
            LY = min (LY, y[j]);
            RX = max (RX, x[j]);
            RY = max (RY, y[j]);
        }
        printf ("%.10f\n", sqrt (gox ()));
    }
    return 0;
}