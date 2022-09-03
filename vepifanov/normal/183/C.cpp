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
#define next NEXT
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
int m, u;
int d[100000];
int was[100000];
int col[100000];
vii v[100000];
int ct;
int need;

int go (int x, int l) {
        was[x] = 1;
        d[x] = l;
        for (int i = 0; i < sz (v[x]); i++) {
                int y = v[x][i].fi;
                int z = v[x][i].se;
                if (was[y] == 0) go (y, l + z); else 
                if (was[y] == 1 && (d[x] - d[y] + z) != 0) need = abs (d[x] - d[y] + z);
        }
        was[x] = 2;
        re 0;
}

int go2 (int x, int l, int h) {
        was[x] = 1;
        col[x] = l;
        for (int i = 0; i < sz (v[x]); i++) {
                int y = v[x][i].fi;
                int z = v[x][i].se;
                if ((was[y] == 0 && !go2 (y, (l + z + h) % h, h)) || (was[y] == 1 && col[y] != (l + z + h) % h)) re 0;
        }
        re 1;
}

int check (int h) {
        memset (was, 0, sizeof (was));
        memset (col, 0, sizeof (col));
        for (int i = 0; i < n; i++)
                if (!was[i])
                        if (!go2 (i, 0, h))
                                re 0;
        re 1;
}

int main () {
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
                int a, b;
                scanf ("%d%d", &a, &b); a--; b--;
                v[a].pb (mp (b, 1));
                v[b].pb (mp (a, -1));
        }
        need = -1;
        for (int i = 0; i < n && need == -1; i++)
                if (!was[i])
                        go (i, 0);
        if (need == -1) printf ("%d\n", n); else {
                for (int i = n; i >= 1; i--)
                        if (need % i == 0)
                                if (check (i)) {
                                        printf ("%d\n", i);
                                        re 0;
                                }
        }
        return 0;
}