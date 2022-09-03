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
int x[100001];
int y[100001];

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int up (ii a, ii b, int c) {
    ll p = (ll)a.se * (b.fi - a.fi) + (ll)(b.se - a.se) * (c - a.fi);
    ll q = b.fi - a.fi;
    if (p < 0) re p / q;
    re (p + q - 1) / q;
}

int down (ii a, ii b, int c) {
    ll p = (ll)a.se * (b.fi - a.fi) + (ll)(b.se - a.se) * (c - a.fi);
    ll q = b.fi - a.fi;
    if (p > 0) re p / q;
    re (p - q + 1) / q;
}

double calc () {
//  for (int i = 0; i < n; i++) printf ("%d %d\n", x[i], y[i]);
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] < x[a] || (x[i] == x[a] && y[i] < y[a])) a = i;
        if (x[i] > x[b] || (x[i] == x[b] && y[i] < y[b])) b = i;
        if (x[i] < x[c] || (x[i] == x[c] && y[i] > y[c])) c = i;
        if (x[i] > x[d] || (x[i] == x[d] && y[i] > y[d])) d = i;
    }
    vii v, w;
    for (int i = a; i != b; i = (i + 1) % n) v.pb (mp (x[i], y[i]));
    v.pb (mp (x[b], y[b]));
    for (int i = d; i != c; i = (i + 1) % n) w.pb (mp (x[i], y[i]));
    w.pb (mp (x[c], y[c]));
    reverse (all (w));
    int i = 0, j = 0;
    double s = 0, sx = 0, sxx = 0, ans = 0;
    for (int c = x[a]; c <= x[b]; c++) {
        while (v[i + 1].fi < c) i++;
        while (w[j + 1].fi < c) j++;
        int l = up (v[i], v[i + 1], c);
        int r = down (w[j], w[j + 1], c);
        int cur = r - l + 1;
        ans += cur * (s * (c + 0.0) * c - 2 * sx * c + sxx);
        s += cur;
        sx += (c + 0.0) * cur;
        sxx += sqr (c + 0.0) * cur;
//      printf ("%d = %d %d , %d %d, %d\n", cur, v[i].fi, v[i].se, w[j].fi, w[j].se, c);
    }
//  printf ("\n%.10f\n", ans / (s * (s - 1) / 2));
    re ans;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
    x[n] = x[0];
    y[n] = y[0];
    double sum = 0;
    for (int i = 0; i < n; i++) sum += (double)x[i] * y[i + 1] - (double)x[i + 1] * y[i];
    if (sum < 0) {
        reverse (x, x + n + 1);
        reverse (y, y + n + 1);
        sum = -sum;
    }
    sum /= 2;
//  printf ("%.10f\n", sum);
    double cnt = 0;
    for (int i = 0; i < n; i++) cnt += gcd (abs (x[i + 1] - x[i]), abs (y[i + 1] - y[i]));
//  printf ("%.10f\n", cnt);
    cnt += (sum + 1 - cnt / 2);
//  printf ("%.10f\n", cnt);
    double ans = calc ();
    for (int i = 0; i <= n; i++) swap (x[i], y[i]);
    reverse (x, x + n + 1);
    reverse (y, y + n + 1);
    ans += calc ();
    printf ("%.10f\n", ans / (cnt * (cnt - 1) / 2) / 2);
    return 0;
}