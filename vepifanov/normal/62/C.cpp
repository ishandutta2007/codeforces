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
int x[100][4], y[100][4];
vector<pair<double, int> > v;

double dist (double x1, double y1, double x2, double y2) {
    re sqrt (sqr (x2 - x1) + sqr (y2 - y1));
}

int cross (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, double *t) {
    ll a = x2 - x1;
    ll b = x3 - x4;
    ll c = x3 - x1;
    ll d = y2 - y1;
    ll e = y3 - y4;
    ll f = y3 - y1;
    if (a * e - b * d != 0) {
        ll T = c * e - b * f;
        ll S = a * f - c * d;
        ll D = a * e - b * d;
        if (D < 0) { T = -T; S = -S; D = -D; }
        if (S >= 0 && S <= D) {
            *t = (T + 0.0) / D;
            re 1;
        }
    }
    re 0;
}

int main() {
    scanf ("%d", &n);   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) scanf ("%d%d", &x[i][j], &y[i][j]);
        x[i][3] = x[i][0];
        y[i][3] = y[i][0];
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            double d = dist (x[i][j], y[i][j], x[i][j + 1], y[i][j + 1]), cur = 1;
            v.clear ();
            for (int k = 0; k < n; k++)
                if (k != i) {
                    double l = 1, r = 0, t;
                    for (int q = 0; q < 3; q++)
                        if (cross (x[i][j], y[i][j], x[i][j + 1], y[i][j + 1], x[k][q], y[k][q], x[k][q + 1], y[k][q + 1], &t)) {
                            if (t < 0) t = 0;
                            if (t > 1) t = 1;
                            l = min (l, t);
                            r = max (r, t);
                        }
                    if (l < r) {
                        v.pb (mp (l, 1));
                        v.pb (mp (r, -1));
                    }
                }   
            sort (all (v));
            int s = 0;
            for (int i = 0; i + 1 < sz (v); i++) {
                s += v[i].se;
                if (s != 0) cur -= v[i + 1].fi - v[i].fi;
            }
            ans += cur * d;
        }
    printf ("%.10f\n", ans);
    return 0;
}