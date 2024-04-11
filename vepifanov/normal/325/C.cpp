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

const int MAX = 314000000;

int n;
int m;

vii u[100000];
vii rw[100000];
vector<pair<ii, ii> > v[100000];
int inf[100000];
int r1[100000];
int r2[100000];
int was[100000];
int cv[100000];
set<ii> all;

int go2 (int x) {
    if (was[x] == 1) re inf[x] = 1;
    was[x] = 1;
    for (int i = 0; i < sz (u[x]); i++)
        if (!v[x][u[x][i].se].fi.fi && go2 (u[x][i].fi)) {
            inf[x] = 1;
            break;
        }
    was[x] = 2;
    re inf[x];
}

int main () {
    scanf ("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        int a, b, c = 0;
        scanf ("%d%d", &a, &b); a--;
        int d = sz (v[a]);
        vi w;
        for (int j = 0; j < b; j++) {
            int x;
            scanf ("%d", &x);
            if (x == -1) c++; else {
                x--;
                w.pb (x);
                rw[x].pb (mp (a, d));
                u[a].pb (mp (x, d));
            }
        }
        v[a].pb (mp (mp (c, b - c), mp (c, b - c)));
    }

    for (int i = 0; i < n; i++) r1[i] = r2[i] = -1;

    {
        all.clear ();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz (v[i]); j++)
                if (v[i][j].fi.se == 0)
                    all.insert (mp (v[i][j].fi.fi, i));
        memset (was, 0, sizeof (was));
        while (!all.empty ()) {
            int x = all.begin ()->fi;
            int y = all.begin ()->se;
            all.erase (all.begin ());
            if (was[y]) continue;
            r1[y] = x;
            was[y] = 1;
            for (int i = 0; i < sz (rw[y]); i++) {
                int z = rw[y][i].fi;
                int t = rw[y][i].se;
                v[z][t].fi.fi = min (MAX, v[z][t].fi.fi + x);
                v[z][t].fi.se--;
                if (v[z][t].fi.se == 0) all.insert (mp (v[z][t].fi.fi, z));
            }
        }
    }

    {
        memset (was, 0, sizeof (was));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < sz (v[i]); j++)
                v[i][j].fi.fi = 0;
        for (int i = 0; i < n; i++)
            if (r1[i] == -1)
                for (int j = 0; j < sz (rw[i]); j++)
                    v[rw[i][j].fi][rw[i][j].se].fi.fi = 1;
        for (int i = 0; i < n; i++) {
            cv[i] = 0;
            for (int j = 0; j < sz (v[i]); j++)
                if (!v[i][j].fi.fi && v[i][j].se.se > 0)
                    cv[i]++;
        }
        all.clear ();
        for (int i = 0; i < n; i++)
            if (r1[i] != -1 && cv[i] == 0)
                for (int j = 0; j < sz (v[i]); j++)
                    if (!v[i][j].fi.fi && v[i][j].se.se == 0)
                        all.insert (mp (-v[i][j].se.fi, i));
        memset (was, 0, sizeof (was));
        while (!all.empty ()) {
            int x = -all.begin ()->fi;
            int y = all.begin ()->se;
            all.erase (all.begin ());
//          printf ("%d - %d\n", y + 1, x);
            if (was[y]) continue;
            r2[y] = x;
            was[y] = 1;
            for (int i = 0; i < sz (rw[y]); i++) {
                int z = rw[y][i].fi;
                int t = rw[y][i].se;
                if (r1[z] == -1) continue;
                v[z][t].se.fi = min (MAX, v[z][t].se.fi + x);
                v[z][t].se.se--;
                if (v[z][t].se.se == 0) {
                    cv[z]--;
                    if (cv[z] == 0)
                        for (int j = 0; j < sz (v[z]); j++)
                            if (!v[z][j].fi.fi && v[z][j].se.se == 0)
                                all.insert (mp (-v[z][j].se.fi, z));
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (r1[i] != -1 && r2[i] == -1) r2[i] = -2;
    }
    for (int i = 0; i < n; i++) printf ("%d %d\n", r1[i], r2[i]);
    return 0;
}