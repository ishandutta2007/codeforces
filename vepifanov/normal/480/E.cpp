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

const int N = 2001;

int n;
int m;
int k;
int cur;
int g[N][N];
int u[N][N];
vii v[N];
string s[N];
int f[N][N];
set<ii> all[N];
int LEN[N];

int add (int i, int j) {
    int h = f[i][j];
    g[i][j] = sz (v[h]);
    v[h].pb (mp (i, j));
    re 0;
}

int del (int i, int j) {
    int h = f[i][j];
    int k = g[i][j];
    if (k != sz (v[h]) - 1) {
        int ii = v[h][sz (v[h]) - 1].fi;
        int jj = v[h][sz (v[h]) - 1].se;
        g[ii][jj] = k;
        v[h][k] = mp (ii, jj);
    }
    v[h].pop_back ();
    re 0;
}

int put (int i, int j, int c) {
//  printf ("%d %d %d = %d\n", i, j, c, f[i][j]);
    if (u[i][j] == c) re 0;
    u[i][j] = c;
    if (c == 0) {
        auto it = all[j].lower_bound (mp (i, 1e9));
        it--;
        ii x = *it;
//      printf ("kill %d %d = %d\n", x.fi, x.se, LEN[cur]);
        LEN[x.se - x.fi + 1]--;
        all[j].erase (it);
        if (x.fi < i) {
            all[j].insert (mp (x.fi, i - 1));
            LEN[i - x.fi]++;
        }
        if (x.se > i) {
            all[j].insert (mp (i + 1, x.se));
            LEN[x.se - i]++;
        }
    } else {
        ii x (i, i);
        if (i > 0 && u[i - 1][j]) {
            auto it = all[j].lower_bound (mp (i, 1e9));
            it--;
            ii y = *it;
            LEN[y.se - y.fi + 1]--;
            all[j].erase (it);
            x.fi = y.fi;
        }
        if (i + 1 < n && u[i + 1][j]) {
            auto it = all[j].lower_bound (mp (i, 1e9));
            ii y = *it;
            LEN[y.se - y.fi + 1]--;
            all[j].erase (it);
            x.se = y.se;
        }
//      printf ("%d %d\n", x.fi, x.se);
        LEN[x.se - x.fi + 1]++;
        all[j].insert (x);
    }
    re 0;
}

int get () {
    for (int i = n; i >= cur; i--)
        if (LEN[i])
            re i;
    re 0;
}

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--)
            if (s[i][j] == 'X')
                f[i][j] = 0;
            else
                f[i][j] = f[i][j + 1] + 1;
    cur = m + 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            add (i, j);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        s[a][b] = 'X';
        for (int j = b; j >= 0; j--) {
            int tmp = f[a][j];
            del (a, j);
            if (s[a][j] == 'X')
                f[a][j] = 0;
            else
                f[a][j] = f[a][j + 1] + 1;
            add (a, j);
            if (tmp >= cur && f[a][j] < cur) put (a, j, 0);
        }
        while (cur > 0 && get () < cur) {
            cur--;
            for (int j = 0; j < sz (v[cur]); j++)
                put (v[cur][j].fi, v[cur][j].se, 1);
        }   
        printf ("%d\n", cur);
    }
    return 0;
}