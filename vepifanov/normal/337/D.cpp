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
int d;
ii d1[100000];
ii d2[100000];
vi v[100000];
int ans;
int bad[100000];

int go (int x, int p) {
    ii a1 = mp (-1e9, 0), a2 = mp (-1e9, 0);
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        int tmp = go (y, x) + 1;
        if (a1.fi < tmp) {
            a2 = a1;
            a1 = mp (tmp, y);
        } else
        if (a2.fi < tmp)
            a2 = mp (tmp, y);
    }
    if (bad[x]) {
        if (a1.fi < 0) {
            a2 = a1;
            a1 = mp (0, x);
        } else
        if (a2.fi < 0)
            a2 = mp (0, x);
    }
    d1[x] = a1;
    d2[x] = a2;
    re a1.fi;
}

int go2 (int x, int p, int up) {
//  printf ("%d %d %d = %d %d | %d %d\n", x + 1, p + 1, up, d1[x].fi, d1[x].se + 1, d2[x].fi, d2[x].se + 1);
    if (d1[x].fi <= d && up <= d) ans++;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        go2 (y, x, max (up, d1[x].se == y ? d2[x].fi : d1[x].fi) + 1);
    }
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        int x;
        scanf ("%d", &x); x--;
        bad[x] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    go (0, -1);
    ans = 0;
    go2 (0, -1, -1e9);
    printf ("%d\n", ans);
    return 0;
}