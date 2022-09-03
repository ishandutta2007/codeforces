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

int n;
int m;
int was[2][2001][2001][2];
ll res[2][2001][2001][2];
vector<pair<ll, int> > u[2];
vii v[2000];
ll d[2000];
int mark[2000];
ll g[2][2000];
int p[2000];
int s[2];

ll go (int t, int ai, int bi, ll al, ll bl, int now) {
    if (ai == sz (u[t])) re 0;
    if (was[t][ai][bi][now]) re res[t][ai][bi][now];
    was[t][ai][bi][now] = 1;
    ll tmp = 0;
    int i = ai, ok = now;
    while (i < sz (u[t]) && u[t][i].fi == u[t][ai].fi) {
        int x = u[t][i].se;
        if (g[1 - t][x] > bl) {
            tmp += p[x];
            ok = 1;
        }
        i++;
    }
    ll cur = tmp + go (t, i, bi, u[t][ai].fi, bl, ok);
    if (ok) cur = max (cur, tmp - go (1 - t, bi, i, bl, u[t][ai].fi, 0));
//  printf ("%d %I64d %I64d %d = %I64d\n", t, al, bl, now, cur);
    re res[t][ai][bi][now] = cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    scanf ("%d%d", &s[0], &s[1]); s[0]--; s[1]--;
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            d[i] = 1e18;
            mark[i] = 0;
        }
        d[s[t]] = 0;
        mark[s[t]] = 1;
        for (int i = 0; i < n; i++) {
            int k = -1;
            for (int j = 0; j < n; j++)
                if (mark[j] == 1 && (k == -1 || d[k] > d[j]))
                    k = j;
            if (k == -1) break;
            mark[k] = 2;
            for (int j = 0; j < sz (v[k]); j++) {
                int y = v[k][j].fi;
                int z = v[k][j].se;
                ll nd = d[k] + z;
                if (d[y] > nd) {
                    d[y] = nd;
                    mark[y] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            g[t][i] = d[i];
            u[t].pb (mp (d[i], i));
//          printf ("%d - %d = %I64d\n", t, i, d[i]);
        }
        sort (all (u[t]));
    }
    ll res = go (0, 0, 0, -1, -1, 0);
    if (res > 0) printf ("Break a heart\n"); else
    if (res < 0) printf ("Cry\n"); else printf ("Flowers\n");
    return 0;
}