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

const int N = 200*1000;

int n;
int m;
int k;
int BAD = 0;
vii v[N];
vi u[N];
vi q;
int cup[N];
int cdown[N];
int was[N];
int cmp[N];
int col[N];
int bad[2 * N];
int ea[N];
int eb[N];
int anc[N][20];
int tin[N];
int tout[N];
int ct;

int go (int x) {
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (was[y]) continue;
        go (y);
        bad[z] = 1;
    }
    q.pb (x);
    re 0;
}

int go2 (int x, int c) {
    col[x] = c;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (was[y] || bad[z]) continue;
        go2 (y, c);
    }
    re 0;
}

int go3 (int x, int p, int c) {
    tin[x] = ct++;
    cmp[x] = c;
    was[x] = 1;
    anc[x][0] = p;
    for (int i = 0; i < 19; i++)
        anc[x][i + 1] = anc[anc[x][i]][i];
    for (int i = 0; i < sz (u[x]); i++) {
        int y = u[x][i];
        if (was[y]) continue;
        go3 (y, x, c);
    }
    tout[x] = ct++;
    re 0;
}

int isanc (int a, int b) { re int (tin[a] <= tin[b] && tout[a] >= tout[b]); }

int lca (int a, int b) {
    int j = 19;
    while (!isanc (a, b))
        if (j == 0 || !isanc (anc[a][j], b))
            a = anc[a][j];
        else    
            j--;
    re a;
}

ii go4 (int x) {
    was[x] = 1;
    ii cur (0, 0);
    for (int i = 0; i < sz (u[x]); i++) {
        int y = u[x][i];
        if (was[y]) continue;
        ii tmp = go4 (y);
        cur.fi += tmp.fi;
        cur.se += tmp.se;
    }
    cur.fi += cup[x];
    cur.se += cdown[x];
    if (cur.fi && cur.se) BAD = 1;
    re cur;
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        ea[i] = a;
        eb[i] = b;
        v[a].pb (mp (b, 2 * i));
        v[b].pb (mp (a, 2 * i + 1));
    }
    for (int i = 0; i < n; i++)
        if (!was[i])
            go (i);
    memset (was, 0, sizeof (was));
    reverse (all (q));
    int o = 0;
    for (int i = 0; i < n; i++)
        if (!was[q[i]]) {
            go2 (q[i], o);
            o++;
        }   
    for (int i = 0; i < m; i++) {
        int a = col[ea[i]];
        int b = col[eb[i]];
        u[a].pb (b);
        u[b].pb (a);
    }
    memset (was, 0, sizeof (was));
    int r = 0;
    for (int i = 0; i < o; i++)
        if (!was[i]) {
            go3 (i, i, r);
            r++;
        }
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        a = col[a];
        b = col[b];
        if (cmp[a] != cmp[b]) {
            printf ("No\n");
            re 0;
        }
        if (a != b) {
            int c = lca (a, b);
            cup[a]++;
            cup[c]--;
            cdown[b]++;
            cdown[c]--;
        }   
    }
    memset (was, 0, sizeof (was));
    for (int i = 0; i < o; i++)
        if (!was[i])
            go4 (i);
    printf ("%s\n", BAD ? "No" : "Yes");
    return 0;
}