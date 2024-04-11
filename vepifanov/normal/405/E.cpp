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
vi v[100000];
int was[100000];
vector<pair<int, ii> > res;

int go (int x, int p) {
    vi u;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i], z;
        if (y == p) continue;
        if (!was[y]) {
            z = go (y, x);
            if (z != -1) res.pb (mp (z, mp (y, x))); else u.pb (y);
        } else
        if (was[y] == 2) u.pb (y);
    }
    while (sz (u) > 1) {
        int a = u.back ();
        u.pop_back ();
        int b = u.back ();
        u.pop_back ();
        res.pb (mp (a, mp (x, b)));
    }
    was[x] = 2;
    if (u.empty ()) re -1;
    re u[0];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++)
        if (!was[i] && go (i, i) != -1) {
            printf ("No solution\n");
            re 0;
        }
    for (int i = 0; i < m / 2; i++)
        printf ("%d %d %d\n", res[i].fi + 1, res[i].se.fi + 1, res[i].se.se + 1);
    return 0;
}