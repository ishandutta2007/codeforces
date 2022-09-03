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

ii v[200000];
set<ii> all, rs;
vii res;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &v[i].fi, &v[i].se);
        v[i].fi *= 2;
        v[i].se *= 2;
        all.insert (v[i]);
    }
    if (n <= m) {
        printf ("-1\n");
        re 0;
    }
    sort (v, v + n);
    for (int i = 0; i < n && i <= m; i++)
        for (int j = 0; i <= n - j - 1 && i + j <= m; j++) {
            int cx = v[i].fi + v[n - j - 1].fi;
            int cy = v[i].se + v[n - j - 1].se;
            int ok = 0;
            for (int k = 0; k < n && ok <= m; k++) {
                int px = cx - v[k].fi;
                int py = cy - v[k].se;
                if (!all.count (mp (px, py)))
                    ok++;
            }
            if (ok <= m && !rs.count (mp (cx, cy))) {
                res.pb (mp (cx, cy));
                rs.insert (mp (cx, cy));
            }   
        }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%.1f %.1f\n", res[i].fi / 4.0, res[i].se / 4.0);
    return 0;
}