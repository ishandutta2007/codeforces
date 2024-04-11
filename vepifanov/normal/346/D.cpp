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

const int inf = 1e9;

int n;
int m;

int x[1000000];
int y[1000000];
int c[1000000];
int was[1000000];
vi v[1000000];
vi rv[1000000];
set<ii> all;
int s, t;

int get (int a) {
    if (c[a]) re y[a] + 1;
    re min (x[a], y[a] + 1);
}

int relax (int a, int z) {
    if (was[a]) re 1;
    all.erase (mp (get (a), a));
    c[a]--;
    y[a] = min (y[a], z);
    x[a] = max (x[a], z);
    all.insert (mp (get (a), a));
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        rv[b].pb (a);
        c[a]++;
    }
    scanf ("%d%d", &s, &t); s--; t--;
    for (int i = 0; i < n; i++) {
        x[i] = -inf;
        if (c[i] == 0) x[i] = inf;
        y[i] = inf;
        if (i != t)
            all.insert (mp (get (i), i));
    }
    all.insert (mp (0, t));
    while (!all.empty ()) {
        int a = all.begin ()->se;
        int z = all.begin ()->fi;
        was[a] = 1;
        all.erase (all.begin ());
        for (int i = 0; i < sz (rv[a]); i++) {
            int b = rv[a][i];
            relax (b, z);
        }
    }
    if (get (s) >= inf) printf ("-1\n"); else printf ("%d\n", get (s));
    return 0;
}