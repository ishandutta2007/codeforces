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

const int tt = 75;

int n;
int m;
int x[100];
int y[100];
int z[100];
vi v;
vi w[300];
int res[301][301][2];
int was[301][301][2];
map<int, int> num;
int f[300];

int calc () {
    vii v;
    for (int i = 0; i < n; i++)
        if (z[i]) {
            v.pb (mp (x[i], 1));
            v.pb (mp (x[i] + y[i], -1));
        } else {
            v.pb (mp (x[i] - y[i], 1));
            v.pb (mp (x[i], -1));
        }
    sort (all (v)); 
    int cur = 0, bal = 0;
    for (int i = 0; i + 1 < 2 * n; i++) {
        bal += v[i].se;
        if (bal) cur += v[i + 1].fi - v[i].fi;
    }
    re cur;
}

int go (int i, int j, int t) {
    if (j < i) {
        t = 0;
        j = i;
    }
    if (i == sz (v)) re 0;
    if (was[i][j][t]) re res[i][j][t];
    was[i][j][t] = 1;
    int cur = go (i + 1, j, t);
    if ((!t || i < j) && f[i] > j) cur = max (cur, go ((t ? j : i) + 1, f[i], 0) + (v[f[i]] - v[j]));
    for (int k = 0; k < sz (w[i]); k++)
        if (w[i][k] > j)
            cur = max (cur, go ((t ? j : i) + 1, w[i][k], 1) + (v[w[i][k]] - v[j]));
    re res[i][j][t] = cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        v.pb (x[i] - y[i]);
        v.pb (x[i]);
        v.pb (x[i] + y[i]);
    }
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    for (int i = 0; i < sz (v); i++) num[v[i]] = i;
    for (int i = 0; i < n; i++) {
        int a = num[x[i] - y[i]];
        int b = num[x[i]];
        int c = num[x[i] + y[i]];
        f[b] = c;
        w[a].pb (b);
    }
    printf ("%d\n", go (0, 0, 0));
    return 0;
}