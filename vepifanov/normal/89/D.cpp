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

const double eps = 1e-10;

int n;
int m;
double ax, ay, az, vx, vy, vz, R, r, ox, oy, oz, px, py, pz;

double scal (double x1, double y1, double z1, double x2, double y2, double z2) {
    re x1 * x2 + y1 * y2 + z1 * z2;
}

double vect (double x1, double y1, double z1, double x2, double y2, double z2) {
    double x3 = y1 * z2 - y2 * z1;
    double y3 = z1 * x2 - z2 * x1;
    double z3 = x1 * y2 - x2 * y1;
    re sqrt (sqr (x3) + sqr (y3) + sqr (z3));
}

double dist1 (double x1, double y1, double z1, double x2, double y2, double z2) {
    re sqrt (sqr (x2 - x1) + sqr (y2 - y1) + sqr (z2 - z1));
}

double dist2 (double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
    double tmp = min (dist1 (x1, y1, z1, x2, y2, z2), dist1 (x1, y1, z1, x3, y3, z3));
    double s1 = scal (x1 - x2, y1 - y2, z1 - z2, x3 - x2, y3 - y2, z3 - z2);
    double s2 = scal (x1 - x3, y1 - y3, z1 - z3, x2 - x3, y2 - y3, z2 - z3);
    if (s1 > 0 && s2 > 0) {
        double d = dist1 (x2, y2, z2, x3, y3, z3);
        double s = vect (x2 - x1, y2 - y1, z2 - z1, x3 - x1, y3 - y1, z3 - z1);
        tmp = s / d;
    }
    re tmp;
}

double get1 (double x, double y, double z, double r) {
    double p = 0, q = 1e13;
    for (int it = 0; it < 300; it++) {
        double s1 = (2 * p + q) / 3;
        double s2 = (p + 2 * q) / 3;
        double d1 = dist1 (ax + vx * s1, ay + vy * s1, az + vz * s1, x, y, z);
        double d2 = dist1 (ax + vx * s2, ay + vy * s2, az + vz * s2, x, y, z);
        if (d1 < d2) q = s2; else p = s1;
    }
    double s = (p + q) / 2;
    double d = dist1 (ax + vx * s, ay + vy * s, az + vz * s, x, y, z);
    if (d > r + R + eps) re 1e15;
    p = 0; q = s;
    for (int it = 0; it < 300; it++) {
        s = (p + q) / 2;
        d = dist1 (ax + vx * s, ay + vy * s, az + vz * s, x, y, z);
        if (d > r + R) p = s; else q = s;
    }
    re q;
}

double get2 (double x1, double y1, double z1, double x2, double y2, double z2) {
    double p = 0, q = 1e13;
    for (int it = 0; it < 300; it++) {
        double s1 = (2 * p + q) / 3;
        double s2 = (p + 2 * q) / 3;
        double d1 = dist2 (ax + vx * s1, ay + vy * s1, az + vz * s1, x1, y1, z1, x2, y2, z2);
        double d2 = dist2 (ax + vx * s2, ay + vy * s2, az + vz * s2, x1, y1, z1, x2, y2, z2);
        if (d1 < d2) q = s2; else p = s1;
    }
    double s = (p + q) / 2;
    double d = dist2 (ax + vx * s, ay + vy * s, az + vz * s, x1, y1, z1, x2, y2, z2);
    if (d > R + eps) re 1e15;
    p = 0; q = s;
    for (int it = 0; it < 300; it++) {
        s = (p + q) / 2;
        d = dist2 (ax + vx * s, ay + vy * s, az + vz * s, x1, y1, z1, x2, y2, z2);
        if (d > R) p = s; else q = s;
    }
    re q;
}

int main () {
    cin >> ax >> ay >> az >> vx >> vy >> vz >> R >> n;
    double ans = 1e15;
    for (int i = 0; i < n; i++) {
        cin >> ox >> oy >> oz >> r >> m;
        ans = min (ans, get1 (ox, oy, oz, r));
        for (int j = 0; j < m; j++) {
            cin >> px >> py >> pz;
            ans = min (ans, get2 (ox, oy, oz, ox + px, oy + py, oz + pz));
        }
    }
    if (ans > 5e14) printf ("-1\n"); else printf ("%.10f\n", ans);
    return 0;
}