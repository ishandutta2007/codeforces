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

ii res[300000];
ll d[300000];
int mark[300000];
vector<pair<int, ii> > v[300000];
set<pair<ll, int> > all;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, mp (c, i)));
        v[b].pb (mp (a, mp (c, i)));
    }
    int S;
    scanf ("%d", &S); S--;
    for (int i = 0; i < n; i++) {
        d[i] = 1e18;
        mark[i] = 0;
        res[i] = mp (2e9, 0);
    }
    res[S] = mp (0, 0);
    d[S] = 0;
    mark[S] = 1;
    all.insert (mp (0, S));
    while (!all.empty ()) {
        int x = all.begin ()->se;
        all.erase (all.begin ());
        for (int i = 0; i < sz (v[x]); i++) {
            int y = v[x][i].fi;
            int z = v[x][i].se.fi;
            if (d[y] > d[x] + z) {
                if (mark[y]) all.erase (mp (d[y], y));
                d[y] = d[x] + z;
                all.insert (mp (d[y], y));
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < sz (v[i]); j++)
            if (d[i] + v[i][j].se.fi == d[v[i][j].fi])
                res[v[i][j].fi] = min (res[v[i][j].fi], v[i][j].se);
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += res[i].fi;
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        if (i != S)
            printf ("%d ", res[i].se + 1);
    printf ("\n");
    return 0;
}