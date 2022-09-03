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
const double eps = 1e-7;

int n;
int m;
double w, h, a;
vector<pair<double, pair<double, double> > > v;
double x1[5], y1[5], x2[5], y2[5];

int cross (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *x, double *y) {
    double a = x2 - x1;
    double b = x3 - x4;
    double c = x3 - x1;
    double d = y2 - y1;
    double e = y3 - y4;
    double f = y3 - y1;
    if (fabs (a * e - b * d) > eps) {
        double t = (c * e - b * f) / (a * e - b * d);
        double s = (a * f - c * d) / (a * e - b * d);
        if (t > -eps && t < 1 + eps && s > -eps && s < 1 + eps) {
            *x = x1 + (x2 - x1) * t;
            *y = y1 + (y2 - y1) * t;
            re 1;
        }
    }
    re 0;
}

int main () {
    cin >> w >> h >> a; w /= 2; h /= 2;
    a = a / 180 * pi;
    x1[0] = -w; y1[0] = -h;
    x1[1] = w; y1[1] = -h;
    x1[2] = w; y1[2] = h;
    x1[3] = -w; y1[3] = h;
    x1[4] = -w; y1[4] = -h;
    for (int i = 0; i < 5; i++) {
        x2[i] = x1[i] * cos (a) - y1[i] * sin (a);
        y2[i] = x1[i] * sin (a) + y1[i] * cos (a);
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            double xc, yc;
            if (cross (x1[i], y1[i], x1[i + 1], y1[i + 1], x2[j], y2[j], x2[j + 1], y2[j + 1], &xc, &yc)) {
                v.pb (mp (atan2 (yc, xc), mp (xc, yc)));
            }   
        }
    sort (all (v));
    v.pb (v[0]);
    double ans = 0;
    for (int i = 0; i + 1 < sz (v); i++)
        ans += v[i].se.fi * v[i + 1].se.se - v[i].se.se * v[i + 1].se.fi;
    printf ("%.10f\n", abs (ans / 2));
    return 0;
}