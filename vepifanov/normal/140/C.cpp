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

vii w;
vi v[100000];
int ra[100000], rb[100000], rc[100000], y[100000];
set<ii> all;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        w.pb (mp (x, i));
        y[i] = x;
    }
    sort (all (w));
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && w[i - 1].fi != w[i].fi) r++;
        v[r].pb (w[i].se);
    }
    for (int i = 0; i <= r; i++)
        all.insert (mp (-sz (v[i]), i));
    int k = 0;
    while (sz (all) > 2) {
        int a = all.begin ()->se;
        all.erase (all.begin ());
        int b = all.begin ()->se;
        all.erase (all.begin ());
        int c = all.begin ()->se;
        all.erase (all.begin ());
        if (a < b) swap (a, b);
        if (b < c) swap (b, c);
        if (a < b) swap (a, b);
        ra[k] = v[a][sz (v[a]) - 1];
        rb[k] = v[b][sz (v[b]) - 1];
        rc[k++] = v[c][sz (v[c]) - 1];
        v[a].pop_back ();
        v[b].pop_back ();
        v[c].pop_back ();
        if (sz (v[a]) > 0) all.insert (mp (-sz (v[a]), a));
        if (sz (v[b]) > 0) all.insert (mp (-sz (v[b]), b));
        if (sz (v[c]) > 0) all.insert (mp (-sz (v[c]), c));
    }
    printf ("%d\n", k);
    for (int i = 0; i < k; i++) printf ("%d %d %d\n", y[ra[i]], y[rb[i]], y[rc[i]]);
    return 0;
}