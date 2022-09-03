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

const double eps = 1e-7;

int n;
int m;

int h[3000], r[3000], R[3000];
double y[3000];

double vect (double x1, double y1, double x2, double y2) {
    re x1 * y2 - x2 * y1;
}

int cross (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double v1 = vect (x3 - x1, y3 - y1, x2 - x1, y2 - y1);
    double v2 = vect (x4 - x1, y4 - y1, x2 - x1, y2 - y1);
    double v3 = vect (x1 - x3, y1 - y3, x4 - x3, y4 - y3);
    double v4 = vect (x2 - x3, y2 - y3, x4 - x3, y4 - y3);
    if (v1 > 0 && v2 > 0 || v1 < 0 && v2 < 0 || v3 > 0 && v4 > 0 || v3 < 0 && v4 < 0) re 0;
    re 1;
}

int bad (double yi, int i, int j) {
    double yj = y[j];
    if (yi < yj) re 1;
    if (cross (0, yi, r[i], yi, r[j], yj, R[j], yj + h[j]) || cross (r[i], yi, R[i], yi + h[i], r[j], yj, R[j], yj + h[j])) re 1;
    re 0;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d", &n);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d", &h[i], &r[i], &R[i]);
        y[i] = 0;
        for (int j = i - 1; j >= 0; j--)
            if (bad (y[i], i, j)) {
                double l = y[i], r = 1e9;
                for (int it = 0; it < 60; it++) {
                    double s = (l + r) / 2;
                    if (bad (s, i, j)) l = s; else r = s;
                }
                y[i] = (l + r) / 2;
            }
//      printf ("%.10f %d\n", y[i], h[i]);
        ans = max (ans, y[i] + h[i]);
    }
    printf ("%.10f\n", ans);
    return 0;
}