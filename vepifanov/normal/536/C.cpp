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

const int N = 200000;

int n;
int m;
pair<ii, int> v[N];
int x[N];
int y[N];
vii w[N];
int bad[N];
int q[N + 10];

bool l1 (pair<ii, int> a, pair<ii, int> b) {
    if (a.fi.fi != b.fi.fi)
        re a.fi.fi < b.fi.fi;
    if (a.fi.se != b.fi.se) 
        re a.fi.se > b.fi.se;
    re a.se < b.se; 
}

ll vect (int a, int b, int c) {
    ll xa = v[a].fi.fi;
    ll ya = v[a].fi.se;
    ll xb = v[b].fi.fi;
    ll yb = v[b].fi.se;
    ll xc = v[c].fi.fi;
    ll yc = v[c].fi.se;
    re xc * yb * (xa - xb) * (ya - yc) - xb * yc * (xa - xc) * (ya - yb);
}

ll vect (ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
    re xc * yb * (xa - xb) * (ya - yc) - xb * yc * (xa - xc) * (ya - yb);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &v[i].fi.fi, &v[i].fi.se);
        x[i] = v[i].fi.fi;
        y[i] = v[i].fi.se;
        v[i].se = i;
    }
    sort (v, v + n);
    int top = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (top >= v[i].fi.se) bad[v[i].se] = 1;
        if (i == 0 || v[i - 1].fi != v[i].fi) top = max (top, v[i].fi.se);
    }
    {
        sort (v, v + n, l1);
        int o = 0;
        for (int i = 0; i < n; i++) {
            while (o > 1 && vect (i, q[o - 2], q[o - 1]) >= 0) o--;
            if (o > 0) {
                w[v[i].se].pb (v[q[o - 1]].fi);
            }   
            q[o++] = i;
        }
    }
    for (int i = 0; i < n; i++) swap (v[i].fi.fi, v[i].fi.se);
    {
        sort (v, v + n, l1);
        int o = 0;
        for (int i = 0; i < n; i++) {
            while (o > 1 && vect (i, q[o - 2], q[o - 1]) >= 0) o--;
            if (o > 0) {
                w[v[i].se].pb (mp (v[q[o - 1]].fi.se, v[q[o - 1]].fi.fi));
            }   
            q[o++] = i;
        }
    }
    for (int i = 0; i < n; i++)
        if (sz (w[i]) == 2 && vect (x[i], y[i], w[i][0].fi, w[i][0].se, w[i][1].fi, w[i][1].se) < 0)
            bad[i] = 1;
    for (int i = 0; i < n; i++)
        if (!bad[i])
            printf ("%d ", i + 1);
    printf ("\n");
    return 0;
}