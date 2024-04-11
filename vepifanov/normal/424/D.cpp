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
#define j0 j57248
#define j1 j34283
#define j2 j543789
                         
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
int ans;
int i1, j1, i2, j2;
set<ii> all;
int g[300][300];
int a[300], b[300], c[300];
int tp, tu, td, t;

int upd (int i, int j, int k, int t) {
    set<ii>::iterator it = all.lower_bound (mp (t, 1e9));
    if (it != all.end ()) {
        if (abs (it->fi - t) < ans) {
            ans = abs (it->fi - t);
            i1 = i;
            i2 = j;
            j1 = it->se;
            j2 = k;
        }
    }
    if (it != all.begin ()) {
        it--;
        if (abs (it->fi - t) < ans) {
            ans = abs (it->fi - t);
            i1 = i;
            i2 = j;
            j1 = it->se;
            j2 = k;
        }
    }
    re 0;
}

int get (int a, int b) {
    if (a > b) re td;
    if (a < b) re tu;
    re tp;
}

int main () {
    scanf ("%d%d%d", &n, &m, &t);
    scanf ("%d%d%d", &tp, &tu, &td);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%d", &g[i][j]);
    ans = 2e9;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++)
            a[k] = b[k] = 0;
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < m; k++) {
                a[k] += get (g[j][k], g[j - 1][k]);
                b[k] += get (g[j - 1][k], g[j][k]);
            }
            if (j - i >= 2) {
                int cur = 0;
                all.clear ();
                for (int k = 0; k < m; k++) {
                    if (k > 0) cur += get (g[i][k - 1], g[i][k]) + get (g[j][k], g[j][k - 1]);
                    c[k] = cur;
                    if (k > 1) {
                        all.insert (mp (a[k - 2] - c[k - 2], k - 2));
                        upd (i, j, k, t - (b[k] + c[k]));
                    }
                }
            }
        }
    }
    printf ("%d %d %d %d\n", i1 + 1, j1 + 1, i2 + 1, j2 + 1);
    return 0;
}