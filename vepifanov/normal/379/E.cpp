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
double x[200000];
double y[200000];
double z[300][301];
double p[200000];
double q[200000];
int k;

int cross (D x1, D y1, D x2, D y2, D x3, D y3, D x4, D y4, D *ct) {
    D a = x2 - x1;
    D b = x3 - x4;
    D c = x3 - x1;
    D d = y2 - y1;
    D e = y3 - y4;
    D f = y3 - y1;
    if (abs (a * e - b * d) > 1e-7) {
        double t = (c * e - b * f) / (a * e - b * d);
        double s = (a * f - c * d) / (a * e - b * d);
        if (s > -1e-7 && s < 1 + 1e-7 && t > -1e-7 && t < 1 + 1e-7) {
            *ct = t;
            re 1;
        }   
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= k; j++)
            scanf ("%lf", &z[i][j]);
    int r = 0;
    double last = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            r = k + 1;
            for (int j = 0; j <= k; j++) {
                x[j] = j;
                y[j] = z[0][j];
            }   
        } else {
            int o = 0;
            for (int j = 0; j < r; j++) p[o++] = x[j];
            for (int j = 0; j + 1 < r; j++) {
                int t = (x[j] + x[j + 1]) / 2;
                double ct;
//              printf ("%.3f %.3f - %.3f %.3f : %d %.3f - %d %.3f\n", x[j], y[j], x[j + 1], y[j + 1], t, z[i][t], t + 1, z[i][t + 1]);
                if (cross (t, z[i][t], t + 1, z[i][t + 1], x[j], y[j], x[j + 1], y[j + 1], &ct)) {
//                  printf ("%.10f\n", ct);
                    p[o++] = t + ct;
                }   
            }
            sort (p, p + o);
            int oo = 0;
            for (int j = 0; j < o; j++)
                if (j == 0 || p[j] > p[j - 1] + 1e-7)   
                    p[oo++] = p[j];
            o = oo;
            for (int j = 0, a = 0, b = 0; j < o; j++) {
                while (x[a + 1] + 1e-7 < p[j]) a++;
                while (b + 1 + 1e-7 < p[j]) b++;
                q[j] = max ((y[a] + (y[a + 1] - y[a]) / (x[a + 1] - x[a]) * (p[j] - x[a])), z[i][b] + (z[i][b + 1] - z[i][b]) * (p[j] - b));
            }
            for (int j = 0; j < o; j++) {
                x[j] = p[j];
                y[j] = q[j];
            }
            r = o;
        }
        double cur = 0;
        for (int j = 0; j + 1 < r; j++)
            cur += (x[j + 1] - x[j]) * (y[j + 1] + y[j]) / 2;
        printf ("%.10f\n", cur - last);
//      for (int j = 0; j < r; j++) printf ("%.10f %.10f\n", x[j], y[j]);
        last = cur;
    }
    return 0;
}