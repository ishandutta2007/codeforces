#include <bits/stdc++.h>

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
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

#define filename ""

const int N = 200000;

int n;
int m;
int good[2 * N];
int was[2 * N];
int used[2 * N];
int res[2 * N];
vii v[2 * N];
vi vn[2 * N], vp[2 * N];

int go (int x, int p, int pe) {
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (abs (z - pe) == m) continue;
        if (was[y] == 1) {
            if (!good[y]) {
                good[y] = 1;
                used[z % m] = 1;
                if (z < m) res[z] = 1;
            }
        } else
        if (!was[y])
            go (y, x, z);
    }
    was[x] = 2;
    re 0;
}

int go2 (int x) {
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (!was[y] && !used[z % m]) {
            if (z < m) res[z] = 1;
            go2 (y);
        }
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf ("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf ("%d", &x);
            if (x > 0) vp[x - 1].pb (i); else vn[abs (x) - 1].pb (i);
        }
    }
    for (int i = 0; i < m; i++) {
        if (vn[i].empty () && vp[i].empty ()) continue;
        if (sz (vp[i]) == 0) {
            res[i] = 0;
            good[vn[i][0]] = 1;
            if (sz (vn[i]) > 1) good[vn[i][1]] = 1;
        } else
        if (sz (vn[i]) == 0) {
            res[i] = 1;
            good[vp[i][0]] = 1;
            if (sz (vp[i]) > 1) good[vp[i][1]] = 1;
        } else {
            v[vp[i][0]].pb (mp (vn[i][0], i + m));
            v[vn[i][0]].pb (mp (vp[i][0], i));
        }
    }
    for (int i = 0; i < n; i++)
        if (!was[i])
            go (i, -1, -1);
    memset (was, 0, sizeof (was));
    for (int i = 0; i < n; i++)
        if (!was[i] && good[i])
            go2 (i);
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            printf ("NO\n");
            re 0;
        }
    printf ("YES\n");
    for (int i = 0; i < m; i++) printf ("%d", res[i]);
    printf ("\n");
    re 0;
}