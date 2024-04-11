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

const int MAX = 86400;

int n;
int m;

vii v;

int can[MAX + 1];
int res[4002][4002];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        v.pb (mp (a, b));
    }
    v.pb (mp (0, 0));
    sort (all (v));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            res[i][j] = 1e9;
    for (int i = 1; i <= MAX; i++) can[i] = -1;
    for (int j = 0; j <= m; j++) res[0][j] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
//          printf ("%d - %d %d - %d = %d\n", i, v[i].fi, v[i].se, j, res[i][j]);
            if (j > 0) {
                if (i == n || i < n && v[i].fi + res[i][j] <= v[i + 1].fi)
                    if (v[i].fi + res[i][j] <= MAX)
                        can[v[i].fi + res[i][j]] = max (can[v[i].fi + res[i][j]], j - 1);
            }
            if (i == n || i < n && v[i].fi + v[i].se + res[i][j] <= v[i + 1].fi)
                if (v[i].fi + v[i].se + res[i][j] <= MAX)
                    can[v[i].fi + v[i].se + res[i][j]] = max (can[v[i].fi + v[i].se + res[i][j]], j);
            if (i == n) continue;
            res[i + 1][j] = min (res[i + 1][j], max (0, res[i][j] + v[i].se - (v[i + 1].fi - v[i].fi)));
            if (j > 0) res[i + 1][j - 1] = min (res[i + 1][j - 1], max (0, res[i][j] - (v[i + 1].fi - v[i].fi)));
        }
    int ans = 0, k = 0;
    for (int i = 1; i <= MAX; i++) {
        while (k <= n && v[k].fi < i)
            k++;
        if (can[i] == -1) continue;
//      printf ("%d %d %d\n", i, can[i], k + can[i] > n ? MAX + 1 : v[k + can[i]].fi);
        if (k + can[i] <= n) ans = max (ans, v[k + can[i]].fi - i); else ans = max (ans, MAX + 1 - i);
    }
    printf ("%d\n", ans);
    return 0;
}