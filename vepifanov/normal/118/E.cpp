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
int m, bad;
int was[100000], f[100000], d[100000];
vi v[100000];
vii q;

int go (int x, int p, int l) {
    was[x] = 1;
    d[x] = l;
    f[x] = l;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p || was[y] == 2) continue;
        q.pb (mp (x + 1, y + 1));
        if (was[y] == 1) f[x] = min (f[x], d[y]); else { 
            f[x] = min (f[x], go (y, x, l + 1)); 
            if (f[y] > l) bad = 1;
        }
    }
    was[x] = 2;
    re f[x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    bad = 0;
    go (0, 0, 0);
    if (bad) printf ("0\n"); else for (int i = 0; i < m; i++) printf ("%d %d\n", q[i].fi, q[i].se);
    return 0;
}