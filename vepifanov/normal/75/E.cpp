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
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int x[50], y[50];
double g[50][50];
int x1, y1, x2, y2;

int cross (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double *t) {
    int a = x2 - x1;
    int b = x3 - x4;
    int c = x3 - x1;
    int d = y2 - y1;
    int e = y3 - y4;
    int f = y3 - y1;
    int D = a * e - b * d;
    int T = c * e - b * f;
    int S = a * f - c * d;
    if (D == 0) re 0;
    if (D < 0) { D = -D; T = -T; S = -S; }
    *t = (T + 0.0) / D;
    if (T > 0 && T < D && S > 0 && S < D) re 1;
    if (T >= 0 && T <= D && S >= 0 && S <= D) re 2;
    re 0;
}

int vect (int x1, int y1, int x2, int y2) {
    re x1 * y2 - x2 * y1;
}

int scal (int x1, int y1, int x2, int y2) {
    re x1 * x2 + y1 * y2;
}

int ein (int x1, int y1, int x2, int y2, int x3, int y3) {
    re vect (x1 - x3, y1 - y3, x2 - x3, y2 - y3) == 0 && scal (x1 - x3, y1 - y3, x2 - x3, y2 - y3) < 0;
}

double dist (double x1, double y1, double x2, double y2) {
    re sqrt (sqr (x1 - x2) + sqr (y1 - y2));
}
             
int main() {
    scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d%d", &x[i], &y[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 1e15;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + 1) % n == j || (j + 1) % n == i || i == j)
                g[i][j] = sqrt (sqr (x[i] - x[j]) + sqr (y[i] - y[j]) + 0.0);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
    double len = sqrt (sqr (x1 - x2) + sqr (y1 - y2) + 0.0);
    double l = 1, r = 0, t;
    int li, ri;
    for (int i = 0; i < n; i++)
        if (cross (x1, y1, x2, y2, x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], &t)) {
            if (l > t) {
                l = t;
                li = i;
            }
            if (r < t) {
                r = t;
                ri = i;
            }
        }
    if (l < r) {
        double xa = x1 + (x2 - x1) * l;
        double ya = y1 + (y2 - y1) * l;
        double xb = x1 + (x2 - x1) * r;
        double yb = y1 + (y2 - y1) * r;
        double mlen = len - (r - l) * len;
        len += (r - l) * len;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                len = min (len, mlen + dist (xa, ya, x[(li + i) % n], y[(li + i) % n]) + g[(li + i) % n][(ri + j) % n] + dist (x[(ri + j) % n], y[(ri + j) % n], xb, yb));
    }   
    printf ("%.10f\n", len);
    return 0;
}