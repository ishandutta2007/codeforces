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
int g[1000][1000];
vii q;
vector<pair<int, ii> > res;
int r[1000];
int c[1000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        g[a][b] = 1;
        r[a]++;
        c[b]++;
    }
    for (int t = 0; t + 1 < n; t++) {
        int a, b;
        for (int i = 0; i < n - t; i++) {
            if (c[i] == 0) a = i;
            if (r[i] > 0) b = i;
        }
        if (b != n - t - 1) {
            res.pb (mp (1, mp (b + 1, n - t)));
            for (int i = 0; i < n; i++) swap (g[b][i], g[n - t - 1][i]);
            swap (r[b], r[n - t - 1]);
        }
        if (a != n - t - 1) {
            res.pb (mp (2, mp (a + 1, n - t)));
            for (int i = 0; i < n; i++) swap (g[i][a], g[i][n - t - 1]);
            swap (c[a], c[n - t - 1]);
        }   
        for (int i = 0; i < n; i++) c[i] -= g[n - t - 1][i];
    }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d %d %d\n", res[i].fi, res[i].se.fi, res[i].se.se);
    return 0;
}