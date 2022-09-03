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
vi w[100001], v[100000];
vii ww[100001];
int u[100001];
int l[100001];
int r[100001];
int anc[100001][20];
int d[100001];
int res[100001];
int ct;
int p[100001];
int f[100001];

int go (int x, int l, int p) {
    d[x] = l;
    w[l].pb (x);
    anc[x][0] = p;
    for (int i = 1; i < 20; i++)
        anc[x][i] = anc[anc[x][i - 1]][i - 1];
    u[x] = ct;
    ::l[x] = ct;
    ct++;
    for (int i = 0; i < sz (v[x]); i++)
        go (v[x][i], l + 1, x);
    r[x] = ct;
    re 0;
}

int get (int x, int d) {
    int j = 19;
    while (d > 0)
        if ((1 << j) <= d) {
            d -= 1 << j;
            x = anc[x][j];
        } else j--;
    re x;
}

int get (int x) {
    x = n - x;
    int s = 0;
    while (x > 0) {
        s += f[x];
        x = (x & (x + 1)) - 1;
    }
    re s;
}

int add (int x, int y) {
    x = n - x;
    while (x <= n) {
        f[x] += y;
        x |= x + 1;
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &p[i]); p[i]--;
        if (p[i] != -1) v[p[i]].pb (i);
    }   
    for (int i = 0; i < n; i++) 
        if (p[i] == -1)
            go (i, 0, i);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--;
        if (d[a] >= b)
            ww[d[a]].pb (mp (get (a, b), i));
    }
    memset (f, 0, sizeof (f));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < sz (w[i]); j++)
            add (u[w[i][j]], 1);
        for (int j = 0; j < sz (ww[i]); j++)
            res[ww[i][j].se] = get (l[ww[i][j].fi]) - get (r[ww[i][j].fi]) - 1;
        for (int j = 0; j < sz (w[i]); j++)
            add (u[w[i][j]], -1);
    }
    for (int i = 0; i < m; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}