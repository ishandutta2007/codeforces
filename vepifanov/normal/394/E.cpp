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

int px[100001];
int py[100001];
int gx[100001];
int gy[100001];
double sy;

double get (double x, double y) {
    double cur = 0;
    for (int i = 0; i < n; i++) cur += sqr (x - gx[i]) + sqr (y - gy[i]);
    re cur;
}

double get (double x) {
    double l = 1e9, r = -1e9;
    for (int i = 0; i < m; i++)
        if (px[i] != px[i + 1] && min (px[i], px[i + 1]) <= x && max (px[i], px[i + 1]) >= x) {
            double y = py[i] + (py[i + 1] - py[i]) * (x - px[i]) / (px[i + 1] - px[i]);
            l = min (l, y);
            r = max (r, y);
        }
    if (sy > r) re get (x, r);
    if (sy < l) re get (x, l);
    re get (x, sy);
}

int main () {
    scanf ("%d", &n);
    sy = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &gx[i], &gy[i]);
        sy += gy[i];
    }   
    sy /= n;
    scanf ("%d", &m);
    double l = 1e9, r = -1e9;
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &px[i], &py[i]);
        l = min (l, (D)px[i]);
        r = max (r, (D)px[i]);
    }
    px[m] = px[0];
    py[m] = py[0];
    for (int it = 0; it < 100; it++) {
        double s1 = (2 * l + r) / 3;
        double s2 = (l + 2 * r) / 3;
        double h1 = get (s1);
        double h2 = get (s2);
        if (h1 < h2) r = s2; else l = s1;
    }
    printf ("%.10f\n", get ((l + r) / 2));
    return 0;
}