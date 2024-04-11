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
#include <unordered_set>

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
vii w, u;
int r;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf ("%d%d", &v[i].fi, &v[i].se);
    sort (v, v + m);
    w.pb (mp (1, 1));
    for (int i = 0; i < m;) {
        if ((i == 0 && v[i].fi > 1) || (i > 0 && v[i - 1].fi + 1 < v[i].fi)) {
            w[0].se = n;
            w.resize (1);
        }
        int j = i;
        while (j < m && v[j].fi == v[i].fi) j++;
        u.clear ();
        for (int p = 0, q = i; p < sz (w); p++) {
            while (q < j && w[p].fi > v[q].se) q++;
            while (true) {
                if (q < j && w[p].se >= v[q].se) {
                    if (w[p].fi <= v[q].se - 1)
                        u.pb (mp (w[p].fi, v[q].se - 1));
                    w[p].fi = v[q].se + 1;
                    q++;
                } else {
                    if (w[p].fi <= w[p].se)
                        u.pb (w[p]);
                    break;
                }   
            }
        }
        if (u.empty ()) {
            printf ("-1\n");
            re 0;
        }
        for (int p = 0, q = i; p < sz (u); p++) {
            while (q < j && u[p].fi > v[q].se) q++;
            if (q < j) u[p].se = v[q].se - 1; else u[p].se = n;
        }
        int r = 1;
        for (int j = 1; j < sz (u); j++)
            if (u[r - 1].se >= u[j].fi)
                u[r - 1].se = max (u[r - 1].se, u[j].se);
            else
                u[r++] = u[j];  
        u.resize (r);
        w = u;
/*      printf ("%d:\n", v[i].fi);
        for (int j = 0; j < r; j++) printf ("%d %d | ", w[j].fi, w[j].se);
        printf ("\n");*/
        i = j;
    }
    if (v[m - 1].fi < n) {
        w[0].se = n;
        w.resize (1);
    }
    if (w[sz (w) - 1].se < n) printf ("-1\n"); else printf ("%d\n", 2 * n - 2);
    return 0;
}