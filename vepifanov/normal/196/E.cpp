#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
        re x > 0 ? x : -x;
}


int n;
int m;
int mark[100000];
ll d[100000];
set<pair<ll, int> > all;
int w[100000];
vii v[100000];
vector<pair<ll, ii> > u;
int p[100000];

int gp (int x) {
        if (p[x] != x) p[x] = gp (p[x]);
        re p[x];
}

int go () {
        memset (mark, 0, sizeof (mark));
        for (int i = 0; i < n; i++) d[i] = 1e18;
        for (int i = 0; i < n; i++)
                if (w[i]) {
                        d[i] = 0;
                        mark[i] = 1;
                        p[i] = i;
                        all.insert (mp (0, i));
                }
        while (!all.empty ()) {
                int x = all.begin ()->se;
                all.erase (all.begin ());
                for (int i = 0; i < sz (v[x]); i++) {
                        int y = v[x][i].fi;
                        ll z = d[x] + v[x][i].se;
                        if (z < d[y]) {
                                if (mark[y]) all.erase (mp (d[y], y));
                                d[y] = z;
                                mark[y] = 1;
                                p[y] = p[x];
                                all.insert (mp (d[y], y));
                        }
                }
        }
        re 0;
}

int main() {
       scanf ("%d%d", &n, &m);
       for (int i = 0; i < m; i++) {
                int a, b, c;
                scanf ("%d%d%d", &a, &b, &c); a--; b--;
                v[a].pb (mp (b, c));
                v[b].pb (mp (a, c));
       }
       scanf ("%d", &m);
       for (int i = 0; i < m; i++) {
                int x;
                scanf ("%d", &x); x--;
                w[x] = 1;
       }
       go ();
       for (int i = 0; i < n; i++)
                for (int j = 0; j < sz (v[i]); j++)
                        u.pb (mp (d[i] + v[i][j].se + d[v[i][j].fi], mp (p[i], p[v[i][j].fi])));
       for (int i = 0; i < n; i++) p[i] = i;
       sort (all (u));
       ll ans = d[0];
       for (int i = 0; i < sz (u); i++) {
                int a = gp (u[i].se.fi);
                int b = gp (u[i].se.se);
                if (a != b) {
                        ans += u[i].fi;
                        if (rand () & 1) p[a] = b; else p[b] = a;
                }
       }
       cout << ans << endl;
       return 0;
}