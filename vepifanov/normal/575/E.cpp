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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 100000;

int n;
int m;
vii v;

void add (int x, int y) {
    v.pb (mp (x, y));
}

ll vect (ii a, ii b, ii c) {
    re (ll)(b.fi - a.fi) * (c.se - b.se) - (ll)(b.se - a.se) * (c.fi - b.fi);
}

ld dist (ii a, ii b) {
    re sqrt (sqr ((ld)a.fi - b.fi) + sqr ((ld)a.se - b.se));
}

ld getr (ii a, ii b, ii c) {
    ld A = dist (a, b);
    ld B = dist (a, c);
    ld C = dist (b, c);
    ld p = (A + B + C) / 2;
    ld S = 4 * sqrt (p * (p - A) * (p - B) * (p - C));
    re A * B * C / S;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y, d;
        scanf ("%d%d%d", &x, &y, &d);
        if (x >= d) add (x - d, y); else {
            int h = d - x;
            if (y + h > N) add (0, N); else add (0, y + h);
            if (y - h < 0) add (0, 0); else add (0, y - h);
        }
        if (x + d <= N) add (x + d, y); else {
            int h = x + d - N;
            if (y + h > N) add (N, N); else add (N, y + h);
            if (y - h < 0) add (N, 0); else add (N, y - h);
        }
        if (y >= d) add (x, y - d); else {
            int h = d - y;
            if (x + h > N) add (N, 0); else add (x + h, 0);
            if (x - h < 0) add (0, 0); else add (x - h, 0);
        }
        if (y + d <= N) add (x, y + d); else {
            int h = y + d - N;
            if (x + h > N) add (N, N); else add (x + h, N);
            if (x - h < 0) add (0, N); else add (x - h, N);
        }
    }
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    vii q1, q2;
    for (int i = 0; i < sz (v); i++) {
        while (sz (q1) > 1 && vect (q1[sz (q1) - 2], q1[sz (q1) - 1], v[i]) >= 0) q1.pop_back ();
        while (sz (q2) > 1 && vect (q2[sz (q2) - 2], q2[sz (q2) - 1], v[i]) <= 0) q2.pop_back ();
        q1.pb (v[i]);
        q2.pb (v[i]);
    }
    q2.pop_back ();
    reverse (all (q2));
    q2.pop_back ();
    for (int i = 0; i < sz (q2); i++) q1.pb (q2[i]);
    pair<ld, int> best (-1e100, 0);
    q1.pb (q1[0]);
    q1.pb (q1[1]);
    for (int i = 0; i + 2 < sz (q1); i++) {
        ld r = getr (q1[i], q1[i + 1], q1[i + 2]);
        best = max (best, mp (r, i));
//      printf ("%d = %.10f\n", i, (D)r);
    }
    printf ("%d %d\n", q1[best.se].fi, q1[best.se].se);
    printf ("%d %d\n", q1[best.se + 1].fi, q1[best.se + 1].se);
    printf ("%d %d\n", q1[best.se + 2].fi, q1[best.se + 2].se);
    return 0;
}