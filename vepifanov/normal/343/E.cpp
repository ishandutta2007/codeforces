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
int was[200];
int q[200];
int ec[2000];
ii v[200][200];
int l[200];
int ct;
int ef[2000];
int prev[200];
int preve[200];
int g[200][200];

int go (int s, int t) {
    ct++;
    int l = 0, r = 1;
    q[0] = s;
    was[s] = ct;
    while (l < r) {
        int x = q[l++];
        for (int i = 0; i < ::l[x]; i++) {
            int y = v[x][i].fi;
            int z = v[x][i].se;
            if (ef[z] > 0 && was[y] != ct) {
                was[y] = ct;
                prev[y] = x;
                preve[y] = z;
                q[r++] = y;
            }
        }
        if (was[t] == ct) re 1;
    }
    re 0;
}

int get (int a, int b) {
    if (a != b && g[a][b] == inf) {
        for (int i = 0; i < 2 * m; i++) ef[i] = ec[i];
        int cur = 0;
        while (go (a, b)) {
            int tmp = 100;
            int i = b;
            while (i != a) {
                int j = prev[i];
                int k = preve[i];
                tmp = min (tmp, ef[k]);
                i = j;
            }
            cur += tmp;
            i = b;
            while (i != a) {
                int j = prev[i];
                int k = preve[i];
                ef[k] -= tmp;
                ef[k ^ 1] += tmp;
                i = j;
            }
        }   
        g[a][b] = g[b][a] = cur;
    }
    re g[a][b];
}

pair<int, vi> calc (vi w) {
    if (sz (w) == 1) re mp (0, w);
    int cur = 1e9;
    for (int i = 1; i < sz (w); i++)
        cur = min (cur, get (w[0], w[i]));
    vi x, y;
    for (int i = 0; i < sz (w); i++)
        if (get (w[0], w[i]) > cur)
            x.pb (w[i]);
        else
            y.pb (w[i]);
    pair<int, vi> rx = calc (x);
    pair<int, vi> ry = calc (y);
    for (int i = 0; i < sz (ry.se); i++)
        rx.se.pb (ry.se[i]);
    re mp (rx.fi + ry.fi + cur, rx.se);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a][l[a]++] = mp (b, 2 * i);
        v[b][l[b]++] = mp (a, 2 * i + 1);
        ec[2 * i] = ec[2 * i + 1] = c;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = inf;
    vi w;
    for (int i = 0; i < n; i++) w.pb (i);
    pair<int, vi> res = calc (w);
    printf ("%d\n", res.fi);
    for (int i = 0; i < sz (res.se); i++)
        printf ("%d ",res.se[i] + 1);
    printf ("\n");
//  cerr << clock () << endl;
    return 0;
}