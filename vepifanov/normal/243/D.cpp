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
int vx, vy;
int tree[(1 << 22) + 1];
int add[(1 << 22) + 1];
vector<pair<int, ii> > u;
vector<pair<ii, ii> > w;
int g[1000][1000];
int p[1000][1000];
int q[1000][1000];

int get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re 2e9;
    if (l >= lc && r <= rc) re max (tree[x], add[x]);
    int s = (l + r) / 2;
    re max (min (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc)), add[x]);
}

int upd (int x, int l, int r, int lc, int rc, int z) {
    if (r < lc || l > rc) re max (tree[x], add[x]);
    if (l >= lc && r <= rc) {
        add[x] = max (add[x], z);
        re max (tree[x], add[x]);
    }
    int s = (l + r) / 2;
    tree[x] = min (upd (x * 2 + 1, l, s, lc, rc, z), upd (x * 2 + 2, s + 1, r, lc, rc, z));
    re max (tree[x], add[x]);
}

int main () {
    scanf ("%d%d%d", &n, &vx, &vy);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &g[i][j]);
    if (vy < 0) {
        vy = -vy;
        for (int i = 0; i < n; i++)
            for (int j = 0; 2 * j < n; j++)
                swap (g[i][j], g[i][n - j - 1]);
    }
    if (vx < 0) {
        vx = -vx;
        for (int i = 0; 2 * i < n; i++)
            for (int j = 0; j < n; j++)
                swap (g[i][j], g[n - i - 1][j]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a = vx * i + vy * j;
            int b = -vy * (i + 1) + vx * j;
            int c = -vy * i + vx * (j + 1) - 1;
            u.pb (mp (a, mp (i, j)));
            w.pb (mp (mp (b, 0), mp (i, j)));
            w.pb (mp (mp (c, 1), mp (i, j)));
        }
    sort (all (u));
    sort (all (w));
    int r = 0;
    for (int i = 0; i < sz (w); i++) {
        if (i == 0 || w[i - 1].fi.fi != w[i].fi.fi) r++;
        if (w[i].fi.se == 0) p[w[i].se.fi][w[i].se.se] = r - 1; else q[w[i].se.fi][w[i].se.se] = r - 1;
    }
    memset (tree, 0, sizeof (tree));
    memset (add, 0, sizeof (add));
    ll ans = 0;
    for (int k = 0; k < sz (u); k++) {
        int i = u[k].se.fi;
        int j = u[k].se.se;
        int a = g[i][j];
        int b = p[i][j];
        int c = q[i][j];
        int d = get (0, 0, r - 1, b, c);
        if (d < a) {
            ans += a - d;
            upd (0, 0, r - 1, b, c, a);
        }
    }
    cout << ans << endl;
    return 0;
}