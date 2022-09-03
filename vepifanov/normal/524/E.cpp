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
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

const int inf = 1e9;

const int N = 1 << 18;

int n;
int m;
int k, q;
int x[N];
int y[N];
int x1[N];
int y1[N];
int x2[N];
int y2[N];
int tree[2 * N + 10];
vector<pair<ii, ii> > v[N];
vi w[N];
int res[N];

int build (int x, int l, int r) {
    tree[x] = inf;
    if (l == r) re 0;
    int s = (l + r) / 2;
    build (x * 2 + 1, l, s);
    build (x * 2 + 2, s + 1, r);
    re 0;
}

int add (int x, int l, int r, int y, int z) {
    if (r < y || l > y) re tree[x];
    if (l == r) re tree[x] = z;
    int s = (l + r) / 2;
    re tree[x] = max (add (x * 2 + 1, l, s, y, z), add (x * 2 + 2, s + 1, r, y, z));
}

int get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re -1;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re max (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int solve () {
    for (int i = 0; i < n; i++) {
        v[i].clear ();
        w[i].clear ();
    }
    build (0, 0, m - 1);
    for (int i = 0; i < k; i++)
        w[x[i]].pb (y[i]);
    for (int i = 0; i < q; i++)
        v[x1[i]].pb (mp (mp (y1[i], y2[i]), mp (x2[i], i)));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < sz (w[i]); j++) {
//          printf ("add %d = %d\n", w[i][j] + 1, i + 1);
            add (0, 0, m - 1, w[i][j], i);
        }   
        for (int j = 0; j < sz (v[i]); j++) {   
            int tmp = get (0, 0, m - 1, v[i][j].fi.fi, v[i][j].fi.se);
//          printf ("get %d %d = %d ? %d\n", v[i][j].fi.fi + 1, v[i][j].fi.se + 1, tmp + 1, v[i][j].se.fi + 1); 
            if (tmp <= v[i][j].se.fi)
                res[v[i][j].se.se] = 1;
        }
    }
    re 0;
}

int main () {
    scanf ("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        x[i]--;
        y[i]--; 
    }
    for (int i = 0; i < q; i++) {
        scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        x1[i]--;
        x2[i]--;
        y1[i]--;
        y2[i]--;
    }
    solve ();
    swap (n, m);
    for (int i = 0; i < k; i++) swap (x[i], y[i]);
    for (int i = 0; i < q; i++) {
        swap (x1[i], y1[i]);
        swap (x2[i], y2[i]);
    }
    solve ();
    for (int i = 0; i < q; i++)
        printf ("%s\n", res[i] ? "YES" : "NO");
    return 0;
}