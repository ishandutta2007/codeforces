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
#define fiint(x,y) memset(x,y,sizeof(x))
                         
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
vi w[100000];
vii v[100000];
int mark[100000];
int d[100000];
set<ii> all;

int get (int x, int t) {
    if (w[x].empty () || w[x][sz (w[x]) - 1] < t) re t;
    int l = -1, r = sz (w[x]) - 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (w[x][s] >= t) r = s; else l = s;
    }
    if (w[x][r] != t) re t;
    while (r + 1 < sz (w[x]) && w[x][r + 1] == w[x][r] + 1) r++;
    re w[x][r] + 1;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    for (int i = 0; i < n; i++) {
        int k;
        scanf ("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf ("%d", &x);
            w[i].pb (x);
        }
        sort (all (w[i]));
    }
    for (int i = 0; i < n; i++) d[i] = 2e9;
    d[0] = 0;
    mark[0] = 1;
    memset (mark, 0, sizeof (mark));
    all.insert (mp (0, 0));
    while (!all.empty ()) {
        int x = all.begin ()->se;
        if (x == n - 1) break;
        all.erase (all.begin ());
        int y = get (x, d[x]);
        if (y > d[x]) {
            d[x] = y;
            all.insert (mp (y, x));
            continue;
        }
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int z = d[x] + v[x][i].se;
            if (d[y] > z) {
                if (mark[y]) all.erase (mp (d[y], y));
                d[y] = z;
                mark[y] = 1;
                all.insert (mp (d[y], y));
            }
        }
    }
    if (!mark[n - 1]) printf ("-1\n"); else printf ("%d\n", d[n - 1]);
    return 0;
}