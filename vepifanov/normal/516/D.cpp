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

const int N = 1 << 17;

int n;
int m;
vii v[N];
ll res[N];
ll len[N];
ll h;
int f[N];
int tin[N];
int tout[N];
int ct;
vector<pair<ll, int> > u;
vector<pair<pair<ll, int>, int> > w;
int cur[N];

ll go (int x, int p) {
    ll cur = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        cur = max (cur, go (y, x) + z);
    }
    re len[x] = cur;
}

ll go2 (int x, int p, ll up) {
    pair<ll, int> b1 (0, -1), b2 (0, -1);
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        pair<ll, int> tmp = mp (len[y] + z, y);
        if (tmp > b1) {
            b2 = b1;
            b1 = tmp;
        } else
        if (tmp > b2)
            b2 = tmp;
    }
    res[x] = max (up, b1.fi);
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        ll tmp = up;
        if (y == b1.se) tmp = max (tmp, b2.fi); else tmp = max (tmp, b1.fi);
        go2 (y, x, tmp + z);
    }
    re 0;
}

int build (int x, int p) {
    tin[x] = ct++;
    u.pb (mp (res[x], x));
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        if (y == p) continue;
        build (y, x);
    }
    tout[x] = ct - 1;
    re 0;
}

int get (int x) {
    x++;
    int y = 0;
    while (x > 0) {
        y += f[x];
        x = (x & (x + 1)) - 1;
    }
    re y;
}

int get (int l, int r) {
    re get (r) - get (l - 1);
}

int add (int x) {
    x++;
    while (x <= n) {
        f[x]++;
        x |= x + 1;
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    go (0, 0);
    go2 (0, 0, 0);
    int r = 0;
    for (int i = 0; i < n; i++)
        if (res[i] < res[r])
            r = i;
    u.clear ();
    build (r, r);
    sort (all (u));
    scanf ("%d", &m);
    for (int it = 0; it < m; it++) {
        ll l;
        cin >> l;
        ct = 0;
        w.clear ();
        for (int j = 0; j < n; j++) cur[j] = 0;
        memset (f, 0, sizeof (f));
        int a = 0, b = 0;
        while (a < n || b < n)
            if (a < n && (b == n || u[a].fi <= u[b].fi + l)) {
                int c = u[a].se;
                w.pb (mp (mp (res[c], -1), c));
                a++;
            } else {
                int c = u[b].se;
                w.pb (mp (mp (res[c] + l, 1), c));
                b++;
            }
//      for (int i = 0; i < 2 * n; i++)
//          printf ("%I64d %d %d\n", w[i].fi.fi, w[i].fi.se, w[i].se);
        for (int i = 0; i < 2 * n; ) {
            int j = i;
            while (j < 2 * n && w[j].fi == w[i].fi) j++;
            for (int k = i; k < j; k++) {
                int c = w[k].se;
                cur[c] += w[k].fi.se * get (tin[c], tout[c]);
//              printf ("get %d %d %d = %d\n", c, tin[c], tout[c], cur[c]);
            }
            if (w[i].fi.se == -1)
                for (int k = i; k < j; k++) {
                    int c = w[k].se;
//                  printf ("add %d\n", tin[c]);
                    add (tin[c]);
                }
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max (ans, cur[i]);
        printf ("%d\n", ans);
    }
    cerr << clock () << endl;
    return 0;
}