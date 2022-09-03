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

ii v[100000];
vii f, g;

int main () {
    scanf ("%d", &n);
    int p = 0, q = 0, lx = 1e9, rx = -1e9;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &v[i].fi, &v[i].se);
        if (v[i].fi < v[p].fi || v[i].fi == v[p].fi && v[i].se > v[p].se) p = i;
        if (v[i].fi > v[q].fi || v[i].fi == v[q].fi && v[i].se < v[q].se) q = i;
        lx = min (lx, v[i].fi);
        rx = max (rx, v[i].fi);
    }
    while (true) {
        f.pb (v[p]);
        int np = (p + 1) % n;
        if (v[np].fi > v[p].fi) p = np; else break;
    }
    while (true) {
        g.pb (v[q]);
        int nq = (q + 1) % n;
        if (v[nq].fi < v[q].fi) q = nq; else break;
    }
    reverse (all (g));
    scanf ("%d", &m);
    int ok = 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        if (x <= lx || x >= rx) { ok = 0; continue; }
        int l, r;
        l = 0, r = sz (f) - 1;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (f[s].fi > x) r = s; else l = s;
        }
        if ((ll)(y - f[l].se) * (f[l + 1].fi - f[l].fi) >= (ll)(x - f[l].fi) * (f[l + 1].se - f[l].se)) { ok = 0; continue; }
        l = 0, r = sz (g) - 1;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (g[s].fi > x) r = s; else l = s;
        }
        if ((ll)(y - g[l].se) * (g[l + 1].fi - g[l].fi) <= (ll)(x - g[l].fi) * (g[l + 1].se - g[l].se)) { ok = 0; continue; }
    }
    if (ok) printf ("YES\n"); else printf ("NO\n");
    return 0;
}