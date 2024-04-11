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
int x[1002], y[1002];

ll vect (ll x1, ll y1, ll x2, ll y2) {
    re x1 * y2 - x2 * y1;
}

ll scal (ll x1, ll y1, ll x2, ll y2) {
    re x1 * x2 + y1 * y2;
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

int gcd (int a, int b) {
    if (!a) re b;
    re gcd (b % a, a);
}

int main() {
    scanf ("%d", &n);   
    for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
    x[n] = x[0];
    y[n] = y[0];
    int d = gcd (abs (x[1] - x[0]), abs (y[1] - y[0]));
    int dx = (x[1] - x[0]) / d;
    int dy = (y[1] - y[0]) / d;
    int l = 0, r = d;
    for (int i = 1; i < n; i++) {
        ll tmp = vect (x[1] - x[0], y[1] - y[0], x[i + 1] - x[i], y[i + 1] - y[i]);
        if (tmp != 0) {
            double t = cross (x[0], y[0], x[0] + dx, y[0] + dy, x[i], y[i], x[i + 1], y[i + 1]);
            if (tmp < 0) {
                if (t < -1e-6) r = -1; else r = min (r, (int)(t + 0.0000001));
            } else l = max (l, (int)(t + 0.9999999));
        } else
        if (scal (x[1] - x[0], y[1] - y[0], x[i + 1] - x[i], y[i + 1] - y[i]) > 0) {
            printf ("0\n");
            re 0;
        }
    }
    printf ("%d\n", max (0, r - l + 1));
    return 0;
}