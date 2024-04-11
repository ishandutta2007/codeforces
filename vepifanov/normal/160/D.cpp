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

vector<pair<ii, ii> > w;
int ct;
vii v[100000];
int f[100000], d[100000], was[100000], use[100000], p[100000];
int res[100000];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int go (int x, int p, int l) {
    use[x] = ct;
    d[x] = f[x] = l;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (z == p) continue;
        if (use[y] != ct) {
            f[x] = min (f[x], go (y, z, l + 1));
            if (f[y] > l) res[z] = 2;
        } else {
            f[x] = min (f[x], d[y]);
        }   
    }
    re f[x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        w.pb (mp (mp (c, i), mp (a, b)));
    }
    sort (all (w));
    for (int i = 0; i < n; i++) p[i] = i;
    int i = 0;
    while (i < m) {
        int j = i;
        ct++;
        vi q;
        while (j < m && w[j].fi.fi == w[i].fi.fi) {
            int a = gp (w[j].se.fi);
            int b = gp (w[j].se.se);
            if (a != b) {
                res[w[j].fi.se] = 1;
                if (a > b) swap (a, b);
                if (was[a] != ct) { v[a].clear (); was[a] = ct; q.pb (a); }
                if (was[b] != ct) { v[b].clear (); was[b] = ct; q.pb (b); }
                v[a].pb (mp (b, w[j].fi.se));
                v[b].pb (mp (a, w[j].fi.se));
            }   
            j++;
        }
        for (int k = 0; k < sz (q); k++)
            if (use[q[k]] != ct)
                go (q[k], -1, 0);
        for (int k = i; k < j; k++) {
            int a = gp (w[k].se.fi);
            int b = gp (w[k].se.se);
            if (a != b) 
                if (rand () & 1) p[a] = b; else p[b] = a;
        }
        i = j;
    }
    for (int i = 0; i < m; i++)
        if (res[i] == 0)
            printf ("none\n");
        else
        if (res[i] == 1)    
            printf ("at least one\n");
        else
            printf ("any\n");   
    return 0;
}