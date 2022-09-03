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

set<ii> all;

ii q[200000];
vii res;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x > n - 1) {
            printf ("No\n");
            re 0;
        }
        if (x > 0) all.insert (mp (-x, i));
    }
    while (!all.empty ()) {
        ii a = *all.begin ();
        all.erase (all.begin ());
        int r = 0;
        while (a.fi) {
            if (all.empty ()) {
                printf ("No\n");
                re 0;
            }
            ii b = *all.begin ();
            all.erase (all.begin ());
            res.pb (mp (a.se + 1, b.se + 1));
            b.fi++;
            a.fi++;
            if (b.fi < 0) q[r++] = b;
        }
        for (int i = 0; i < r; i++) all.insert (q[i]);
    }
    printf ("Yes\n%d\n", m / 2);
    for (int i = 0; i < m / 2; i++) printf ("%d %d\n", res[i].fi, res[i].se);
    return 0;
}