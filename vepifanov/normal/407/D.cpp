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

#define filename ""

const int N = 160000;
const int M = 400;

int n;
int m;
vii v[N];
int l[M][M];
int r[M][M];
int g[M][M];
int res[M];

int upd (int i1, int j1, int i2, int j2) {
    if (j1 <= j2) r[i1][j1] = min (r[i1][j1], j2);
    if (j1 >= j2) l[i1][j1] = max (l[i1][j1], j2);
    re 0;
}

int add (int x, int i, int j) {
    int ok = 1;
    for (int t = 0; t < sz (v[x]); t++) {
        upd (v[x][t].se, v[x][t].fi, i, j);
        if (v[x][t].fi == j) {
            ok = 0;
            v[x][t].se = i;
        }
    }   
    if (ok) v[x].pb (mp (j, i));    
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf ("%d", &g[i][j]);
            g[i][j]--;
            l[i][j] = -1;
            r[i][j] = m;
        }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            add (g[i][j], i, j);
            res[j] = m;
        }   
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (l[j][k] >= 0)
                    res[l[j][k]] = min (res[l[j][k]], k);
                if (r[j][k] < m)
                    res[k] = min (res[k], r[j][k]);
            }   
            for (int k = m - 2; k >= 0; k--) res[k] = min (res[k], res[k + 1]);
            for (int k = 0; k < m; k++) {
//              printf ("%d %d %d = %d\n", i, j, k, res[k]);
                ans = max (ans, (j - i + 1) * (res[k] - k));
            }   
        }
    }
    printf ("%d\n", ans);
    return 0;
}