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
vii v[100000];
int f[200000];
int d[200000];
int u[200000];
int col[200000];
int tr[200000];
int o = 0;
int c[200000];

int go (int x, int p, int r, int l) {
    d[x] = l;
    if (r >= 0) {
        u[p] = o;
        o++;    
    }
    col[x] = r;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (z != p) 
            if (r == -1) {
                f[i] = o;
                go (y, z, i, l + 1);
            } else
                go (y, z, r, l + 1);    
    }
    re 0;
}

int get (int x) {
    int s = 0;
    while (x > 0) {
        s += tr[x];
        x = (x & (x + 1)) - 1;
    }
    re s;
}

int add (int x, int y) {
    x++;
    while (x <= n) {
        tr[x] += y;
        x |= x + 1;
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (mp (b, i));
        v[b].pb (mp (a, i));
        c[a]++;
        c[b]++;
    }   
    int r = 0;
    for (int i = 0; i < n; i++)
        if (c[i] > c[r])
            r = i;
    go (r, -1, -1, 0);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int t, x, y;
        scanf ("%d%d", &t, &x); x--;
        if (t == 1) {
            add (u[x], -1);
        } else
        if (t == 2) {
            add (u[x], 1);
        } else {
            scanf ("%d", &y); y--;
            if (x == y) printf ("0\n"); else
            if (col[x] == col[y]) {
                if (d[x] > d[y]) swap (x, y);
                int X = col[x];
                int tmp = get (f[X] + d[y]) - get (f[X] + d[x]);
                if (tmp == 0) tmp = d[y] - d[x]; else tmp = -1;
                printf ("%d\n", tmp);
            } else {
                int tmp = 0, X = col[x], Y = col[y];
                if (X != -1) tmp += get (f[X] + d[x]) - get (f[X]);
                if (Y != -1) tmp += get (f[Y] + d[y]) - get (f[Y]);
                if (tmp == 0) tmp = d[y] + d[x]; else tmp = -1;
                printf ("%d\n", tmp);
            }
        }
    }   
    return 0;
}